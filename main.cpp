#include <iostream>
#include "simulator.h"
#include "fcfs_scheduler.h"
#include "sjf_scheduler.h"
#include "srtf_scheduler.h"
#include "rr_scheduler.h"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Usage: ./scheduler <input-file>" << std::endl;
		exit(0);
	}

	std::string file_name(argv[1]);
	std::vector<Scheduler *> schedulers = {new FCFSScheduler, new SJFScheduler, new SRTFScheduler, new RRScheduler};
	Simulator simulator(schedulers);	
	simulator.run(file_name);
	return 0;
}
