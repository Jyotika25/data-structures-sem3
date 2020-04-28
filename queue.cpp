/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue *next;
};
struct queue *addq(struct queue *front);
struct queue *delq(struct queue *front);
 main()
{
    struct queue *front;
    int reply,option,data;
    system("cls");
    front=NULL;
    do
    {
	printf("\n1.addq");
	printf("\n2.delq");
	printf("\n3.exit");
	printf("\nSelect proper option");
	scanf("%d",&option);
	switch(option)
	{
		case 1 : //addq
			 front=addq(front);
			 break;
		case 2 : //delq
			 front=delq(front);
		case 3 : exit(0);
	}
    }while(1);
    return 0;
}
struct queue *addq(struct queue *front)
{
	struct queue *c,*r;
	//create new node
	c=(struct queue*)malloc(sizeof(struct queue));
	if(c==NULL)
	{
		printf("Insufficient memory");
		return(front);
	}
	//read an insert value from console
	printf("\nEnter data");
	scanf("%d",&c->data);
	c->next=NULL;
	if(front==NULL)
	{
		front=c;
	}
	else
	{
		//insert new node after last node
		r=front;
		while(r->next!=NULL)
		{
			r=r->next;
		}
	}
	return(front);
}
struct queue *delq(struct queue *front)
{
	struct queue *c;
	if(front==NULL)
	{
		printf("Queue is empty");
		return(front);
	}
	//print the content of first node
	printf("Deleted data:%d",front->data);
	//delete first node
	c=front;
	front=front->next;
	free(c);
	return(front);
}*/

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int frontelement();
void enq(int data);
void deq();
void empty();
void display();
void create();
void queuesize();
 
int count = 0;
 
main()
{
    int no, ch, e;
 
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    printf("\n 7 - Queue size");
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 
/* Create an empty queue */
void create()
{
    front = rear = NULL;
}
 
/* Returns queue size */
void queuesize()
{
    printf("\n Queue size : %d", count);
}
 
/* Enqueing the queue */
void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 
/* Displaying the queue elements */
void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->info);
}
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 
/* Returns the front element of queue */
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 
/* Display if queue is empty or not */
void empty()
{
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}
