#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
} *root;

struct binaryTreeNode *createInsertNode(struct binaryTreeNode *root)
{
    char ch;
    if (root == NULL)
    {
        root = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
        root->left = NULL;
        root->right = NULL;
        printf("\nEnter the data==>\n");
        scanf("%d", &root->data);
        return root;
    }
    else
    {
        printf("\nWrite L for left node insert of data %d\n", root->data);
        printf("\nWrite R for right node insert %d\n", root->data);
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'l':

            root->left = createInsertNode(root->left);
            break;
        case 'r':

            root->right = createInsertNode(root->right);
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }

    return root;
}

void preOrderTraversal(struct binaryTreeNode *root)
{

    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(struct binaryTreeNode *root)
{

    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}
void postOrderTraversal(struct binaryTreeNode *root)
{

    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{

    root = NULL;
    while (1)
    {
        printf("\n1.create and insert the node\n 2.pre-Order traversal\n 3.post-Order traversal \n 4.In-Order traversal\n5.Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = createInsertNode(root);
            break;
        case 2:
            printf("\n PreOrderTraversal==>\n");

            preOrderTraversal(root);
            break;
        case 3:
            printf("\n PostOrderTraversal==>\n");

            postOrderTraversal(root);
            break;
        case 4:
            printf("\n InOrderTraversal==>\n");

            inOrderTraversal(root);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

/* If you want to stop the node creation prees (E) for exit */