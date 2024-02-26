#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertSorted(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = data;

    if (head == NULL || head->info > data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->info < data) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteBeforePosition(int position) {
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        printf("Cannot delete before position 1.\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Cannot delete before position %d.\n", position);
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void deleteAfterPosition(int position) {
    if (head == NULL || head->next == NULL) {
        printf("List is empty or has only one node. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Cannot delete after position %d.\n", position);
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void display() {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;

    
        printf("\nMenu:\n");
        printf("1. Insert at the front\n");
        printf("2. Insert at the end\n");
        printf("3. Insert in ascending order\n");
        printf("4. Delete first node\n");
        printf("5. Delete before specified position\n");
        printf("6. Delete after specified position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
do {    printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                insertFront(data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 3:
                printf("Enter data to insert in ascending order: ");
                scanf("%d", &data);
                insertSorted(data);
                break;

            case 4:
                deleteFront();
                break;

            case 5:
                printf("Enter position before which you want to delete: ");
                scanf("%d", &position);
                deleteBeforePosition(position);
                break;

            case 6:
                printf("Enter position after which you want to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(position);
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}

