#include "simulator.h"
#include <fstream>
#include <iostream>

std::vector<Task> Simulator::get_workload(std::string file_name, int &quant_length){
	std::ifstream input_file(file_name);

	if (input_file.fail()){
		std::cout << "ERROR: Could not open file " + file_name + "." << std::endl;
	}

	input_file >> quant_length;
		
	std::vector<Task> tasks;	
	int arrival_t;
	int id;
	int burst_l;
	input_file >> arrival_t;
	while (!input_file.eof()){
		input_file >> id;
		input_file >> burst_l;
		Task t(id, arrival_t, burst_l);
		tasks.push_back(t);
		input_file >> arrival_t;
	}
	input_file.close(); 
	return tasks;
}

void Simulator::run(string file_name){
	int quant_len;
	std::vector<Task> tasks = get_workload(file_name, quant_len);
	for (Scheduler *scheduler : schedulers){
		scheduler->simulate(file_name, tasks, quant_len);
	}
}
