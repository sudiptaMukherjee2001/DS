#include <stdio.h>
#include <stdlib.h>

struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
} *head , *tail;
struct circularLinkedList* CclNodeCreation(struct circularLinkedList* head){
    struct circularLinkedList* newNode , *temp;
    newNode = (struct circularLinkedList*)malloc(sizeof(struct circularLinkedList));
    printf("\nEnter the data\n");
    scanf("%d",&newNode->data);
    if(head==0){
        head=newNode;
        tail=newNode;
        head->next= head;

    }else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
           temp->next=newNode;
            newNode->next=head;
           tail=newNode;
    }
    return head;
}
void traverseList(struct circularLinkedList* head ){
    struct circularLinkedList* temp = head ;
    printf("\nList of Ciculer linked list==>\t ");
  
     while (temp->next != head) {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
        printf("%d \t", temp->data); // temp in last node
        printf("\ntail%d \n\t", tail->data); // temp in last node
              
}

int main(){
    int ch;

       
        head=0;

     while (1){
        printf("\n Circuler LINKED LIST\n");
        printf("\n1.Insert\n2.Traverse\n3.Insert at start\n4.Insert at given Position\n5.Insert at end\n6.Exit");
        printf("\n====================================");
        printf("\nEnter the choice==>");
        scanf("%d",&ch);
        if(ch==1){
            head=CclNodeCreation(head );
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