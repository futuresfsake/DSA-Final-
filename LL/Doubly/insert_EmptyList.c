#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* addToEmptyList(struct node* head, int data){

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (!temp) {
        printf("Dynamic memory allocation failed!.\n");
        return 0;
    }

    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    head = temp;
    return head;
}

int main() {

    struct node* head = NULL;
    head = addToEmptyList(head, 120);

    printf("%d", head->data);
    return 0;




}