#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct stack * ptr,char data)
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
        char  data = ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}

int Isparenthesis(char * exp)
{
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(sp,'(');
        }
        else if(exp[i]==')')
        {
            if(isEmpty(sp))
                return 0;
            pop(sp);
        }
    }
    
    if(isEmpty(sp))
        return 1;
    else
        return 0;
}

int main()
{
    char * exp = "9*8-)(7)";
    if(Isparenthesis(exp))
        printf("The parenthesis is Matching");
    else
        printf("The parenthesis is not Matching");
    return 0;
}