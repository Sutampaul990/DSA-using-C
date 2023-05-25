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

struct node * deleteBegin(struct node * root)
{
    struct node * ptr = root;
    root = root->next;
    free(ptr);
    return root;
}

struct node * deleteAtIndex(struct node * root,int pos)
{
    struct node * p = root;
    struct node * q = root->next;

    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return root;
}

struct node * deleteEnd(struct node * root)
{
    struct node * ptr = root;
    while(ptr->next->next!=NULL)
    {
        ptr = ptr->next;
    }
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
    struct node * fourth = createNode(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    printf("Linked List is : \t");
    traverse(head);
    
    /*head = deleteBegin(head);
    printf("\nAfter Linked List is : \t");
    traverse(head);*/

    /*head = deleteAtIndex(head,1);
    printf("\nAfter Linked List is : \t");
    traverse(head);*/

    head = deleteEnd(head);
    printf("\nAfter Linked List is : \t");
    traverse(head);

    return 0;
}