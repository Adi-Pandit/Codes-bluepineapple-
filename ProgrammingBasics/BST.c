#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left, *right;
};

struct node *NewNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}

struct node *Insert(struct node *node, int data)
{
    if(node==NULL)
        return NewNode(data);
    if(data < node->data)
        node->left = Insert(node->left,data);
    else
        node->right = Insert(node->right,data);
    return node;
}

struct node *MinValueNode(struct node *node)
{
    struct node *current = node;
    if(current && current->left!=NULL)
        current =  current->left;
    return current;
}

struct node *deleteNode(struct node *root, int data) 
{
    if(root == NULL) 
        return root;

    if(data < root-> data)
        root->left = deleteNode(root->left, data);
    else if(data > root-> data)
        root->right = deleteNode(root->right, data);
    else 
    {
        if (root->left == NULL) 
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = MinValueNode(root->right);
        root-> data = temp-> data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    root = Insert(root, 8);
    root = Insert(root, 3);
    root = Insert(root, 1);
    root = Insert(root, 6);
    root = Insert(root, 7);
    root = Insert(root, 10);
    root = Insert(root, 14);
    root = Insert(root, 4);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("Inorder traversal: ");
    inorder(root);
}
