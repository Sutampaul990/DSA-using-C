#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * createNode(int data)
{
    struct node * root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->next = NULL;
    return root;
}

struct node * insertBeginning(struct node* root,int data)
{
    struct node * ptr = createNode(data);
    ptr->next = root;
    return ptr;
}

struct node * insertAtIndex(struct node * root,int pos,int data)
{
    struct node * ptr = createNode(data);
    struct node * p = root;
    int i=0;

    while(i!=pos-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return root; 
}

struct node * insertEnd(struct node * root,int data)
{
    struct node * ptr = createNode(data);
    struct node * p = root;

    while(p->next != NULL)
        p = p->next;
    p->next = ptr;
    ptr->next = NULL;
    return root;
}

void traverse(struct node * root)
{
    while(root!= NULL)
    {
        printf("%d\t",root->data);
        root = root->next;
    }
}

int main()
{
    struct node * head = createNode(20);
    struct node * second = createNode(30);
    struct node * third = createNode(40);

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("Linked List is : \t");
    traverse(head);

    /*head = insertBeginning(head,5);
    printf("\nAfter Linked List is : \t");
    traverse(head);*/

    /*head = insertAtIndex(head,1,25);
    printf("\nAfter Linked List is : \t");
    traverse(head);*/

    head = insertEnd(head,60);
    printf("\nAfter Linked List is : \t");
    traverse(head);

    return 0;
}