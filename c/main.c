#include <stdio.h>
#include <malloc.h>
//#include "stack/stack.h"
#include "list/list.h"

int main() {
    /**
     * Для просмотра работы структуры stack
     */
//    stack *s = newStack();
//    push(s, 2);
//    push(s, 3);
//    push(s, 4);
//    push(s, 5);
//    stack *sCopy = copy(s);
//
//    printf("%d\n", *pop(s));
//    printf("%d\n", *pop(s));
//    printf("%d\n", *pop(s));
//    printf("%d\n", *pop(s));
//    int* a = pop(s);
//    if (a != NULL) {
//        printf("%d\n", *a);
//    }
//    printf("%d\n", *pop(sCopy));
//    printf("%d\n", *pop(sCopy));
//
//    freeStack(&s);
//    freeStack(&sCopy);
    /**
     * Для просмотра структуры List
     */
    int* arr = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        arr[i] = i+1;
    }
    List* l = newListFromArray(arr, 10);
    addToListNode(l, 10);
    addToListNodeIdx(l, 4, 3);
    printList(l);
    return 0;
}
