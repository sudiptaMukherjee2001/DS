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
    printf("Enter the data ==>");
    scanf("%d",&newNode->data);
    temp=head;
    if(head!=NULL){
        newNode->link=temp; // storing the head node address in the place of newNode Link and We estabhlish a link or connection between newNode with previous head node ..
        temp=newNode;// store newNode address to the temp  variable
    }else{
        printf("List is empty .. Please create a list is ==>");
    }
       
    printf("After Insert new node==>\n");
    head=temp;

    while (temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->link;
    }
    printf("Null");           
    printf("\nthis is head data inside func %d\t",head->data);
    // printf("\ninside insert function ==> %d",head->data);
    printf("\n");
    return head; // retrun the newNode address which is added at the front

}
/* Code to get the lenght of the linked-list */
int getLength(struct InstertionOp* head) {
    int length=0;
    struct InstertionOp* current=head;
    while (current!=NULL)
    {
        length++;
        current=current->link;
    }
    return length; 

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



/* Insert at given position */
struct InstertionOp* insertAtPerticularPosition(struct InstertionOp* head){
    struct InstertionOp* newNode , *temp;
    int pos,length,i=1;
    length=getLength(head);
    printf("Enter the position where you want to insert the data ==> ");
    scanf("%d",&pos);
    if(pos==1){
        return insertAtFront( head);
    }else if(pos>1 && pos<length){
        newNode=(struct InstertionOp* )malloc(sizeof(struct InstertionOp));
        temp=head;//100 in temp
        printf("\nEnter the data==>");
        scanf("%d",&newNode->data);
        while (pos>i)//1.2>1 || 2. 2>2 false
        {
           
            temp=temp->link;// 200 in temp
            i++;//i is incremented to 2

        }
           
        // temp=200 now
        newNode->link=temp->link;
        temp->link=newNode;
        
    }else
    {
        printf("\nInvalid position\n");
    }
     printf("\n");
    
    
    traverseList(head);
    
}


int main() {
    struct InstertionOp* head = NULL;
    struct InstertionOp* temp;
    int ch;
    while (1){
        printf("\n1.Insert\n2.Traverse\n3.Insert at start\n4.Insert at given Position\n5.Insert at end\n6.Exit");
        printf("\n====================================");
        printf("\nEnter the choice==>");
        scanf("%d",&ch);
        if(ch==1){
            head=nodeCreation(head);
        }else if(ch==2){
            traverseList(head);
        }else if(ch==3){
            insertAtFront(head); // here  we store newNode address in left side of head variable ..
           
        }else if(ch==4){
            insertAtPerticularPosition(head);
            
        }else if(ch==6){
            break;
        }else{
            printf("Invalid choice");
        }
        
    }
    
  
}
