#include "scheduler.h"

class RRScheduler : public Scheduler {
	public:
		RRScheduler() : Scheduler("RR") {};

	private:
		void schedule(vector<Task> tasks, int quant_len);
};	
