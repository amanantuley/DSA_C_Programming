/*
        Implementaion of Singly Linked List 
        
        Name : Aman Antuley.
        Roll No : 23CO25
        Batch : 02


        Theory :
        
       

         Operations :

      
*/







#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


// Inserting a Node At the End

struct node *insertAtEnd(struct node *h)
{
    int d;
    struct node *temp,*p;
    p = (struct node *)malloc(size of(struct node));

    if(p==NULL)
    {
        printf("Not enough memory..");
        return h;
    }
    else
    {
        p->data=d;
        p->next=NULL;
        if(h==NULL)
        {
            h=p;
        }
        else
        {
            temp =h;
            while(temp->next!=NULL)
            {
                temp=temp->next;
                temp->next=p;
            }
            return h;
        }
    }

}

   
/*
     Conclusion : 
*/