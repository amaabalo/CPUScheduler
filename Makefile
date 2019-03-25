CC = g++
CCFLAGS = -std=c++11 -g
OBJS = main.o simulator.o scheduler.o fcfs_scheduler.o sjf_scheduler.o srtf_scheduler.o rr_scheduler.o

my_scheduler: $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o my_scheduler

main.o: main.cpp simulator.h scheduler.h fcfs_scheduler.h sjf_scheduler.h srtf_scheduler.h rr_scheduler.h
	$(CC) $(CCFLAGS) -c main.cpp -o main.o

simulator.o: simulator.cpp simulator.h scheduler.h
	$(CC) $(CCFLAGS) -c simulator.cpp -o simulator.o

scheduler.o: scheduler.cpp scheduler.h
	$(CC) $(CCFLAGS) -c scheduler.cpp -o scheduler.o

fcfs_scheduler.o: fcfs_scheduler.cpp fcfs_scheduler.h scheduler.h
	$(CC) $(CCFLAGS) -c fcfs_scheduler.cpp -o fcfs_scheduler.o

sjf_scheduler.o: sjf_scheduler.cpp sjf_scheduler.h scheduler.h
	$(CC) $(CCFLAGS) -c sjf_scheduler.cpp -o sjf_scheduler.o

srtf_scheduler.o: srtf_scheduler.cpp srtf_scheduler.h scheduler.h
	$(CC) $(CCFLAGS) -c srtf_scheduler.cpp -o srtf_scheduler.o

rr_scheduler.o: rr_scheduler.cpp rr_scheduler.h scheduler.h
	$(CC) $(CCFLAGS) -c rr_scheduler.cpp -o rr_scheduler.o

clean:
	rm *.o my_scheduler
