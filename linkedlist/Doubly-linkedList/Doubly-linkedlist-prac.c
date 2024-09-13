#include<stdio.h>
#include<stdlib.h>
struct  dll
{
    int movieId;
    char movieName[50];
    float ratings;
    struct dll *next;
    struct dll *prev;
} *tail;

/* node creation */
struct dll* nodeCreation(struct dll* head){
    struct dll* newNode;
    float rating;
    newNode=(struct dll*)malloc(sizeof(struct dll));
    newNode->next=NULL;
    newNode->prev=NULL;
    printf("\nEnter the movieId==> \t");
    scanf("%d",&newNode->movieId);
    printf("\nEnter the movieName==> \t");
    scanf("%s",&newNode->movieName);
    
    printf("\nEnter the ratings==> \t");
    scanf("%2f",&rating);
    if(rating<=5){
    // printf("%f",rating);
    newNode->ratings=rating;
    }else{
        printf("\nPlease provied Rating between between 0 to 5\n");
    }
    
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else
    {
        struct dll* temp=head;
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
/* traversing the list */
void traverseList(struct dll* head){
struct dll* temp=head;
printf("Movie Details==>\n");
while (temp!=NULL){
    printf("Movie id==> %d  \t ",temp->movieId);
    printf("Movie name==> %s \t",temp->movieName);
    printf("Movie ratings=> %.2f  \t",temp->ratings);
    printf("\n");
    temp=temp->next;
}
/* printf("Null");
printf("\n======================================\n");
printf("backward traversing\n");
printf("NULL\t"); */
// Use a temporary pointer to traverse backward, leaving `tail` unchanged
/*     struct dll* tempTail = tail;
while (tempTail!=NULL){
    printf("%d\t",tempTail->data);
    tempTail=tempTail->prev;
}
printf("NULL");
printf("\nHead data==> %d",head->data);
printf("\n tail data==> %d",tail->data); */

}
/* add the node at front */
/* struct dll* insertAtFront(struct dll* head){
    struct dll* newNode , *temp;
    if(head==NULL){
        nodeCreation(head);
    }else{
        newNode=(struct dll*)malloc(sizeof(struct dll));
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
} */
/* get the length of the list */
/* int getLength(struct dll* head){
    int length=0;
    struct dll* temp=head;
    while (temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;

} */
/* add the node at given position */
/* struct dll* insertInGivenPosition(struct dll* head){
    struct dll* newNode , *temp;
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
            newNode=(struct dll*)malloc(sizeof(struct dll));
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
} */
/* Add the node at the end */
/* struct dll* insertAtEnd(struct dll* head){
    if(head==NULL){
        nodeCreation(head);
    }else{
        struct dll* newNode;
        newNode=(struct dll*)malloc(sizeof(struct dll));
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
} */
/* findind the elements */
/* int findElement(struct dll* head){
    int key;
    struct dll* temp;
    printf("\nEnter the element you want to find==> \t");
    scanf("%d",&key);
    if(head==NULL){
        printf("List is empty");
    }else{
        temp=head;
        // key is found in head node
        if(key==temp->data){
            printf("\nElement found in the head and searched element is %d\n",temp->data);
             return 1;
        } 
        else {
            while (temp!=NULL)
            {                
                if(temp->data==key){
                    printf("\nElement found in the list and searched element is %d\n",temp->data);
                   break;
                }
                temp=temp->next;
            }
            // After the last node if temp = null that means we did not find the element in the list..
            if (temp==NULL)
            {
                printf("\nElement not found in the list!!!!\n");
            }
                    
        }
        
    }
    
} */
/* Search movie details by their id */
int findElement(struct dll* head){
    int searchId;
    struct dll* temp;
    printf("\nEnter the element you want to find==> \t");
    scanf("%d",&searchId);
    if(head==NULL){
        printf("List is empty");
    }else{
        temp=head;
        // key is found in head node
        if(searchId==temp->movieId){
            printf("\nElement found in the head and searched element is %s",temp->movieName);
             return 1;
        } 
        else {
            while (temp!=NULL)
            {                
                if(temp->movieId==searchId){
                    printf("\nElement found in the list and searched element is %s \n",temp->movieName);
                   break;
                }
                temp=temp->next;
            }
            // After the last node if temp = null that means we did not find the element in the list..
            if (temp==NULL)
            {
                printf("\nElement not found in the list!!!!\n");
            }
                    
        }
        
    }
    
} 

/* Lab=> find movie by their ratings */
void findBestMovie(struct dll* head){

    struct dll* temp=head;
        printf("\nWow!!!! You choosed best movies from our list\n");
    while (temp!=NULL)
    {     
    if(temp->ratings>=4 && temp->ratings<=5){
        printf("\nMovie Id: %d",temp->movieId);
        printf("\nMovie Name: %s",temp->movieName);
        printf("\nMovie Ratings: %.2f\n",temp->ratings);

    }
    temp=temp->next;
    }
    

}
int main(){
    struct dll *head = NULL;
    int ch;   
    while (1)
    {
        printf("\nDOUBLY LINKED LIST\n");
        printf("\n1.Insert\n2.Traverse\n3.Insert at start\n4.Insert at given Position\n5.Insert at end\n6.Search a perticuler data\n7.Find movie which is between 4 to 5 ratings\n8.Exit");
        printf("\n====================================");
        printf("\nEnter the choice==>");
        scanf("%d",&ch);
        if(ch==1){
            head=nodeCreation(head);
        }else if(ch==2){
            traverseList(head);
        }else if(ch==3){
          
            //head = insertAtFront(head); // here  we store newNode address in left side of head variable ..
           
        }else if(ch==4){
            
            //head = insertInGivenPosition(head); 
        }else if(ch==5){
            
            //head = insertAtEnd(head); 
        }
        else if(ch==6){
            
             findElement(head); 
        }
        else if(ch==7){
           findBestMovie(head); 
        }
        else if(ch==8){
            break;
        }
        else{
            printf("Invalid choice");
        }        
    }  
}