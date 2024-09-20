#include<stdio.h>
#include<stdlib.h>
struct Stack_Store_LL
{
    int data;
    struct Stack_Store_LL* next;
};

struct Stack_Store_LL* top = 0; // 0 means top is not pointing any node .. so stack is empty till now ...

void push(){
     struct Stack_Store_LL* newNode=( struct Stack_Store_LL* )malloc(sizeof (struct Stack_Store_LL));
     if(newNode==NULL){
        printf("Memory has not created!!! \n");
     }
     printf("Entert the data==>");
     scanf("%d",&newNode->data);
     newNode->next=top;
     top=newNode;
}
void pop(){

        printf("Top==>%d\n",top->data);
    if(top==0){
        printf("Stack is empty!!! \n");
    }else{
        struct Stack_Store_LL* temp=top;
        top=top->next;
        printf("Poped element==>%d\t",temp->data);
        
    }
}

// Function to display the top element of the stack
void peek() {
    if (top == 0) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void displayStack(){
   if (top == NULL) {
        printf("Stack is empty\n");
    } else {
         struct Stack_Store_LL* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    } 
}

int main(){
    int ch ;
    while(1){
        printf("\n\nStack Operations using linkedlist\n\n");
        printf(
        "1. Push the element inside the stack \n"
        "2. Remove the top element from  the stack\n"
        "3. Show the top element from  the stack\n"
        "4. Display whole  the stack\n"
        "5. Close the program\n"
        );
        printf("\nEnter the choice==>");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();// This is used to push the element to stack
                break;
            case 2:
                pop();// This is used to pop the top element from stack
                break;
            case 3:
                peek();//This is used to display the top element
                break;
            case 4:
                 displayStack();//Display all the stack
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice");
        }
    }
}