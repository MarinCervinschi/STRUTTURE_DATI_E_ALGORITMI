#include <stdio.h>
#include "elemtype.h"
#include "list.h"

extern Item *AppendMod(Item *i1, Item *i2);

int main(void) {
    
    ElemType e1 = {
        .name = "Marin",
        .street = "Via Rieti",
        .number = 3,
        .city = "Modena",
        .province = "MO",
        .postal_code = "41125"
    };
    ElemType e2 = {
        .name = "Cammel",
        .street = "Via Pio",
        .number = 22,
        .city = "Bologna",
        .province = "CG",
        .postal_code = "40225"
    };
    ElemType e3 = {
        .name = "Mich",
        .street = "Via Delle Bombe",
        .number = 1,
        .city = "Rubiera",
        .province = "RB",
        .postal_code = "42134"
    };
    ElemType e4 = {
        .name = "Beppe",
        .street = "Via Della Pace",
        .number = 5,
        .city = "Modena",
        .province = "CP",
        .postal_code = "41136"
    };
    

    Item *list1 = ListCreateEmpty();
    Item *list2 = ListCreateEmpty();

    list1 = ListInsertBack(list1, &e1);
    list1 = ListInsertBack(list1, &e2);
    list2 = ListInsertBack(list2, &e3);
    list2 = ListInsertBack(list2, &e4);
    
    
    list1 = AppendMod(list1,list2);
    
    ListWriteStdout(list1);
    
    ListDelete(list1);
    ListDelete(list2);
    return 0;
}
