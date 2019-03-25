#include "rr_scheduler.h"
#include <algorithm>
#include <queue>

void RRScheduler::schedule(vector<Task> tasks, int quant_len){
	if (tasks.empty()){
		return;
	}

	std::queue<Task> task_queue;
	int curr = 0;
	int i = 0;
	Task task; // the current task
	while (i < tasks.size() || !task_queue.empty()){
		if (i < tasks.size() && !task_queue.empty()){ // there are incoming tasks and queued tasks
			if (curr == tasks[i].arrival_time && tasks[i].id < task_queue.front().id){
				task = tasks[i];
				log[task.id].wait_time = 0;
				i++;
			} else {
				task = task_queue.front();
				task_queue.pop();
				log[task.id].wait_time += curr - task.enqueue_time;
			}
		} else if (task_queue.empty()){ // there are incoming tasks but no queued tasks
			task = tasks[i];
			log[task.id].wait_time = 0;
			curr = task.arrival_time;
			i++;
		} else { // there are only queued tasks
			task = task_queue.front();
			task_queue.pop();
			log[task.id].wait_time += curr - task.enqueue_time;
		}

		if (task.burst_length <= quant_len){
			curr += task.burst_length;
			log[task.id].finish_time = curr;
			log[task.id].turnaround_time = curr - task.arrival_time; 
		} else {
			curr += quant_len;
		}
		
		while (i < tasks.size() && tasks[i].arrival_time < curr){
			tasks[i].enqueue_time = tasks[i].arrival_time;
			task_queue.push(tasks[i]);
			i++;
		}

		if (task.burst_length > quant_len){
			task.enqueue_time = curr;
			task.burst_length -= quant_len;
			task_queue.push(task);
		}
	}
}
