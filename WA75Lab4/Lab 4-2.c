
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create a linked list
void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }
}

// Delete first element
void delete_first()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Delete specified element
void delete_specified()
{
    struct node *temp, *prev;
    int value;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while(temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Delete last element
void delete_last()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    prev = NULL;

    if(head->next == NULL)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted element: %d\n", temp->data);

    free(temp);
}

// Display linked list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;
     printf("DHANYA M\t  1WA25CS075\t  3 nov 2026");

    while(1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                delete_first();
                break;

            case 3:
                delete_specified();
                break;

            case 4:
                delete_last();
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

