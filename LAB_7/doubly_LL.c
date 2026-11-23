#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};


struct node* create(struct node *head, int n) {
    struct node *newnode, *temp;
    int i, value;

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        }
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    return head;
}


struct node* insertLeft(struct node *head, int key, int value) {
    struct node *temp, *newnode;

    temp = head;

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = temp;
    newnode->prev = temp->prev;

    if(temp->prev != NULL) {
        temp->prev->next = newnode;
    }
    else {
        head = newnode;
    }

    temp->prev = newnode;

    return head;
}


struct node* deleteNode(struct node *head, int key) {
    struct node *temp = head;

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    return head;
}


void display(struct node *head) {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main() {
    struct node *head = NULL;
    int n, choice, key, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = create(head, n);

    while(1) {
        printf("\n\n1. Insert to the left");
        printf("\n2. Delete a node");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value before which to insert: ");
                scanf("%d", &key);

                printf("Enter new value: ");
                scanf("%d", &value);

                head = insertLeft(head, key, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);

                head = deleteNode(head, key);
                break;

            case 3:
                display(head);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
