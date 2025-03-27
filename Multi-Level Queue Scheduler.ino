#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 3

typedef struct {
    int id;
    int execution_time;
    int queue_level;
} Task;

Task tasks[MAX_TASKS];

void mlq_scheduler() {
    for (int i = 0; i < MAX_TASKS - 1; i++) {
        for (int j = i + 1; j < MAX_TASKS; j++) {
            if (tasks[i].queue_level > tasks[j].queue_level) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Executing Task %d (Queue Level: %d)...\n", tasks[i].id, tasks[i].queue_level);
        sleep(tasks[i].execution_time);
        printf("Task %d completed.\n", tasks[i].id);
    }
}

int main() {
    for (int i = 0; i < MAX_TASKS; i++) {
        printf("Enter execution time and queue level for Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].execution_time, &tasks[i].queue_level);
        tasks[i].id = i + 1;
    }
    mlq_scheduler();
    return 0;
}
