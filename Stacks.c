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

void pop() {
    if(head == NULL) return;
    node* temp = head;
    head = temp->next;
    free(temp);
}

void push(int data) {
    node* temp = newNode(data);
    if(head == NULL) {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
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

int main() {
   push(23);
   push(24);
   push(60);
   print();
   pop();
   print();
   pop();
   print();
}
