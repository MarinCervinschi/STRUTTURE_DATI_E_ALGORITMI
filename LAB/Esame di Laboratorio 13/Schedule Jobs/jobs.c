#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
    int profit;
    int duration;
    int deadline;
}job;
int TrovaIlPiùAppetibile(const job* jobs, size_t j_size, bool *used){
    int appetibilità = -1;
    int index = 0;
    for (size_t i  = 0; i < j_size; ++i) {
        if(!used[i]){
            int tmp = jobs[i].profit / jobs[i].duration;
            if(tmp > appetibilità){
                appetibilità = tmp;
                index = (int)i;
            }
//            if(tmp == appetibilità){
//                if(jobs[index].duration > jobs[i].duration){
//                    continue;
//                }else{
//                    index = (int)i;
//                }
//            }
        }
    }
    return index;
}
int ScheduleJobs(const job* jobs, size_t j_size){
    
    bool *used = calloc(j_size, sizeof(bool));
    
    int time = 0;
    for (size_t i  = 0; i < j_size; ++i) {
        int best = TrovaIlPiùAppetibile(jobs, j_size, used);
        if(time + jobs[best].duration <= jobs[best].deadline){
            printf("%d ", best);
            used[best] = true;
            time += jobs[best].duration;
        }
    }
    
    // calcola profitto
    int profitto = 0;
    for (size_t i  = 0; i < j_size; ++i) {
        if(used[i]){
            profitto += jobs[i].profit;
        }
    }
    free(used);
    return profitto;
}
