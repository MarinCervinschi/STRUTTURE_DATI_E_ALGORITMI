#include "pulce.h"

// Function prototypes
const Item *SaltaIndietro(const Item *list, int num, size_t *salti, size_t n);
const Item *SaltaInAvanti(const Item *list, int num, size_t *salti, size_t n);

// Function to calculate the path of the pulce
const Item* CalcolaPercorso(const Item *start, size_t n){
    // Check if the start is NULL
    if(!start){
        return NULL;
    }
    // Check if there's only one item in the list, no movement is possible
    if (!start->next && !start->prev) {
        return start;
    }
    // Initialize a pointer tmp to keep track of the current item in the list
    const Item *tmp = start;

    // Variable to keep track of the total jumps made by the pulce
    size_t salti = 0;

    // Loop until we reach the desired number of jumps (n)
    while (1) {
        if(salti >= n){
            break;
        }
        // If the value of the current item is positive, jump forward
        if(tmp->value > 0){
            tmp = SaltaInAvanti(tmp, tmp->value, &salti, n);
            if(salti >= n){
                break;
            }
        }
        // If the value of the current item is 0, the pulce doesn't move, return the current item
        else if (tmp->value == 0){
            break;
        }
        // If the value of the current item is negative, jump backward
        else{
            tmp = SaltaIndietro(tmp, abs(tmp->value), &salti, n);
            if(salti >= n){
                break;
            }
        }
    }
    // return current position
    return tmp;
}

// Function to jump backward by 'num' steps
const Item *SaltaIndietro(const Item *list, int num, size_t *salti, size_t n){
    for (int i = 0; i < num; ++i) {
        if(*salti >= n){
            return list;
        }
        // If there is no previous item, jump forward
        if(!list->prev){
            list = SaltaInAvanti(list, num - i, salti, n);
            break;
        }
        // Move to the previous item and increment the number of jumps made (salti)
        list = list->prev;
        ++*salti;
    }
    return list;
}

// Function to jump forward by 'num' steps
const Item *SaltaInAvanti(const Item *list, int num, size_t *salti, size_t n){
    for (int i = 0; i < num; ++i) {
        if(*salti >= n){
            return list;
        }
        // If there is no next item, jump backward
        if(!list->next){
            list = SaltaIndietro(list, num - i, salti, n);
            break;
        }
        // Move to the next item and increment the number of jumps made (salti)
        list = list->next;
        ++*salti;
    }
    return list;
}
