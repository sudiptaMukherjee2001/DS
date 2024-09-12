#include <stdio.h>
#include <stdlib.h>


struct doubly_linkedList
{
    int data;
    struct doubly_linkedList* prev;
    struct doubly_linkedList* next;
};

struct doubly_linkedList* nodeCreation(struct doubly_linkedList* head){
    struct doubly_linkedList *newNode, *temp;
    newNode=(struct doubly_linkedList*)malloc(sizeof(struct doubly_linkedList));
    newNode->prev=NULL;
    newNode->next=NULL;
  printf("Enter the data==>");
scanf("%d",&newNode->data);
    if(head==NULL){
        head=newNode;
        
      
        
    }else{
       temp=head;
       while (temp->next != NULL){
        temp=temp->next;
       }
       
        temp->next=newNode;
        newNode->prev=temp;
      
     
       
    }
    return head;

}
void traverseList(struct doubly_linkedList* head){
    struct doubly_linkedList *temp, *tail;
    temp = head ;
    printf("\nhead data==>%d\n",head->data);
    printf("\nForward  traversing \n");
    printf("List==>\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        tail=temp;
        temp=temp->next;

    }   
    printf("NUll");
    printf("\n=====================================\n");
    printf("\n backward traversing \n");
    printf("List==>");
    while(tail!=NULL){
        printf("%d\t",tail->data);
        tail=tail->prev;
    }   
    printf("NUll");

}

struct doubly_linkedList* insertAtFront(struct doubly_linkedList* head){
    struct doubly_linkedList* newNode;
    newNode=(struct doubly_linkedList*)malloc(sizeof(struct doubly_linkedList));
    newNode->prev=NULL;
    newNode->next=NULL;
    printf("Enter the data==>");
    scanf("%d",&newNode->data);
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
    if(head->prev==NULL){
        printf("New Node insterted successfuly at first");
    }
    return head;
}

int getLength(struct doubly_linkedList* head){
    int length=0;
    struct doubly_linkedList* temp=head;
    while (temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;

}

/* Insert at given position */
struct doubly_linkedList* insertInGivenPosition(struct doubly_linkedList* head){
    struct doubly_linkedList* newNode , *temp;
    int position ;
    int i=1;
   printf("Enter the position where you want to insert the data ==> ");
    scanf("%d",&position);
    int length= getLength(head);
    if(position == 1 && position >length){
        insertAtFront(head);

    }
    else if(position>1 && position < length){
          newNode=(struct doubly_linkedList* )malloc(sizeof(struct doubly_linkedList));
            temp=head;
           printf("\nEnter the data==>");
        scanf("%d",&newNode->data);
        while (position>i && i<length )
        {
           temp=temp->next;
           i++;
        }
        temp->prev->next=newNode;
        newNode->prev=temp->prev;
        newNode->next=temp;
        temp->prev=newNode;

    }
    else{
        printf("Invalid position");
    }
    return head;

}

int main(){
    int ch;
        struct doubly_linkedList *head;
        head=NULL;

     while (1){
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