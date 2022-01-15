#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    int n;
    Node* next;
};

void addNode(Node* current, Node* add); // private
void addNodeIdx(Node* node, Node* add,int currentIdx, int idx); //  private
void printNodes(Node* node, int idx);


Node* newNode(int n) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->n = n;
    return tmp;
}

void addNode(Node* current, Node* add) {
    if (current->next == NULL) {
        current->next = (Node*)malloc(sizeof(Node));
        current->next = add;
        return;
    }
    addNode(current->next, add);
}

void printNodes(Node* node, int idx) {
    if (node->next == NULL) {
        return;
    }
    printf("[%d] %d - ", idx, node->n);
    printNodes(node->next, idx+1);
}

void addNodeIdx(Node* node, Node* add, int currentIdx, int idx) {
    if (currentIdx+1 == idx) {
        add->next = node->next;
        node->next = add;
        return;
    }
    addNodeIdx(node->next, add, currentIdx+1, idx);
}

void free_nodes(Node** node) {
	if ((*node)->next == NULL) {
		return;
	}
	free_nodes(&(*node)->next);
	free(node);
	node = NULL;
}
