#include <stdio.h>
#include <malloc.h>
#include "labs_11/list.h"

int main() {
    T* range = malloc(5 * sizeof(T));
    for (int i = 0; i < 5; i++) {
        *(range + i) = i;
    }
    List* list = constructListFromRange(range, range+4);

    for(int i = 0; i< 5; i++) {
        pop_front(list);
        printList(list);
        printf("\n");
    }

    List* copy = cloneList(list);

    destruct(list);
    destruct(copy);
    free(range);
}