#include "srtf_scheduler.h"
#include <algorithm>
#include <queue>

void SRTFScheduler::schedule(vector<Task> tasks, int quant_len){
	if (tasks.empty()){
		return;
	}

	std::priority_queue<Task, vector<Task>, comparison> task_queue;
	int curr = 0;
	int i = 0;
	Task task; // the current task
	bool task_in_hand = false; // true when the current task preempted a previous one
	do {
		if (!task_in_hand) {
			if (task_queue.empty() && i < tasks.size()) {
				do{
					tasks[i].enqueue_time = tasks[i].arrival_time;
					task_queue.push(tasks[i]);
				} while (++i < tasks.size() && tasks[i].arrival_time == tasks[i - 1].arrival_time);
			}
			task = task_queue.top();
			task_queue.pop();
			curr = std::max(curr, task.arrival_time);
			int wait_time = curr - task.enqueue_time;
			log[task.id].wait_time += wait_time;
		} else {
			task_in_hand = false;
			log[task.id].wait_time = 0;
		}
		if (!log.count(task.id)){
			log[task.id].id = task.id;
		}
		int potential_finish_time = curr + task.burst_length;
		while (i < tasks.size() && tasks[i].arrival_time <= potential_finish_time){
			int potential_remaining_time = potential_finish_time - tasks[i].arrival_time;
			if (tasks[i].burst_length < potential_remaining_time){
				task_in_hand = true;
				break;
			}
			tasks[i].enqueue_time = tasks[i].arrival_time;
			task_queue.push(tasks[i]);
			i++;
		}

		if (!task_in_hand){ // there was no interruption
			curr = potential_finish_time;
			log[task.id].finish_time = potential_finish_time;
			log[task.id].turnaround_time = potential_finish_time - task.arrival_time;
		} else {
			curr = tasks[i].arrival_time;
			task.burst_length = potential_finish_time - curr;
			task.enqueue_time = curr;
			task_queue.push(task);

			int tih_index = i;
			i++;
			while (i < tasks.size() && tasks[i].arrival_time == curr){
				if (tasks[i].burst_length < tasks[tih_index].burst_length || (tasks[i].burst_length == tasks[tih_index].burst_length && tasks[i].id < tasks[tih_index].id)){
					tasks[tih_index].enqueue_time = curr;
					task_queue.push(tasks[tih_index]);
					tih_index = i;
				} else {
					tasks[i].enqueue_time = curr;
					task_queue.push(tasks[i]);
				}
				i++;
			}
			task = tasks[tih_index];
		}
	} while (i < tasks.size() || task_in_hand || !task_queue.empty());
}
