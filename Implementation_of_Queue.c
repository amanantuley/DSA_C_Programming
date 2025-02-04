
// Implementation of queue using array

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue {
    int data[MAX];
    int front, rear;
};

void initialize(struct queue *qt)
{
    qt->front=-1;
    qt->rear=-1;
    printf("Initialization Done ..\n");
}

int isEmpty(struct queue *qt)
{
    if(qt->front== -1 || qt->rear== -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *qt)
{
    if(qt->front==MAX-1||qt->rear==MAX-1)
    {
        return 1 ;
    }
    else
    {
        return 0;
    }
}

void insert(struct queue *qt)
{
    int d;
    if(isFull(qt))
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter the data to be Entered ::");
        scanf("%d" , &d);
        qt->data[++(qt->rear)]=d;
        printf("%d have been entered into queue\n" ,d);
    }
}

void delete(struct queue *qt)
{
    if(isEmpty(qt))
    {
        printf("Queue is Empty\n");
    }
    else if(qt->front == qt->rear)
    {
        printf("removed data is %d" , qt->data[qt->front]);
        qt->front = qt->rear = -1;
    }
    else
    {
        printf("%d has been removed form the queue \n" , qt->data[qt->front]);
        qt->front++;
    }
}


void display(struct queue *qt)
{
    if(isEmpty(qt))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("queue Elemets are ::");
        for(int i=0 ; i<=qt->rear ; i++)
        {
            printf("%d" , qt->data[i]);
        }
    }
}

int main()
{
    struct queue q;
    int ch;

while(1)
{
    printf("\t\tMenu\n");
    printf("1) Initialize\n");
    printf("2) IsEmpty\n");
    printf("3) IsFull\n");
    printf("4) Insert\n");
    printf("5) Delete\n");
    printf("6) Display\n");
    printf("7) Exit\n");

    printf("Enter Your Selection ::");
    scanf("%d" , &ch);

    switch(ch)
    {
        case 1 :
        initialize(&q);
        break;

        case 2 :
        if(isEmpty(&q)){
            printf("Queue is Empty\n");
        }
        else
        {
            printf("Queue is Not empty\n");
        }
        break;

        case 3 :
        if(isFull(&q))
        {
            printf("Queue is Full\n");
        }
        else
        {
            printf("Queue is Not full\n");
        }
        break;

        case 4:

        insert(&q);
        break;

        case 5 :
        delete(&q);
        break;

        case 6:
        display(&q);
        break;

        case 7 :
        exit(0);
        break;

        default :
        printf("Invalid choice\n");


    }





}
return 0;
}
