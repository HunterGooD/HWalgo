#include <stdio.h>
#include <stdlib.h>

const int DEFAULT_LENGTH = 10;

typedef struct {
    int *arr;
    int length;
    int end;


}stack;

stack* newStack() {
    stack* st = (stack*)malloc(sizeof(stack));
    if (!st) {
        exit(1);
    }
    st->arr =  (int*)malloc(sizeof(int) * DEFAULT_LENGTH);
    if (!st->arr) {
        exit(1);
    }
    st->length =  DEFAULT_LENGTH;
    st->end = 0;
    return st;
}

stack* copy(stack* s) {
    stack* tmp = (stack*)malloc(sizeof(stack));
    tmp->arr = (int*) malloc(sizeof(int)*s->length);
    for (int i = 0; i < s->end; i++) {
        tmp->arr[i] = s->arr[i];
    }
    tmp->end = s->end;
    tmp->length = s->length;
    return tmp;
}

void resize(stack* s) {
    s->arr = (int*)realloc(s->arr, sizeof(int) * s->length * 2);
}

void push(stack* s, int x) {
    if (s->end != s->length) {
        s->arr[s->end++] = x;
        return;
    }
    resize(s);
    push(s, x);
}

int* pop(stack* s) {

    if (s->end == 0) {
        return NULL;
    }

    int* x = malloc(sizeof(int));
    *x = s->arr[--s->end];
    return x;
}

void clearStack(stack* s) {
    free(s->arr);
    s->arr = NULL;
    s->end = 0;
    s->length = 0;
}

void freeStack(stack** s) {
    clearStack(*s);
    free(*s);
    s = NULL;
}
