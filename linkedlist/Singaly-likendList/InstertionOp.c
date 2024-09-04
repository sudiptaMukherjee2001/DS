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



struct InstertionOp*  insertAtFront(struct InstertionOp* head ){
    struct InstertionOp* newNode;
    struct InstertionOp* temp;
    newNode=(struct InstertionOp*)malloc(sizeof(struct InstertionOp));
    newNode->link=NULL;
    printf("Enter the data ==>");
    scanf("%d",&newNode->data);
    
    if(head!=NULL){
        newNode->link=head; // storing the head node address in the place of newNode Link and We estabhlish a link or connection between newNode with previous head node ..
        head=newNode;// store newNode address to the temp  variable
    }else{
        printf("List is empty .. Please create a list is ==>");
    }
       
    printf("After Insert new node==>\n");


    traverseList(head);
    return head;

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




/* Insert at given position */
struct InstertionOp* insertInGivenPosition(struct InstertionOp* head){
    struct InstertionOp* newNode , *temp;
    int pos,length,i=1;
    length=getLength(head);
    printf("\nlength of linked list %d\n",length);
    printf("Enter the position where you want to insert the data ==> ");
    scanf("%d",&pos);
    if(pos==1){
        return insertAtFront( head);
    }else if(pos>1 && pos<=length){
        newNode=(struct InstertionOp* )malloc(sizeof(struct InstertionOp));
        temp=head;
        printf("\nEnter the data==>");
        scanf("%d",&newNode->data);
        while (pos-1>i && i<length )
        {
           
            temp=temp->link;
            i++;

        }

           
       
        newNode->link=temp->link;
        temp->link=newNode;
        
    }
    else
    {
        printf("\nInvalid position\n");
    }
     printf("\n");
    
    
    traverseList(head);
    return head;
    
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
             head = insertAtFront(head); // here  we store newNode address in left side of head variable ..
           
        }else if(ch==4){
            head = insertInGivenPosition(head); 
        }else if(ch==6){
            break;
        }else{
            printf("Invalid choice");
        }
        
    }
    
  
}
