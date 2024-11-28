#include <stdio.h>
#include <stdlib.h>

/* CREATE THE NODE STRUCTURE*/
struct nodeStruct
{
    int data;
    struct nodeStruct *link;
} *front = NULL, *rear = NULL;

/* node create and perfrom queue logic */

struct nodeStruct *enqueue()
{
    // node creation
    struct nodeStruct *newnode, *temp;
    newnode = (struct nodeStruct *)malloc(sizeof(struct nodeStruct));
    newnode->link = NULL;
    printf("\nEnter the data==>\n");
    scanf("%d", &newnode->data);
    if (front == NULL && rear == NULL)
    {
        front = newnode;
        rear = newnode;
        printf("\nNode is added successfuly\n");
    }
    else
    {
        // temp = rear;
        rear->link = newnode;
        rear = newnode;
        printf("\nNode is added successfuly\n");
    }
}

struct nodeStruct *dequeue()
{
    struct nodeStruct *temp = front;

    if (front == NULL && rear == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else if (front == rear) // this else if will work when we have only one element in my list and  we want to delete that item from the list
    {

        printf("Front value before delete==>%d", front->data);
        front = NULL;
        rear = NULL;
    }
    else
    {
        printf("Front value before delete==>%d", front->data);
        front = front->link;
    }
};

void display()
{
    struct nodeStruct *temp, *i;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("LIST IS EMPTY");
        return;
    }

    printf("\n front==>%d\n", front->data);
    printf("\nrear==>%d\n", rear->data);

    for (i = temp; i != NULL; i = i->link)
    {
        printf("\nData==>%d", i->data);
        temp = temp->link;
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
            enqueue();
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