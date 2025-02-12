/*
        Implementaion of Circular Queue Using Array
        
        Name : Aman Antuley.
        Roll No : 23CO25
        Batch : 02


        Theory :
        A circular queue is a type of linear data structure where the last position is connected back to the first, forming a circle. This design allows for efficient use of space by ensuring that when the end of the queue is reached, the next element can be added at the beginning if there is available space. In a circular queue, elements are enqueued at the rear and dequeued from the front, with both pointers wrapping around when reaching the end of the array. Overflow occurs when the queue is full and an attempt to enqueue is made, while underflow happens if the queue is empty and a dequeue is attempted. This structure optimizes memory utilization and avoids the problem of wasted space in a regular linear queue.

        Queue ADT : 
          ADT : Abstract Data Type (Hidden Data type)
         Data : Sequence of any specific type of Data.


         Operations :

        1. Initialization of Queue: Set up the circular queue using a fixed-size array and initialize the `front` and `rear` pointers to manage the positions of the first and last elements.

        2. Check if Empty: The queue is considered empty if `front` equals `rear`.

        3. Check if Full: The queue is full if `(rear + 1) % size` equals `front`, where `size` is the total capacity of the queue.

        4. Insert (Enqueue): Add data to the position indicated by `rear`, and then update `rear` to `(rear + 1) % size`, provided the queue is not full.

        5. Delete (Dequeue): Remove data from the position indicated by `front`, and then update `front` to `(front + 1) % size`, ensuring the queue is not empty.

        6. Display: Traverse the queue from `front` to `rear`, handling the circular wraparound to display all elements.
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue {
    int data[MAX];
    int front,rear;
};

// Initialize Function
void initialize(struct queue *qt){
    qt->front = -1;
    qt->rear = -1;
    printf("Initialization Done !...");
}

// isEmpty Function 
int isEmpty(struct queue *qt){
    if(qt->front == -1 || qt->rear == -1){
         return 1; 
    } 
    else{
        return 0;
    }
}

// isFull Function
int isFull(struct queue *qt){
    if((qt->rear + 1) % MAX == qt->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Insert Function 
void insert(struct queue *qt){
    int d;
    if(isFull(qt))
    {
        printf("Queue Overflows...");
    }
    else{
        if(isEmpty(qt))
        {
            qt->front = qt->rear = 0;
        }
        else
        {
            qt->rear = (qt->rear + 1) % MAX;
        }
        printf("Enter A Value ::");
        scanf("%d" , &d);
        qt->data[qt->rear] = d;
        printf("%d is Entered in the Queue ..." , d);
    }
}


// Delete function
void delete(struct queue *qt)
{
    if(isEmpty(qt))
    {
        printf("Queue Is Empty...");
    }
    else{
        if(qt->front == qt->rear)
        {
            qt->front = qt->rear = -1;
        }
        else
        {
            printf("%d is Deleted from the Queue ..." , qt->data[qt->front]);
            qt->front = (qt->front +1) % MAX;
            
        }
    }
}



// Display Function
  void display(struct queue *qt)
  {
    int i;
    if(isEmpty(qt))
    {
        printf("Queue is Empty..");
    }
    else
    {
        printf("Queue Elements ::");
        int i = qt->front;
        while (1) {
            printf("%d ", qt->data[i]);
            if (i == qt->rear) break;
            i = (i + 1) % MAX;
        }
                printf("\n");
        }
    }


// Main Function 
int main()
{
    struct queue q;
    int ch;

    while(1)
    {
          printf("\n\n\t\tMENU\t\t\n\n");
    printf("\t\t1)Initailize\n\n");
    printf("\t\t2)IsEmpty\n\n");
    printf("\t\t3)IsFull\n\n");
    printf("\t\t4)Insert\n\n");
    printf("\t\t5)Delete\n\n");
    printf("\t\t6)Display\n\n");
    printf("\t\t7)Exit\n\n");
    printf("Enter Your Selection ::");
    scanf("%d" , &ch);

    switch(ch)
    {
           case 1 :
            initialize(&q);
            break;

            case 2 :
            if(isEmpty(&q))
                {
                    printf("Stack is Empty");
                }
                else
                {
                    printf("Stack is not Empty");
                }
            break;

            case 3 :
            if(isFull(&q))
                {
                    printf("Stack is Full");
                }
            else
                {
                    printf("Stack is not Full");
                }
            break;

            case 4 :
            insert(&q);
            break;

            case 5 :
            delete(&q);
            break;

            case 6 :
            display(&q);
            break;

            case 7 :
            exit(0);
            break;

            default :
            printf("Inavlid Selection");
        }
    }

    }

    
/*
     Conclusion : Hence We have Successfully Understood and Implemented Circular Queue Using Array.
*/