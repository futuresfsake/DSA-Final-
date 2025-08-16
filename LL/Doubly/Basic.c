// ! Insereting  a node in an empty list

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
  
};

struct Node* addToEmpty (struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    
    return head;

}

int main() {
    
    struct Node* head = NULL;
    head = addToEmpty(head, 45);
    printf("%d", head->data);
    return 0;

}