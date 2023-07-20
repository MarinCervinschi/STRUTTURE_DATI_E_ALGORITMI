#include "sum_dlist.h"

// This function copies the linked list pointed to by `i`.
Item *DListCopy(const Item *i) {
    // Create an empty list.
    Item *list_copy = DListCreateEmpty();

    // Iterate through the original list, adding each element to the copy.
    for (; !DListIsEmpty(i); i = DListGetTail(i)) {
        // Insert the element at the end of the copy list.
        list_copy = DListInsertBack(list_copy, DListGetHeadValue(i));
    }

    // Return the copy list.
    return list_copy;
}

// This function sums the two linked lists pointed to by `i1` and `i2`.
Item* DListSum(const Item *i1, const Item *i2) {
    // If both lists are empty, return an empty list.
    if (!i1 && !i2) {
        return NULL;
    }

    // If `i1` is empty, return a copy of `i2`.
    if (!i1) {
        return DListCopy(i2);
    }

    // If `i2` is empty, return a copy of `i1`.
    if (!i2) {
        return DListCopy(i1);
    }
    // Iterate `i1` and `i2` until the end of list
    while (i1->next) {
        i1 = i1->next;
    }
    while (i2->next) {
        i2 = i2->next;
    }

    // Initialize the result list and the carry.
    Item *result = NULL;
    ElemType carry = 0;

    // Iterate through the two lists, adding the elements together and updating the carry.
    while (i1 || i2 || carry) {
        // Calculate the sum of the current elements and the carry.
        ElemType sum = carry;

        // If `i1` is not empty, add the value of the current element.
        if (i1) {
            sum += i1->value;
            i1 = i1->prev;
        }

        // If `i2` is not empty, add the value of the current element.
        if (i2) {
            sum += i2->value;
            i2 = i2->prev;
        }

        // Update the carry.
        carry = sum / 10;
    
        // Update the sum.
        sum %= 10;
    
        // Insert the current sum into the result list.
        result = DListInsertHead(&sum, result);
    }

    // Return the result list.
    return result;
}
