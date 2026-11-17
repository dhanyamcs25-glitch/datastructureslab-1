
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create a new node
struct node *createNode(int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Create a doubly linked list
void create()
{
    struct node *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("Doubly Linked List created successfully!\n");
}

// Insert a node to the left of a specific node
void insertLeft()
{
    struct node *newNode, *temp;
    int value, key;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the value of the new node: ");
    scanf("%d", &value);

    printf("Enter the value before which to insert: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Specified node not found!\n");
        return;
    }

    newNode = createNode(value);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;

    temp->prev = newNode;

    printf("Node inserted successfully!\n");
}

// Delete a node based on a specific value
void deleteNode()
{
    struct node *temp;
    int key;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted successfully!\n");
}

// Display the doubly linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Doubly Linked List:\n");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- DOUBLY LINKED LIST OPERATIONS ---\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Insert a Node to the Left\n");
        printf("3. Delete a Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                insertLeft();
                break;

            case 3:
                deleteNode();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program Terminated.\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

