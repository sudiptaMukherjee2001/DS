#include <stdio.h>
#include <stdlib.h>

struct ddlPrac
{
    int data;
    struct ddlPrac *prev;
    struct ddlPrac *next;
};

/* This func is responsible for creating the node and added to the linked list */
struct ddlPrac *nodeCreation(struct ddlPrac *head)
{
    struct ddlPrac *newNode = (struct ddlPrac *)malloc(sizeof(struct ddlPrac));
    struct ddlPrac *temp;
    newNode->prev = NULL;
    newNode->next = NULL;

    printf("Enter the data==>");
    scanf("%d", &newNode->data);
    temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        /*
        Here temp -> next because  if i use only temp then at the end temp will hold null ..Because if my
        last node address is 200 and temp(200) != null (true) then loop will execute and last node next field will point to  null and
        then temp will hold null .. If my temp hold null then i do not have the access of last node..
        To solve this problem i use temp->next != null
        */
        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
    return head;
}
struct ddlPrac *insertAtStart(struct ddlPrac *head)
{
    struct ddlPrac *newNode = (struct ddlPrac *)malloc(sizeof(struct ddlPrac));
    struct ddlPrac *temp;
    newNode->prev = NULL;
    newNode->next = NULL;

    printf("Enter the data==>");
    scanf("%d", &newNode->data);
    temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
    }
    return head;
}
void traverseList(struct ddlPrac *head)
{
    printf("\nhead data==>%d\n", head->data);
    struct ddlPrac *temp = head;
    while (temp != NULL)
    {
        printf("\nList==>\t");
        printf("%d", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct ddlPrac *head = NULL;

    while (1)
    {
        int exp;
        printf(
            "\n1. Node create \n"
            "2. insert at the start\n"
            "3. insert at the given position\n"
            "4. insert at the end\n"
            "5. display the  linked list\n"
            "6. close the program\n");
        printf("Enter your choice==>");
        scanf("%d", &exp);
        switch (exp)
        {
        case 1:
            head = nodeCreation(head);
            break;
        case 2:
            head = insertAtStart(head);
            break;
        case 3:
            // head = insertAtPosition(head);
            break;
        case 5:
            traverseList(head);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice");
        }
    }
}