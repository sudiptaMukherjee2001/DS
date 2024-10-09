#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    /* First check if my queue is full or not*/
    if (rear == SIZE - 1)
    {
        printf("\n QUEUE IS FULL\n");
    }
    else if (rear == -1 && front == -1)
    {
        /* This will preform when my queue is empty */
        front++;
        rear++;
        queue[rear] = data;
        printf("Data has been added successfuly in the queue");
    }
    else
    {
        /* for normal insert */
        rear++;
        queue[rear] = data;
        printf("Data has been added successfuly in the queue");
    }
}

/* DELETE THE QUEUE */
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else if (front == rear)
    {
        /* if only one element present then this code block will work */
        int data = queue[front];
        printf("\n Deleted data is =>%d", data);
        front = -1;
        rear = -1;
    }
    else
    {
        int data = queue[front];
        printf("\n Deleted data is =>%d", data);
        front++;
    }
}

/* Display the queue */
void display()
{
    printf("\nQUEUE DATA\n");
    for (int i = front; i != rear + 1 && i <= SIZE - 1; i++)
    {
        printf("%d\t", queue[i]);
    }
}

int main()
{
    int ch;
    int data;
    while (1)
    {
        printf("\nQueue operation");
        printf("\n 1.Enqueue \n2.Dequeue\n3.Display the queue\n4.Exit");
        printf("\nEnter the choice :\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the data =>\t");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            //   display the queue
            display();
            break;
        case 4:
            return 0;

        default:
            printf("\n INVALID CHOICE");
            break;
        }
    }
}