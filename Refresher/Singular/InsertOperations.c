#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function declarations
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
// struct Node* insertAtPosition(struct Node* head, int data, int position);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;  // empty list

    // Example usage (you will test after implementing functions)
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    // head = insertAtPosition(head, 15, 2); // insert 15 at position 2

    printf("Linked List: ");
    displayList(head);

    return 0;
}

// Function definitions (to be implemented by you!)
struct Node* insertAtBeginning(struct Node* head, int data) {
    // TODO: create a new node and insert at beginning

 

    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    if (!new) {
        printf("Memory allocation failed.\n"); return 0;
    }

   new->data = data;
   new->next = NULL;

   
   new->next = head;
   head = new;

   return head;


}

struct Node* insertAtEnd(struct Node* head, int data) {
    // TODO: create a new node and insert at end

   

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Dynamic Memory Allocation failed!");
        return 0;
    }

    newNode->data = data;
 newNode->next = NULL;

    struct Node* temp = head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
   

    return head;
}




void displayList(struct Node* head) {
    // TODO: traverse and print list

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

