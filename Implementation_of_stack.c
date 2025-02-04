
/*
 Implementation of stack using array
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack {
    int data[MAX];
    int top;
};


// 1. Initailize

void initialize(struct stack *st)
{
    st->top =-1;
    printf("Initialziaton Done !\n");
}

// 2. IsEmpty
int isEmpty(struct stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 3. IsFull

int isFull(struct stack *st)
{
    if(st->top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

// 4. push 

void push(struct stack *st)
{
    int d;
    if(isFull(st))
    {
        printf("Stack is Full.\n");
    }
    else
    {
        printf("Enter Data to be Pushed:");
        scanf("%d" , &d);
        st->data[++(st->top)]=d;
        printf("%d is pushed into stack.\n", d);
    }
}

// Pop

void pop(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("%d is popped from the stack\n" , st->data[(st->top)--]);
    }
}

void display(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Elements of the stack are :");
        for(int i=st->top; i>=0 ; i--)
        {
            printf("%d\n" , st->data[i]);
        }
    }
}

void peek(struct stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is : %d\n" ,st->data[st->top]);
    }
}

int main()
{
    struct stack s;
    int ch;

while(1)
{
    printf("\t\t\tMENU\n");
    printf("1) Initailize\n");
    printf("2) IsEmpty\n");
    printf("3) IsFull\n");
    printf("4) Push\n");
    printf("5) Pop\n");
    printf("6) Display\n");
    printf("7) Peek\n");
    printf("8) Exit\n");

    printf("Enter your Choice ::");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
        initialize(&s);
        break;

        case 2 :
        if(isEmpty(&s))
        {
            printf("Stack is Empty");
        }
        else
        {
            printf("Stack is Not Empty");
        }
        break;

        case 3 :
        if(isFull(&s))
        {
            printf("Stack is FUll");
        }
        else
        {
            printf("Stack is Not Full");
        }
        break;

    case 4 :
    push(&s);
    break;

    case 5:
    pop(&s);
    break;

    case 6 :
    display(&s);
    break;
    
    case 7 :
    peek(&s);
    break;

    case 8 :
    exit(0);
    break;

    default :
    printf("Invalid Selection.");



}
}
return 0;
}








