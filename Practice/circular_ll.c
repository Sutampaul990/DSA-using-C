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

struct node * insertFirst(struct node * root,int data)
{
    struct node * ptr = createNode(data);
    struct node * p = root->next;

    while(p->next!=root)
    {
        p=p->next;
    }
    ptr->next = root;
    p->next = ptr;
    root = ptr;
    return root;
}

void traverse(struct node * root)
{
    struct node * ptr = root;
    do
    {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }while(ptr != root);
}

int main()
{
    struct node * head = createNode(20);
    struct node * second = createNode(30);
    struct node * third = createNode(40);
    struct node * fourth = createNode(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    printf("Linked List is :\t");
    traverse(head);

    head = insertFirst(head,05);
    printf("\nAfter Linked List is :\t");
    traverse(head);

    return 0;
}