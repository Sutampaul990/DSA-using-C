#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
        return 1;
    return 0;
}

void push(struct stack * ptr,int data)
{
    if(isFull(ptr))
    {
        printf("Stack OverFlow..");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack UnderFlow..");
        return -1;
    }
    else{
        int  data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}

int peek(struct stack * ptr,int i)
{
    int index = ptr->top - i + 1;
    if(index<0)
    printf("Not a valid positiion");
    else
    return ptr->arr[index];
}

int isFull(struct stack * ptr)
{
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

int main()
{
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;//Can be Scanned
    sp->top = -1;// -1 means Empty
    sp->arr = (int *)malloc(sizeof(int));



    return 0;
}