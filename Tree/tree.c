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

void preOrder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d\t",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t",root->data);
    }
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

int main()
{
    struct node* p = createNode(4);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(5);
    struct node* p4 = createNode(2);

    // Linking Code
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Here PreOrder : \n");
    preOrder(p);
    printf("\nHere PostOrder : \n");
    postOrder(p);
    printf("\nHere InOrder : \n");
    inOrder(p);

    return 0;
}