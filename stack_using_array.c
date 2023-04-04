#include<stdio.h>
#define size 5
struct stack
{
    int top;
    int arr[size];
};

// The Stack is Empty or not

int isEmpty(struct stack s)
{
    if(s.top == -1)
        return 1;
    return 0;
}

// The Stack is Full or not

int isFull(struct stack s)
{
    if(s.top == size-1)
        return 1;
    return 0;
}

// Pushing a data to stack

void push(struct stack *s, int data)
{
    s->top++;
    s->arr[s->top] = data;
    printf("Data Pushed!");
}

// Popping a Data from Stack

int pop(struct stack *s)
{
    int val;
    val = s->arr[s->top];
    s->top--;
    return val;
}

//Displaying the Stack

void display(struct stack s)
{
    for(int i=0;i<=s.top;i++)
        printf("%d\t",s.arr[i]);
}

//Peeking the value from Stack

int peek(struct stack *s)
{
    return s->arr[s->top];
}

int main()
{
    struct stack s;
    s.top = -1;
    int n, a,flag=1;
    while (flag==1)
    {
        printf("\n\t M E N U\n");
        printf("\t 1. Push \n");
        printf("\t 2. Pop \n");
        printf("\t 3. Peek \n");
        printf("\t 4. Display the stack\n");
        printf("\t 5. Exit \n");
        printf("Enter The Case You Want To Do: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if (isFull(s))

                printf("Stack Overflow");
        
            else
            {
                printf("Enter The Data To Push In Stack: ");
                scanf("%d", &n);
                push(&s, n);
            }
            break;
        case 2:
            if (isEmpty(s))
            
                printf("Stack Underflow!!");
            
            else
            
                printf("Poped Element is: %d", pop(&s));
            
            break;
        case 3:
            if (isEmpty(s))
            
                printf("Stack Underflow!!");
            
            else
            
                printf("The Top most element : %d", peek(&s));
            
            break;
        case 4:
            printf("The Elements Are : \n");
            display(s);
            break;
        case 5:
            printf("Exiting!!!");
            flag = 0;
            break;
        default :
            printf("Wrong Input!!");
            break;
        }
    }
    return 0;
}