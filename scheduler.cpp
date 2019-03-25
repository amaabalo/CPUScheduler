#include "scheduler.h"
#include <fstream>
#include <iostream>

void Scheduler::simulate(std::string file_name, std::vector<Task> tasks, int quant_len) {
	schedule(tasks, quant_len);
	write_stats(file_name);	
}

void Scheduler::write_stats(std::string file_name){
	int last_slash = file_name.rfind('/');
	file_name = file_name.substr(last_slash + 1);
	std::ofstream outfile(file_name + "_" + name);
	if (outfile.fail()){
		cout << "WARNING: Failed to write scheduling records to file." << endl;
		return;
	}

	for (auto it = log.begin(); it != log.end(); it++) {
		Record r = it->second;
		outfile << it->first << " " << r.finish_time << " " << r.wait_time << " " << r.turnaround_time << endl;
	}
	
	outfile.close();

}
