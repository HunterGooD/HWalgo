#include <stdio.h>
#include <stdlib.h>
#include "node.h"

//typedef struct Node Node;
//struct Node{
    //int n;
  //  Node* next;
//};

//Node* newNode(int n) {
 //   Node* tmp = (Node*)malloc(sizeof(Node));
  //  tmp->n = n;
   // return tmp;
//}

typedef struct {
    Node* head;
    int length;
}List;

void addToListNode(List* l, int n); // Вставка в конец
//void addNode(Node* current, Node* add); // private
//void addNodeIdx(Node* node, Node* add,int currentIdx, int idx); //  private
void addToListNodeIdx(List* l,int n, int idx); // Вставка по индексу
void addToListNodeBeforeIdx(List* l,int n, int idx); // Вставка перед индексом
//void printNodes(Node* node, int idx);

List* newList() {
    List* l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->length = 0;
    return l;
}

List* newListFromArray(int arr[], int length) {
    List* l = (List*)malloc(sizeof(List));
    l->head = NULL;
    for (int i = 0; i < length; i++) {
        addToListNode(l, arr[i]);
    }
    return l;
}

void addToListNode(List* l, int n){
    Node *node = newNode(n);
    node->next = NULL;
    if (l->head == NULL) {
        l->head = malloc(sizeof(Node));
        l->head = node;
    } else {
        addNode(l->head, node);
    }
    l->length++;
}

void addToListNodeIdx(List* l,int n, int idx) {
    if (idx > l->length) {
        return;
    }
    Node *node = newNode(n);
    if (idx == 1) {
        node->next = l->head;
        l->head = node;
        return;
    }
    addNodeIdx(l->head, node, 0, idx);
    l->length++;
}
/*
void addNodeIdx(Node* node, Node* add, int currentIdx, int idx) {
    if (currentIdx+1 == idx) {
        add->next = node->next;
        node->next = add;
        return;
    }
    addNodeIdx(node->next, add, currentIdx+1, idx);
}
*/
void addToListNodeBeforeIdx(List* l,int n, int idx) {

}
/*
void addNode(Node* current, Node* add) {
    if (current->next == NULL) {
        current->next = malloc(sizeof(Node));
        current->next = add;
        return;
    }
    addNode(current->next, add);
}
*/
void printList(List* l) {
    if (l->head == NULL) {
        printf("Length 0");
        return;
    }
    printf("Length: %d Head: %d Tail: ", l->length, l->head->n);
    printNodes(l->head->next, 1);
    printf("> NULL\n");
}
/*
void printNodes(Node* node, int idx) {
    if (node->next == NULL) {
        return;
    }
    printf("[%d] %d - ", idx, node->n);
    printNodes(node->next, idx+1);
}
*/
void freeList(List **list) {
	free_nodes(&(*list)->head);
	free(*list);
	list = NULL;
}
