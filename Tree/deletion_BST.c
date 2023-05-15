#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node * n;
    n = (struct node*)malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node * inOrderPredecessor(struct node * root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

void inOrder(struct node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d\t",root->data);
        inOrder(root->right);
    }
}

struct node * deleteNode(struct node * root, int value)
{
    struct node * iPre;
    if(root == NULL)
        return NULL;

    else if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    else if(root->data > value)
        root->left = deleteNode(root->left,value);

    else if(root->data < value)
        root->right = deleteNode(root->right,value);
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
}

int main()
{
    struct node* p = createNode(5);
    struct node* p1 = createNode(3);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(1);
    struct node* p4 = createNode(4);

    // Linking Code
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Before Deletion : \n");
    inOrder(p);
    deleteNode(p,5);
    printf("\nAfter Deletion : \n");
    inOrder(p);
    printf("\nData is %d ",p->data);

    return 0;
}