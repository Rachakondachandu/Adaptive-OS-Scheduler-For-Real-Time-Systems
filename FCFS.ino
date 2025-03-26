#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TASKS 3

typedef struct {
    int id;
    int execution_time;
} Task;

Task tasks[MAX_TASKS];

void fcfs_scheduler() {
    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Executing Task %d...\n", tasks[i].id);
        sleep(tasks[i].execution_time);
        printf("Task %d completed.\n", tasks[i].id);
    }
}

int main() {
    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Enter execution time for Task %d: ", i + 1);
        scanf("%d", &tasks[i].execution_time);
        tasks[i].id = i + 1;
    }
    fcfs_scheduler();
    return 0;
}
