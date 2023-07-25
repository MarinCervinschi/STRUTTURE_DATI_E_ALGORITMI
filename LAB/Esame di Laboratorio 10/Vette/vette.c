#include "list.h"
#include <stdlib.h>
int ContaVette(const Item* i){
    if(!i){
        return 0;
    }
    int vette = 1;
    while (i) {
        int k = 0;
        for (const Item *tmp = i->next; tmp; tmp = tmp->next){
            if(i->value > tmp->value){
                k = 1;
            }else{
                k = 0;
                break;
            }
        }
        if(k){
            ++vette;
        }
        i = i->next;
    }
    
    return vette;
}
