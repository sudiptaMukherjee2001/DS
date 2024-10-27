#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

struct binaryTreeNode *createNode()
{
    int x;
    char ch;
    struct binaryTreeNode *newNode = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
    printf("\nEnter the data=>");
    scanf("%d", &newNode->data);
    newNode->left = 0;
    newNode->right = 0;
printf("\nIf you do not want create any further node then press  :=>-1\n
        If you want to create any further node then press :=> 1\t");
scanf("%d",&x);
if(x==-1){
        return newNode;
}else{
    printf("\nIf you want to add to the left then press  :=>L\n
        If you want to add to the Right then press :=>R\n       
        ");
    scanf("%c",&ch);
    switch (ch)
    {
        case 'L':
            newNode->left = createNode();
            break;
        case 'R':
            newNode->right = createNode();
            break;
        // case "E":
        //     return newNode;
        default:
            printf("\nInvalid choice");
            break;
    }
}
return newNode;
}

void main()
{

    struct binaryTreeNode *root = 0;
    while (1)
    {
        printf("\n1.create and insert the node\n 2.pre-Order traversal\n 3.post-Order traversal \n 4.In-Order traversal\n5.Exit");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = createNode();
            break;
        case 2:
            // preOrderTraversal(root);
            break;
        case 3:
            // postOrderTraversal(root);
            break;
        case 4:
            // inOrderTraversal(root);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

/* If you want to stop the node creation prees (E) for exit */