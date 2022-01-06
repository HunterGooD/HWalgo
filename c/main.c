#include <stdio.h>
#include "stack.h"

int main() {
    stack *s = newStack();
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    stack *sCopy = copy(s);

    printf("%d\n", *pop(s));
    printf("%d\n", *pop(s));
    printf("%d\n", *pop(s));
    printf("%d\n", *pop(s));
    int* a = pop(s);
    if (a != NULL) {
        printf("%d\n", *a);
    }
    printf("%d\n", *pop(sCopy));
    printf("%d\n", *pop(sCopy));

    freeStack(&s);
    freeStack(&sCopy);
    return 0;
}