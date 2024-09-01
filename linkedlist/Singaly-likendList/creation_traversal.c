#include <stdio.h>
#include <stdlib.h>

/* STRUCTURE CREATION */
struct creation_traversal_Node
{
    int data;
    struct creation_traversal_Node* link;
};

struct creation_traversal_Node* creationOfNode(struct creation_traversal_Node* head){
    struct creation_traversal_Node *newNodePtr,*temp;
   
    /* allocate the memory address for node */
   newNodePtr=(struct creation_traversal_Node*)malloc(sizeof(struct creation_traversal_Node));

   newNodePtr->link=NULL;

   printf("Enter the data ==>");
   scanf("%d",&newNodePtr->data);// gets inpout from the user..
   if(head==NULL){
    head=newNodePtr; // we store the address of newNodePtr to head; 
   
   }else{
    temp=head; 
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newNodePtr; // here in the temp->link we store the newNode Address

   }
   return head;  // head return a address
   
}

void traverseList(struct creation_traversal_Node* head){
    struct creation_traversal_Node* temp;
    temp=head;
    if(temp==NULL){
        printf("List is empty");
    }else{
        printf("head data==>%d",head->data);  

        printf("\n===================================\n");    

        printf("List data==>\n");        
        
        while (temp !=NULL){
        printf("%d \t",temp->data); // prints the data of the node
        temp=temp->link;
        }
        printf("Null");        
    }

}

int main(){
    int ch;
    struct creation_traversal_Node* head = NULL;
    while (1){
    printf("\n1.Add the node");
    printf("\n2.Traverse the list");
    printf("\n3.Exit");
    printf("\n====================================");
    printf("\nEnter the choice==>");
    scanf("%d",&ch);
    if (ch==1){
        head=creationOfNode(head); // this head contain address of starting node       
    }
    else if (ch==2){
        traverseList(head);     
    }
    else if(ch==3){
        break;
    }
    }
    
    

}