#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    /* First check if my queue is full or not*/
    printf("\nfront=>%d\t\n", front);
    printf("\nbefore insert data rear is =>%d\t\n", rear);
    if (front == (rear + 1) % SIZE)
    {
        printf("\nQueue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = front + 1;
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
    }
    else
    {

        rear = (rear + 1) % SIZE;
        queue[rear] = data;
    }
    printf("\nfront=>%d\t\n", front);
    printf("\nafter insert data rear is rear=>%d\t\n", rear);
    printf("\nafter insert data is3=>%d\t\n", queue[rear]);
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty\n");
    }
    else if (front == rear)
    {
        int data = queue[front];
        printf("\nDeletd data==>%d\n", data);
        front--;
        rear--;
    }
    else
    {
        int data = queue[front];
        printf("\nDeleted data%d\n", data);
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;
    printf("\nfront=>%d\t\n", front);
    printf("\nrear=>%d\t\n", rear);

    for (i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d\n", queue[i]);
    }
    printf("%d\n", queue[i]);
}

/* DELETE THE QUEUE */
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