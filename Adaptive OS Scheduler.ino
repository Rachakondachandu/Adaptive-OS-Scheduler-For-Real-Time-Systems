#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 5

// Task structure
typedef struct {
    int id;
    int period;
    int execution_time;
    int deadline;
    int remaining_time;
} Task;

Task tasks[MAX_TASKS];
int num_tasks = 0;

void *task_execution(void *arg) {
    Task *task = (Task *)arg;
    while (1) {
        printf("Task %d executing...\n", task->id);
        usleep(task->execution_time * 1000);
        printf("Task %d completed execution cycle.\n", task->id);
        sleep(task->period);
    }
    return NULL;
}

// Adaptive Scheduler Function
void adaptive_scheduler() {
    pthread_t threads[MAX_TASKS];
    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_execution, (void *)&tasks[i]);
    }
    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }
}

// Main function
int main() {
    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);
    
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter period, execution time, and deadline for task %d: ", i + 1);
        scanf("%d %d %d", &tasks[i].period, &tasks[i].execution_time, &tasks[i].deadline);
        tasks[i].id = i + 1;
        tasks[i].remaining_time = tasks[i].execution_time;
    }
    
    adaptive_scheduler();
    return 0;
}
