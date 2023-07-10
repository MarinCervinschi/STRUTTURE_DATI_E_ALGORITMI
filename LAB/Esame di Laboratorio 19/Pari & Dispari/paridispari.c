#include <stdlib.h>
#include "list.h"
#include "elemtype.h"
#include <stdbool.h>
int Conta(Item *i, int resto){
    int num = 0;
    while (i) {
        if(i->value % 2 == resto){
            ++num;
        }
        i = i->next;
    }
    return num;
}
bool Verifica(Item *i, int size){
    if(size == 1 && i->value % 2 ==1){
        return false;
    }
    int index = 0;
    while (index < size-1) {
        // primo pari e secondo dispari || primo dispari e secondo pari
        if( ( i->value % 2 == 0 && i->next->value % 2 == 1 ) || ( i->value % 2 == 1 && i->next->value % 2 == 0 )){
            return false;
        }
        i = i->next;
        ++index;
    }
    return true;
}

Item *PariDispari(Item *i){
    if(!i){
        return NULL;
    }
    
    int num_pari = Conta(i, 0);
    int num_dispari = Conta(i, 1);
    
    Item *head = i;
    while (!Verifica(head, num_pari) ) {
        Item *prev = NULL;
        Item *curr = head;
        int index = 0;
        while (index < num_pari+num_dispari && curr->next) {
            Item *foll = curr->next;
            Item *follfoll = foll->next;
            if((curr->value % 2 == 1 && curr->next->value % 2 == 0 )){
                if(!prev){
                    head = foll;
                    curr->next = follfoll;
                    foll->next = curr;
                }else{
                    prev->next = foll;
                    curr->next = follfoll;
                    foll->next = curr;
                }
              
                prev = foll;
            }else{
                prev = curr;
                curr = foll;
                
            }
            ++index;
        }
    }
    
    
    return head;
}
