#include <stdio.h>
#include<stdlib.h>

/* Create a sturcture */
struct InstertionOp
{
    int data;
   struct InstertionOp* link;
};

struct InstertionOp* nodeCreation(struct InstertionOp* head){ // head will contain the address

struct InstertionOp *newNode , *temp;
newNode=(struct InstertionOp*)malloc(sizeof(struct InstertionOp));
newNode->link=NULL;
printf("Enter the data==>");
scanf("%d",&newNode->data);

if(head==NULL){
    head=newNode;
}else{
temp=head;
// traversing to the end of the list
while (temp->link!= NULL){
    temp=temp->link;
}
temp->link=newNode;
}
return head;

}



struct InstertionOp*  insertAtFront(struct InstertionOp* head ){
    struct InstertionOp* newNode;
    struct InstertionOp* temp;
    newNode=(struct InstertionOp*)malloc(sizeof(struct InstertionOp));
    newNode->link=NULL;
    printf("Enter the data==>");
    scanf("%d",&newNode->data);
    temp=head;
    if(head!=NULL){
        newNode->link=temp;
        temp=newNode;
    }else{
        printf("List is empty .. Please create a list is ==>");
    }
    head=temp;
    printf("\ninside insert function ==> %d",head->data);
    printf("\n");
    return head;

}

void traverseList(struct InstertionOp* head ){
    struct InstertionOp* temp;
    temp=head;
    printf("\nList data==>\n");
    while (temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;        
    }
    printf("Null");
    
}


int main() {
    struct InstertionOp* head = NULL;
    struct InstertionOp* temp;
    int ch;
    while (1){
        printf("\n1.Insert\n2.Traverse\n3.Insert at start\n4.Insert at middel\n5.Insert at end\n6.Exit");
        printf("\n====================================");
        printf("\nEnter the choice==>");
        scanf("%d",&ch);
        if(ch==1){
            head=nodeCreation(head);
        }else if(ch==2){
            traverseList(head);
        }else if(ch==3){
            head =insertAtFront(head); // here  we store newNode address in left side of head variable ..
            temp=head;
            printf("Insert list==>\n");

           while (temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->link;
           }
            printf("Null");           
            printf("\nthis is head data %d\t",head->data);
        }else if(ch==6){
            break;
        }else{
            printf("Invalid choice");
        }
        
    }
    
  
}
