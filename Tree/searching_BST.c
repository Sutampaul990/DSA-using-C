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
//Through Recursion
struct node * searchingBST(struct node * root,int key)
{
    if(root==NULL)
    return NULL;
    else if(root->data==key)
    return root;
    else if(root->data> key)
    return searchingBST(root->left,key);
    else
    return searchingBST(root->right,key);
}

// Through Iterative Way

struct node * searchingItrBST(struct node * root,int key)
{
    while(root!=NULL)
    {
        if(root->data == key)
        return root;
        else if(root->data > key)
        root = root->left;
        else
        root = root->right;
    }
    return NULL;
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

    //struct node * n = searchingBST(p,6);
    
    /*if(n!=NULL)
    printf("Found : %d",n->data);
    else
    printf("Not Found..");*/

    struct node * n = searchingItrBST(p,5);
    if(n!=NULL)
    printf("Found : %d",n->data);
    else
    printf("Not Found..");

    return 0;
}