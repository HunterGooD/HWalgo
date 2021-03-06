#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    int key;
    int value;
    unsigned char height;
    node *left;
    node *right;
};

node* newNode(int key) {
    node* n = (node*)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->key = key;
    n->value = 0;
    n->height = 0;
    return n;
}
void printNode(node *n) {
    if (n == NULL) {
        return;
    }
    printf("- %d -", n->key);
    printNode(n->right);
    printNode(n->left);
}

int height(node *n) {
    return n == NULL ? 0 : n->height;
}

int balanceFactor(node *n) {
    return height(n->right) - height(n->left);
}

void recalcHeight(node *n) {
    unsigned char hl = height(n->left);
    unsigned char hr = height(n->right);
    n->height = (hl>hr ? hl : hr)+1;
}

node* rotateRight(node *n) {
    node* l = n->left;
    n->left = l->right;
    l->right = n;
    recalcHeight(n);
    recalcHeight(l);
    return l;
}

node* rotateLeft(node *n) {
    node* r = n->right;
    n->right = r->left;
    r->left = n;
    recalcHeight(n);
    recalcHeight(r);
    return r;
}

node* balance(node *n) {
    recalcHeight(n);
    if (balanceFactor(n) == 2) {
        if (balanceFactor(n->right) < 0) {
            n->right = rotateRight(n->right);
        }
        return rotateLeft(n);
    }
    if (balanceFactor(n) == -2) {
        if (balanceFactor(n->left) > 0) {
            n->left = rotateLeft(n->left);
        }
        return rotateRight(n);
    }
    return n;
}

node* insert(node *n, int k) {
    if (n == NULL) {
        return newNode(k);
    }
    if (k < n->key) {
        n->left = insert(n->left, k);
    } else {
        n->right = insert(n->right, k);
    }
    return balance(n);

}

void freeNode(node **n) {
    if (n == NULL) {
        return;
    }
    freeNode((*n)->left == NULL ? NULL : &(*n)->left);
    freeNode((*n)->right == NULL ? NULL : &(*n)->right);
    free(*n);
    (*n) = NULL;
}
