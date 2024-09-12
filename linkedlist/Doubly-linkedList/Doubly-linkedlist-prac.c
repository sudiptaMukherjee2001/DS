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
while (tail!=NULL){
    printf("%d\t",tail->data);
    tail=tail->prev;
}
printf("NULL");
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
          
            // head = insertAtFront(head); // here  we store newNode address in left side of head variable ..
           
        }else if(ch==4){
            
            // head = insertInGivenPosition(head); 
        }else if(ch==5){
            "hi";
            // head = insertEnd(head); 
        }
        else if(ch==6){
            break;
        }else{
            printf("Invalid choice");
        }
        
    }
    

}