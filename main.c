#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

void InsertEnd(Node** node, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL)
        return;
        
    newNode->data = data;
    
    if (*node == NULL){
        newNode->next = NULL;
        *node = newNode;
        return;
    }
    
    Node* aux = *node;
    
    while (aux->next != NULL){
        aux = aux->next;
    }
    aux->next = newNode;
}

void deleteList(Node** node){
    while(*node != NULL){
        Node* aux = *node;
        *node = (*node)->next;
        free(aux);
    }
    *node = NULL;
}

Node* search(Node* node, int data){
    while(node != NULL){
        if (node->data == data)
            return node;
        node = node->next;

    }
    return NULL;
}

void updateData(Node* node, int oldData, int newData){
    Node* nodeToChage = search(node, oldData);
        if (nodeToChage == NULL)
            return;
            
    nodeToChage->data = newData;
}

void InsertBeginning(Node** node, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    
    newNode->data = data;
    
    newNode->next = *node;
    *node = newNode;
}

void printList(Node* node){
    while(node != NULL){
        printf("%d\n",node->data);
        node = node->next;
    }
}

int main()
{
    Node* node = NULL;
    int data = 129;
    
    InsertEnd(&node, data);
    InsertEnd(&node, 3);
    InsertEnd(&node, 1);
    InsertEnd(&node, 2);
    InsertBeginning(&node, 0);
    
    printList(node);
    
    
}
