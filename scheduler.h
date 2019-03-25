#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Task {
	int id;
	int arrival_time;
	int burst_length;
	int enqueue_time; // The most recent time the task was enqueued
	Task() : id(0), arrival_time(0), burst_length(0), enqueue_time(0){};
	Task (int id_, int arrival_t, int burst_l) : id(id_), arrival_time(arrival_t), burst_length(burst_l) {};
};

class comparison{
    public:
        bool operator() (const Task &a, const Task &b) const {
            return (a.burst_length > b.burst_length || (a.burst_length == b.burst_length && a.id > b.id));
        }
};


struct Record {
	int id;
	int finish_time;
	int wait_time;
	int turnaround_time;
	Record() : id(0), finish_time(0), wait_time(0), turnaround_time(0){};
	Record(int id_, int finish_, int wait_, int turnaround_) : id(id_), finish_time(finish_), wait_time(wait_), turnaround_time(turnaround_) {};
};

class Scheduler {
	public:
		string name;
		Scheduler(string name_) : name(name_) {};
		void simulate(string file_name, vector<Task> tasks, int quant_len);
	protected:
		map <int, Record> log; // Maps each task to an execution record	
	private:
		virtual void schedule(vector<Task> tasks, int quant_len) = 0;
		void write_stats(string file_name);

};
#endif
