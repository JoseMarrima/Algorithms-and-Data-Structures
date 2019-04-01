#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* head;

node* newNode(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtHead(int data) {
    node* temp = newNode(data);
    if (head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insertAtTail(int data) {
    node* newEntry = newNode(data);
    if (head == NULL) {
        head = newEntry;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newEntry;
}

void deleteAtHead() {
    node* temp = head;
    if (head == NULL) {
        return;
    }
    head = temp->next;
    free(temp);
}

void deleteAtTail() {
    if (head == NULL) {
        return;
    }
    node* curr = head;
    node* temp = curr;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
}

void print() {
    if (head == NULL) return;
    node* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseIterative() {
  node* curr = head;
  node* next = NULL;
  node* prev = NULL;
  while(curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

void printRecursion(node* temp) {
    if(temp == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", temp->data);
    printRecursion(temp->next);
}

void printRecursionReverse(node* temp) {
    if(temp == NULL) {
        //printf("\n");
        return;
    }
    printRecursionReverse(temp->next);
    printf("%d ", temp->data);
}

int main() {
   insertAtHead(23);
   insertAtTail(90);
   insertAtTail(60);
   print();
   printf("deleting from tail \n");
   deleteAtTail();
   print();
   insertAtTail(12);
   print();
   deleteAtHead();
   print();
   deleteAtHead();
   print();
}
