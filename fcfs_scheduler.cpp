#include "fcfs_scheduler.h"
#include <algorithm>

void FCFSScheduler::schedule(vector<Task> tasks, int quant_len){
	if (tasks.empty()){
		return;
	}

	std::sort(tasks.begin(), tasks.end(),
				[](Task &a, Task &b)->bool{return a.arrival_time < b.arrival_time || (a.arrival_time == b.arrival_time && a.id < b.id);});

	int curr = tasks[0].arrival_time;
	for (Task task : tasks) {
		curr = std::max(curr, task.arrival_time);
		int wait_time = curr - task.arrival_time;
		curr += task.burst_length;
		int turnaround_time = curr - task.arrival_time;
		Record r(task.id, curr, wait_time, turnaround_time);
		log[task.id] = r;
	}
}
