#include <stdio.h>
#include "elemtype.h"
#include "list.h"

extern const ElemType *Find(const Item *i, const char *name);

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
        .city = "Modena",
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
        .city = "Carpi",
        .province = "CP",
        .postal_code = "41136"
    };
    

    Item *list = ListCreateEmpty();
    

    list = ListInsertBack(list, &e1);
    list = ListInsertBack(list, &e2);
    list = ListInsertBack(list, &e3);
    list = ListInsertBack(list, &e4);
    
    
    const ElemType *trova = Find(list, "Cammel");
    if(trova){
        ElemWriteStdout(trova);
    }
    
    
    return 0;
}
