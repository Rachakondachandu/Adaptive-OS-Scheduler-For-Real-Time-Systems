#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TASKS 3

// Task structure
typedef struct {
    int id;
    int execution_time;
} Task;

Task tasks[MAX_TASKS];

void *task_execution(void *arg) {
    Task *task = (Task *)arg;
    printf("Task %d started execution...\n", task->id);
    usleep(task->execution_time * 1000);
    printf("Task %d completed execution.\n", task->id);
    return NULL;
}

// Simple Round-Robin Scheduler
void simple_scheduler() {
    pthread_t threads[MAX_TASKS];
    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_create(&threads[i], NULL, task_execution, (void *)&tasks[i]);
    }
    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Main function
int main() {
    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Enter execution time for task %d: ", i + 1);
        scanf("%d", &tasks[i].execution_time);
        tasks[i].id = i + 1;
    }
    
    simple_scheduler();
    return 0;
}
