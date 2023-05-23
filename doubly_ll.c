#include<stdio.h>
#include<stdlib.h>

struct  node{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * createNode(int data)
{
    struct node* root = (struct node *)malloc(sizeof(struct node));

    root->data = data;
    root->prev = NULL;
    root->next = NULL;
    return root;
}

void traverse(struct node * root)
{
    while(root!=NULL)
    {
        printf("%d\t",root->data);
        root = root->next;
    }
}

void revTraverse(struct node * root)
{
    while(root->next!=NULL)
    {
        root = root->next;
    }
    while(root!=NULL)
    {
        printf("%d\t",root->data);
        root = root->prev;
    }
}

int main()
{
    struct node * head = createNode(5);
    struct node * first = createNode(10);
    struct node * second = createNode(15);
    struct node * third = createNode(20);

    head->prev = NULL;
    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = NULL;

    printf("\nDoubly Linked list : ");
    traverse(head);

    
    printf("\nReverse Linked list : ");
    revTraverse(head);

    return 0;
}