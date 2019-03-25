#include "scheduler.h"

class SRTFScheduler : public Scheduler {
	public:
		SRTFScheduler() : Scheduler("SRTF") {};

	private:
		void schedule(vector<Task> tasks, int quant_len);
};	

