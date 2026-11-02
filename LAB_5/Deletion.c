#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create() {
    struct Node *newNode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        }
        else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}


void deleteFirst() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First element deleted\n");
}


void deleteSpecified() {
    struct Node *temp, *prev;
    int key;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;

    if(head->data == key) {
        head = head->next;
        free(temp);
        printf("Element deleted\n");
        return;
    }

    prev = NULL;

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Element not found\n");
    }
    else {
        prev->next = temp->next;
        free(temp);
        printf("Element deleted\n");
    }
}

void deleteLast() {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last element deleted\n");
        return;
    }

    temp = head;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last element deleted\n");
}


void display() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n1. Create\n");
        printf("2. Delete First\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
