#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct {
    node* head;
    int depth;
}avlTree;

avlTree* NewAVLTree() {
    avlTree* avl = (avlTree*)malloc(sizeof(avlTree));
    avl->head = NULL;
    return avl;
}

void insertInTree(avlTree* avl, int k) {
    avl->head = insert(avl->head, k);
}

void printAVLTree(avlTree* avl) {
    if (avl->head == NULL) {
        printf("Empty tree");
    }
    printNode(avl->head);
    printf("\n");
}

void freeAVL(avlTree **avl) {
    freeNode((*avl)->head == NULL ? NULL : &(*avl)->head);
    free(*avl);
    (*avl) = NULL;
}
