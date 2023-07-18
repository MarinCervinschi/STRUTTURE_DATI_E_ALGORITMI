#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int profit;
    int duration;
    int deadline;
}job;
extern int ScheduleJobs(const job* jobs, size_t j_size);
int main(void) {
    
    job jobs[] = { { .profit = 50, .duration = 2, .deadline = 4 },
                   { .profit = 100, .duration = 4, .deadline = 7 },
                   { .profit = 30, .duration = 1, .deadline = 3 }};
    size_t size = sizeof(jobs) / sizeof(job);
    
    printf("con %d di profitto\n", ScheduleJobs(jobs, size));
    
    return 0;
}
