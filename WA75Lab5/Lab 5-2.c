
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

// Stack PUSH operation
void push(int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into Stack\n", value);
}

// Stack POP operation
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

// Display Stack
void displayStack()
{
    struct node *temp = top;

    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Queue ENQUEUE operation
void enqueue(int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Queue Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into Queue\n", value);
}

// Queue DEQUEUE operation
void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display Queue
void displayQueue()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- STACK AND QUEUE OPERATIONS ---\n");
        printf("1. Stack PUSH\n");
        printf("2. Stack POP\n");
        printf("3. Display Stack\n");
        printf("4. Queue ENQUEUE\n");
        printf("5. Queue DEQUEUE\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                printf("Program Terminated.\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

