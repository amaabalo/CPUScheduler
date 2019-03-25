#include "scheduler.h"

class FCFSScheduler : public Scheduler {
	public:
		FCFSScheduler() : Scheduler("FCFS") {};

	private:
		void schedule(vector<Task> tasks, int quant_len);
};	
