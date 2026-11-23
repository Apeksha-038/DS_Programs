#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

struct node *insert(struct node *head, int value)
{
    struct node *newnode = createNode(value);
    struct node *temp;

    if (head == NULL)
        return newnode;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void sort(struct node *head)
{
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


struct node *concatenate(struct node *head1,
                         struct node *head2)
{
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n, value, i, choice;

    do
    {
        printf("\n1. Create First List");
        printf("\n2. Create Second List");
        printf("\n3. Display Lists");
        printf("\n4. Sort First List");
        printf("\n5. Reverse First List");
        printf("\n6. Concatenate Two Lists");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                head1 = NULL;

                for (i = 0; i < n; i++)
                {
                    printf("Enter data: ");
                    scanf("%d", &value);
                    head1 = insert(head1, value);
                }
                break;

            case 2:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                head2 = NULL;

                for (i = 0; i < n; i++)
                {
                    printf("Enter data: ");
                    scanf("%d", &value);
                    head2 = insert(head2, value);
                }
                break;

            case 3:
                printf("First List: ");
                display(head1);

                printf("Second List: ");
                display(head2);
                break;

            case 4:
                sort(head1);
                printf("Sorted List: ");
                display(head1);
                break;

            case 5:
                head1 = reverse(head1);
                printf("Reversed List: ");
                display(head1);
                break;

            case 6:
                head1 = concatenate(head1, head2);
                head2 = NULL;

                printf("Concatenated List: ");
                display(head1);
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (1);

    return 0;
}
