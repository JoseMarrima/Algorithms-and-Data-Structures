#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

node* head = NULL;

node* newNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertAtHead(int data) {
    node* temp = newNode(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(int data) {
    node* newEntry = newNode(data);
    if(head == NULL) {
        head = newEntry;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newEntry;
    newEntry->prev = temp;
}

void print() {
    if(head == NULL) return;
    node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printReverse() {
    if(head == NULL) return;
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
   insertAtTail(12);
   insertAtTail(56);
   insertAtTail(78);
   insertAtTail(90);
   print();
   printReverse();
   print();
}
