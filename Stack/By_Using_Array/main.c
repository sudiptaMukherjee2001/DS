#include<stdio.h>
#define SIZE 5
int top = -1; //top is just a value and here it is work as index
int stack[SIZE];


void push(){
    //First check if stack is full or empty
    if(top==SIZE-1){
        printf("Stack is full\n");
        return;
    }else{
        //Increse the top value first;
        top++;
        int value;
        printf("Enter the value that you want to push==>");
        scanf("%d",&value);
        stack[top]=value;
        printf("Your inserted value is ==>%d",stack[top]);
    }
}

void pop(){
    //First check if stack is empty
    if(top==-1){
        printf("Stack is empty alredy!!!\n");
    }else{
        int poped_item;
        poped_item = stack[top];
        top--;
        printf("Popped item is ==>%d\n",poped_item);
    }
}
void peek(){
    //First check if stack is empty
    if(top==-1){
        printf("Stack is empty alredy!!!\n");
    }else{
        int peeked_Item;
        peeked_Item = stack[top];
        printf("peeked Item  is ==>%d\n",peeked_Item);
    }
}



void displayStack(){
    //Check stack is empty or not 
    if(top==-1){
        printf("Stack is empty\n");
    }else{
        int i;
        printf("Stack element==>\t");
        for(i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
    }

}


int main(){
    int ch ;
    while(1){
        printf("\n\nStack Operations\n\n");
        printf(
        "1. Push the element inside the stack \n"
        "2. Remove the top element from  the stack\n"
        "3. Show the top element from  the stack\n"
        "4. Display whole  the stack\n"
        "5. Close the program\n"
        );
        printf("Enter the choice==>");
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