
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Insert a node at the end
struct node *insert(struct node *head, int value)
{
    struct node *newNode = createNode(value);
    struct node *temp;

    if (head == NULL)
        return newNode;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Display the linked list
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

// Sort the linked list using Bubble Sort
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

    printf("List sorted successfully!\n");
}

// Reverse the linked list
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

    printf("List reversed successfully!\n");

    return prev;
}

// Concatenate two linked lists
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

// Main function
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int choice, value, n, i;

    while (1)
    {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display First List\n");
        printf("4. Sort First List\n");
        printf("5. Reverse First List\n");
        printf("6. Concatenate Two Lists\n");
        printf("7. Display Second List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

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

                for (i = 0; i < n; i++)
                {
                    printf("Enter data: ");
                    scanf("%d", &value);
                    head2 = insert(head2, value);
                }
                break;

            case 3:
                printf("First Linked List: ");
                display(head1);
                break;

            case 4:
                sort(head1);
                display(head1);
                break;

            case 5:
                head1 = reverse(head1);
                display(head1);
                break;

            case 6:
                head1 = concatenate(head1, head2);
                head2 = NULL;
                printf("Lists concatenated successfully!\n");
                display(head1);
                break;

            case 7:
                printf("Second Linked List: ");
                display(head2);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
