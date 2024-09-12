#include<stdio.h>
#include<stdlib.h>


struct  Doubly_linkedlist_prac
{
    int data;
    struct Doubly_linkedlist_prac *next;
    struct Doubly_linkedlist_prac *prev;
} *tail;

struct Doubly_linkedlist_prac* nodeCreation(struct Doubly_linkedlist_prac* head){
    struct Doubly_linkedlist_prac* newNode;
    newNode=(struct Doubly_linkedlist_prac*)malloc(sizeof(struct Doubly_linkedlist_prac));
    newNode->next=NULL;
    newNode->prev=NULL;
    printf("\nEnter the data==> \n");
    scanf("%d",&newNode->data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else
    {
        struct Doubly_linkedlist_prac* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        tail=newNode;
    }    
    return head;
}

void traverseList(struct Doubly_linkedlist_prac* head){
struct Doubly_linkedlist_prac* temp=head;
printf("Null\t");
while (temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
}
printf("Null");
printf("\n======================================\n");
printf("backward traversing\n");
printf("NULL\t");
// Use a temporary pointer to traverse backward, leaving `tail` unchanged
    struct Doubly_linkedlist_prac* tempTail = tail;
while (tempTail!=NULL){
    printf("%d\t",tempTail->data);
    tempTail=tempTail->prev;
}
printf("NULL");
printf("\nHead data==> %d",head->data);
printf("\n tail data==> %d",tail->data);

}

struct Doubly_linkedlist_prac* insertAtFront(struct Doubly_linkedlist_prac* head){
    struct Doubly_linkedlist_prac* newNode , *temp;
    if(head==NULL){
        nodeCreation(head);
    }else{
        newNode=(struct Doubly_linkedlist_prac*)malloc(sizeof(struct Doubly_linkedlist_prac));
        newNode->prev=NULL;
        newNode->next=NULL;
        printf("\nEnter the data\n");
        scanf("%d",&newNode->data);
        temp=head;
       newNode->next=temp;
       temp->prev=newNode;
       head=newNode;        
    }
    printf("Node is successfuly added to the front");
    return head;
}
int getLength(struct Doubly_linkedlist_prac* head){
    int length=0;
    struct Doubly_linkedlist_prac* temp=head;
    while (temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;

}
struct Doubly_linkedlist_prac* insertInGivenPosition(struct Doubly_linkedlist_prac* head){
    struct Doubly_linkedlist_prac* newNode , *temp;
    int position,i=1;
    int len=getLength(head);
    if(head==NULL){
        nodeCreation(head);
    }else{
        printf("Enter the posistion==>");
        scanf("%d",&position);
        if(position>i && position<len){
            temp=head;
            while (position>i){
                temp=temp->next;
                i++;
            }
            newNode=(struct Doubly_linkedlist_prac*)malloc(sizeof(struct Doubly_linkedlist_prac));
            newNode->prev=NULL;
            newNode->next=NULL;
            printf("\nEnter the data\n");
            scanf("%d",&newNode->data);
            newNode->next=temp->prev->next;
            newNode->prev=temp->prev;
            temp->prev->next=newNode;
            temp->prev=newNode;            
        }else{
            printf("Invalid position");
        }
        
    }
    printf("Node is successfuly added to the perticular position");
    return head;
}

struct Doubly_linkedlist_prac* insertAtEnd(struct Doubly_linkedlist_prac* head){
    if(head==NULL){
        nodeCreation(head);
    }else{
        struct Doubly_linkedlist_prac* newNode;
        newNode=(struct Doubly_linkedlist_prac*)malloc(sizeof(struct Doubly_linkedlist_prac));
        newNode->next=NULL;
        newNode->prev=NULL;
        printf("\nEnter the data==>\n");
        scanf("%d",&newNode->data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;// update the tail pointer

    }
    printf("Node is successfuly added to the end of the list");

    return head;
}
int main(){
    struct Doubly_linkedlist_prac *head = NULL;
    int ch;
    

    while (1)
    {
        printf("\nDOUBLY LINKED LIST\n");
        printf("\n1.Insert\n2.Traverse\n3.Insert at start\n4.Insert at given Position\n5.Insert at end\n6.Exit");
        printf("\n====================================");
        printf("\nEnter the choice==>");
        scanf("%d",&ch);
        if(ch==1){
            head=nodeCreation(head);
        }else if(ch==2){
            traverseList(head);
        }else if(ch==3){
          
            head = insertAtFront(head); // here  we store newNode address in left side of head variable ..
           
        }else if(ch==4){
            
            head = insertInGivenPosition(head); 
        }else if(ch==5){
            
            head = insertAtEnd(head); 
        }
        else if(ch==6){
            break;
        }else{
            printf("Invalid choice");
        }
        
    }
    

}