#include "scheduler.h"
using namespace std;

class Simulator{
	private:
		std::vector<Scheduler *> schedulers;
		std::vector<Task> get_workload(std::string file_name, int &quant_length);
	public:
		Simulator(std::vector<Scheduler *> schedulers_) : schedulers(schedulers_){};
		void run(string file_name);
};

