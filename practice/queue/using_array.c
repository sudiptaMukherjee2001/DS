#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        queue[rear] = data;
        printf("\nData added successfuly\n");
    }
    else
    {
        rear++;
        queue[rear] = data;
        printf("\nData added successfuly\n");
    }
}

void dequeue()
{
    int data;
    if (rear == -1 && front == -1)
    {
        printf("Queue is empty\n");
    }
    if (front == rear)
    {
        data = queue[front];
        front = -1;
        rear = -1;
        printf("\nDeleted data=> %d ", data);
    }
    else
    {
        data = queue[front];
        front++;
        printf("\nDeleted data=> %d ", data);
    }
}

void display()
{
    int i;
    for (i = front; i != rear + 1; i++)
    {
        printf("%d ", queue[i]);
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