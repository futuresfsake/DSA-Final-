#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *link;
};

// Insert at end
void insertEnd(struct node **head, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Display list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Delete at beginning
void deleteBeginning(struct node **head) {
    if (*head == NULL) {
        printf("List empty!\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->link;
    free(temp);
}

// Delete at end
void deleteEnd(struct node **head) {
    if (*head == NULL) {
        printf("List empty!\n");
        return;
    }
    if ((*head)->link == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *temp = *head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    free(temp->link);
    temp->link = NULL;
}

// Delete by value
void deleteByValue(struct node **head, int value) {
    if (*head == NULL) return;

    struct node *temp = *head;

    // if head holds the value
    if (temp->data == value) {
        *head = temp->link;
        free(temp);
        return;
    }

    while (temp->link != NULL && temp->link->data != value) {
        temp = temp->link;
    }

    if (temp->link == NULL) {
        printf("Value not found!\n");
        return;
    }

    struct node *toDelete = temp->link;
    temp->link = toDelete->link;
    free(toDelete);
}

// Main function
int main() {
    struct node *head = NULL;

    // Insert some nodes
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Original List: ");
    display(head);

    deleteBeginning(&head);
    printf("After deleting beginning: ");
    display(head);

    deleteEnd(&head);
    printf("After deleting end: ");
    display(head);

    deleteByValue(&head, 20);
    printf("After deleting value 20: ");
    display(head);

    return 0;
}
