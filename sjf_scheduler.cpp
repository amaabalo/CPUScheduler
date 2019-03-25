#include "sjf_scheduler.h"
#include <algorithm>
#include <queue>


void SJFScheduler::schedule(vector<Task> tasks, int quant_len){
	if (tasks.empty()){
		return;
	}

	std::priority_queue<Task, vector<Task>, comparison> task_queue;
	int curr = 0;
	int i = 0;
	do {
		if (task_queue.empty() && i < tasks.size()) {
			do{
				task_queue.push(tasks[i]);
			} while (++i < tasks.size() && tasks[i].arrival_time == tasks[i - 1].arrival_time);
		}
		
		Task task = task_queue.top();
		task_queue.pop();
		curr = std::max(curr, task.arrival_time);
		int wait_time = curr - task.arrival_time;
		curr += task.burst_length;
		int turnaround_time = curr - task.arrival_time;
		Record r(task.id, curr, wait_time, turnaround_time);
		log[task.id] = r;
		while (i < tasks.size() && tasks[i].arrival_time <= curr){
			task_queue.push(tasks[i]);
			i++;
		}

	} while (log.size() < tasks.size());
}
