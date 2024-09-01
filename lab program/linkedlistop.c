#include <stdio.h>
#include <stdlib.h>  // For malloc

struct Node {
    int sid;
    float cgpa;
    struct Node *link;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode() {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;  // Return NULL if memory allocation fails
    }
    
    printf("Enter the sid: ");
    scanf("%d", &newNode->sid);
    printf("Enter the cgpa(below 10): ");
    scanf("%f", &newNode->cgpa);

    if(newNode->cgpa <= 10){
    return newNode;    
    newNode->link = NULL;
    }
    else{
        printf("\nPlease give cgpa below 10");
        return NULL;
    }
    
}
int IsEmpty(){
    return head == NULL;
}

int findNode(){
    struct Node *temp;
    int i, findKey;
    temp = head;
    i = 0;
    printf("Enter the key to search: ");
    scanf("%d", &findKey);
    while (temp != NULL) {
        if(temp->sid == findKey) {
            printf("sid is:  ==> %d, \n cgpa ==> %.2f\n", temp->sid, temp->cgpa);
            return 0;
        } else {
            temp = temp->link;
            i++;
        }
    }
    printf("Key is not present in the list\n");
    return -1;
}

int displayFullList(){
    struct Node *temp;
}

int main() {
    int ch;
    
    while (1) {
        printf("\n\n1. Add elements  \n2. Display the List \n3. Check if List is Empty \n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        
        if (ch == 1) {
            struct Node *newNode = createNode();
            if (newNode == NULL) {
                continue; 
            }
            newNode->link = head;
            head = newNode;
        } else if (ch == 2) {
            findNode();
        } else if (ch == 3) {
            if (IsEmpty()) {
                printf("\nThe list is empty.\n");
            } else {
                printf("\nThe list is not empty.\n");
            }
        } else if (ch == 4) {
            break;
        } else {
            printf("\nInvalid ch. Please try again.\n");
        }
    }
    
    // Free the list
    while (head != NULL) {
        struct Node *temp = head;
        head = head->link;
        free(temp);
    }
    
    return 0;
}