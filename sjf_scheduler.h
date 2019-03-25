#include "scheduler.h"

class SJFScheduler : public Scheduler {
	public:
		SJFScheduler() : Scheduler("SJF") {};

	private:
		void schedule(vector<Task> tasks, int quant_len);
};	

