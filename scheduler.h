#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Task {
    int id;           
    int deadline;      
    int executionTime; 
    int remainingTime; 

    Task(int _id, int _deadline, int _executionTime)
        : id(_id), deadline(_deadline), executionTime(_executionTime), remainingTime(_executionTime) {}
    
    bool operator<(const Task &other) const {
        return deadline > other.deadline;  
    }
};

class Scheduler {
private:
    std::priority_queue<Task> taskQueue; 

public:
    void addTask(int id, int deadline, int executionTime);
    void schedule();
    void executeTask(Task &task);
};

#endif 
