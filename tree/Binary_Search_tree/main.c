/* not pushed because delete func is not working */
#include <stdio.h>
#include <stdlib.h>

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
} *root;

struct binaryTreeNode *createInsertNode(struct binaryTreeNode *root, int data)
{

    if (root == NULL)
    {
        root = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    else
    {
        // Insert data according to BST rules
        if (data < root->data)
        {
            root->left = createInsertNode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = createInsertNode(root->right, data);
        }
        else
        {
            printf("Duplicate values are not allowed in this BST.\n");
        }
    }

    return root;
}

void searchKey(struct binaryTreeNode *root, int searchData)
{
    if (root == NULL)
    {
        printf("Key not found in the tree.\n");
    }
    else if (root->data == searchData)
    {
        printf("\nKey found in the tree %d\n", searchData);
    }
    else if (searchData < root->data)
    {
        searchKey(root->left, searchData);
    }
    else if (searchData > root->data)
    {
        searchKey(root->right, searchData);
    }
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
/* struct binaryTreeNode *FindMinEle(struct binaryTreeNode *root)
{
    if (root == NULL)
    {
        return root;
    }
    FindLargestEle(root->left);
}
struct binaryTreeNode *helper(struct binaryTreeNode *root)
{
    struct binaryTreeNode *leftChild = root->left;
    struct binaryTreeNode *lastRightChild = FindLargestEle(leftChild->right);
    lastRightChild->left = leftChild;
    lastRightChild->right = root->right;
    return lastRightChild;
} */

/* struct binaryTreeNode *deleteNode(struct binaryTreeNode *root, int Delete_data)
{
    if (Delete_data < root->data)
    {
        if (Delete_data == root->left->data)
        {
            root->left = helper(root->left);
        }
        else
        {
            root = root->left;
        }
    }
    return root;
} */

int main()
{

    root = NULL;
    while (1)
    {
        printf("\n1.create and insert the node\n 2.pre-Order traversal\n 3.post-Order traversal \n 4.In-Order traversal\n5.Delete node\n6.Exit\n");
        int choice;
        int data, searchData;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data==>\n");
            scanf("%d", &data);
            root = createInsertNode(root, data);
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
            printf("\nEnter the search key=>\n");
            scanf("%d", &searchData);
            searchKey(root, searchData);
            /* printf("\n Delete node==>\n");
            printf("\nwhat data you want to delete==>\n");
            scanf("%d", &deleteData);
            deleteNode(root, deleteData); */
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

/* If you want to stop the node creation prees (E) for exit */
