#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void InsertAtBegin(struct Node **head, int num)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Unable To Create List!!!");
    }
    else if (*head == NULL)
    {
        printf("You Have To Create Your Head");
    }
    else
    {
        ptr->data = num;
        ptr->next = *head;
        *head = ptr;
    }
}

void InsertAtEnd(struct Node **head, int num)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p;
    ptr->data=num;
    if (ptr == NULL)
    {
        printf("Empty List!!");
    }
     else if (*head == NULL)
        {
            ptr->next = NULL;
            *head = ptr;
        }
        else
        {
            p = *head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = ptr;
            ptr->next = NULL;
        }
    }

void InsertAfterNode(struct Node **head, int num, int val)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = *head;
    while (p->data != num && p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = val;
    ptr->next = p->next;
    p->next = ptr;
}

void InsertAtPos(struct Node **head, int val, int pos)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    if (ptr == NULL)
	{
		printf("Unable To Create");
	}
	else if (*head == NULL)
	{
		printf("You Have To Create At Least A Linked List");
		exit(0);
	}
    else if (*head == NULL && pos == 1)
    {
        ptr->next = *head;
        *head = ptr;
    }
    else if (pos == 1)
	{
		ptr->next = *head;
        *head = ptr;
	}
    else{
    int i = 0;
    while (i != pos - 1)
    {
        *head = (*head)->next;
        i++;
    }
    ptr->next = (*head)->next;
    (*head)->next = ptr;
    }
}

void DeleteAtBegin(struct Node **head)
{
    struct Node *p = *head;
    if (*head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        *head = p->next;
        free(p);
    }
}

void DeleteByNthNode(struct Node **head, int val)
{
    struct Node *p = *head;
    struct Node *q = (*head)->next;
    if (*head == NULL)
    {
        printf("Your List Is Empty!!");
    }
    else if (q == NULL)
    {
        *head = NULL;
        free(q);
    }
    else
    {
    	int i;
        for ( i = 1; i < val - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
    }
}

void DeleteAtLast(struct Node **head)
{
    struct Node *p = *head;
    if (*head == NULL)
    {
        printf("Your List Is Empty!!");
    }
    else if (p->next == NULL)
    {
        free(p);
        *head = NULL;
    }
    else
    {
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }
}

void ReverseLinkedList(struct Node **head)
{
    struct Node *cur = *head;
    struct Node *prev = NULL;
    while (cur != NULL)
    {
        struct Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;
}

void Display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Empty List");
        exit(0);
    }
    else
    {
        printf("\nYour Created Linked List Is In Bellow::::\n");
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n\n");
    }
}
int main()
{
    struct Node *head = NULL;
    while (1)
    {
        printf("\n");
        printf("\t\t\t\t\t\t\t1->To Create A Linked List\n");
        printf("\t\t\t\t\t\t\t2->Insert At Begin\n");
        printf("\t\t\t\t\t\t\t3->Insert At End\n");
        printf("\t\t\t\t\t\t\t4->Traverse\n");
        printf("\t\t\t\t\t\t\t5->Insert After Node:\n");
        printf("\t\t\t\t\t\t\t6->Insert At Position\n");
        printf("\t\t\t\t\t\t\t->->->->->->->->->->->->->->->\n");
        printf("\t\t\t\t\t\t\t7->Delete At Begin\n");
        printf("\t\t\t\t\t\t\t8->Delete By Value:\n");
        printf("\t\t\t\t\t\t\t9->Delete The Last Node:\n");
        printf("\t\t\t\t\t\t\t->->->->->->->->->->->->->->->\n");
        printf("\t\t\t\t\t\t\t10->Reverse The Linked List:\n");
         printf("\t\t\t\t\t\t\t11->To Find Largest Node:\n");
        printf("\t\t\t\t\t\t\t->->->->->->->->->->->->->->->\n");
        printf("\t\t\t\t\t\t\tEnter C or c To Continue: \n");
        printf("\t\t\t\t\t\t\tEnter B or b To Stop: \n");
        int a, num, val;
        char ch;
        printf("Enter Your Choice: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &num);
            InsertAtEnd(&head,num);
            // ReverseLinkedList(&head);
            break;
        case 2:
            printf("Enter The Value You Want To Insert At Begin: ");
            scanf("%d", &num);
            InsertAtBegin(&head, num);
            break;
        case 3:
            printf("Enter Value: ");
            scanf("%d", &num);
            InsertAtEnd(&head, num);
            break;
        case 4:
            if (head == NULL)
                printf("Empty List");
            else
                Display(head);
            break;
        case 5:
            Display(head);
            printf("\nEnter The Element You Want To Insert After: ");
            scanf("%d", &num);
            printf("Enter The Value: ");
            scanf("%d", &val);
            InsertAfterNode(&head, num, val);
            break;
        case 6:
            Display(head);
            printf("\nEnter the pos you want to insert a element: ");
            scanf("%d", &num);
            printf("Enter the Value: ");
            scanf("%d", &val);
            InsertAtPos(&head, val, num);
            break;
        case 7:
            Display(head);
            printf("\nThe Linked List Is After Delete The First Node->->->->\n");
            DeleteAtBegin(&head);
            Display(head);
            break;
        case 8:
            Display(head);
            printf("Enter The Node Pos You Want To Delete?: ");
            scanf("%d", &num);
            DeleteByNthNode(&head, num);
            Display(head);
            break;
        case 9:
            Display(head);
            printf("\nThe Linked List Is After Delete The Last Node->->->->\n");
            DeleteAtLast(&head);
            Display(head);
            break;
        case 10:
            Display(head);
            printf("\nThe Linked List Is After Reverse->->->->\n");
            ReverseLinkedList(&head);
            Display(head);
            break;
        /*case 11:
        	//printf("The Largest Node Is: %d",Largest(head)->data);*/
        default:
            Display(head);
        }
        printf("Do You Want To Stop?: ");
        scanf("%s", &ch);
        if (ch == 'b' || ch == 'B')
            break;
    }
    return 0;
}