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

    return 0;
}