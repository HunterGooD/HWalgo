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
    if (avl->head == NULL) {
        avl->head = insert(avl->head, k);
    } else {
        if (k > avl->head->right->key) {
            avl->head->right = insert(avl->head->right, k);
        } else {
            avl->head->left = insert(avl->head->left, k);
        }
    }
    balance(avl->head);
}

void printAVLTree(avlTree* avl) {
    if (avl->head == NULL) {
        printf("Empty tree");
    }
    printf("%d", avl->head->key);
}
