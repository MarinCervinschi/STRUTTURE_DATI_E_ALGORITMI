#include "pulce.h"
#include <stdlib.h>
#include <math.h>
const Item *SaltaIndietro(const Item *list, int num, size_t *salti, size_t n){
    for (int i = 0; i < num; ++i) {
        if(*salti >= n){
            return list;
        }
        if(!list->prev){
            //salta in avanti
            for (int j = i; j < num; ++j){
                if(*salti >= n){
                    return list;
                }
                list = list->next;
                ++*salti;
            }
            break;
        }
        list = list->prev;
        ++*salti;
    }
    return list;
}
const Item *SaltaInAvanti(const Item *list, int num, size_t *salti, size_t n){
    for (int i = 0; i < num; ++i) {
        if(*salti >= n){
            return list;
        }
        if(!list->next){
            if(*salti >= n){
                return list;
            }
            list = SaltaIndietro(list, num - 1, salti, n);
            break;
        }
        list = list->next;
        ++*salti;
    }
    return list;
}
const Item* CalcolaPercorso(const Item *start, size_t n){
    if(!start){
        return NULL;
    }
    if (!start->next || !start->prev) {
        return start;
    }
    if(start->value == 0){
        return start;
    }
    const Item *tmp = start;
    size_t salti = 0;
    while (1) {
        if(salti >= n){
            return tmp;
        }
        if(tmp->value > 0){
            tmp = SaltaInAvanti(tmp, tmp->value, &salti, n);
            if(salti >= n){
                return tmp;
            }
        }else if (tmp->value == 0){
            return tmp;
        }else{
            tmp = SaltaIndietro(tmp, abs(tmp->value), &salti, n);
            if(salti >= n){
                return tmp;
            }
        }
    }
    return tmp;
}
