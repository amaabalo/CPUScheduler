#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main (int argc, char **argv) {

	if (argc != 4){
		cout << "Usage: ./test_gen <quantum_length> <num_lines> <file_name>" << endl;
		exit(0);
	}
	
	int quantum_length;
	int num_lines;

	quantum_length = atoi(argv[1]);
	num_lines = atoi(argv[2]);
	string filename(argv[3]);
	std::ofstream out(filename);

	if (out.fail()){
		std::cout << "Could not open output file for writing" << std::endl;
		exit(1);
	}

	int max_burst_length = quantum_length * 100;
	int max_interval = (rand() % 30) + 1;
	int arrival_prev;	
	int arrival_time;
	out << quantum_length << std::endl;

	for (int i = 1; i <= num_lines; i++){
		if (i == 1){
			arrival_time = rand() % 100000;
		} else {
			arrival_time = arrival_prev + (rand() % max_interval);
		}
		int burst_length = (rand() % max_interval) + 1;
		out << arrival_time << " " << i << " " << burst_length << std::endl;	
		arrival_prev = arrival_time;
	}

	out.close();
	return 0;
}
