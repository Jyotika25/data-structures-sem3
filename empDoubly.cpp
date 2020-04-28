#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
  struct node *prev;
  int empid;
  char name[20];
  struct node *next;
};
struct node *first=NULL,*last=NULL;
int n;
/*
void append(int n)
{
 struct node *t;
 int i;
 first=(struct node*)malloc(sizeof(struct node));
 first->prev=NULL;
 printf("\nEnter employee id:");
 scanf("%d",&first->empid);
 printf("\nEnter the employee name:");
 scanf("%s",first->name);
 first->next=NULL;
 first=last;

 for(i=1;i<n;i++)
 {
    t=(struct node*)malloc(sizeof(struct node)); 
    t->prev=last;
    printf("\nEnter employee id:");
    scanf("%d",&t->empid);
    printf("\nEnter the employee name:"); 
    scanf("%s",t->name);
    t->next=NULL;
    last->next=t;
 }
}
*/
bool isEmpty(){
	return first==NULL;
}

void insert_beg()
{
	char name[20];
	struct node *link=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter employee id:");
 	scanf("%d",&link->empid);
 	printf("\nEnter the employee name:");
 	scanf("%s",link->name);
 		if(isEmpty()){
 	last=link;
			 }
 else
 {first->prev=link;
 }
	link->next=first;
	first=link;
	}


void display()
{ 
 struct node *t;
 t=first;
 while(t!=NULL)
 {
  printf("\nEmployee id:%d",t->empid);
 printf("\nEmployee name:%s",t->name);
 t=t->next;
 printf("\n\n");
 }
} 

struct node* del_end()
{
 struct node *t=last;
 if(first->next=NULL)
 {
 	first=NULL;
 }
 else{
 	last->prev->next=NULL;
 }
 last=last->prev;
 return t;
}
/* int n;
 printf("\nEnter the employee id to be deleted:");
 scanf("%d",&n);
 while(t!=NULL)
 {
 if(t->empid==n)
 {
 t=t->next;
 t->prev=NULL;
 }
 else
 {
 if(t->next==NULL)
 t->prev->next=NULL;
 else{
 t->prev->next=t->next;
 t->next->prev=t->prev;
 }
 }
 return;
 t=t->next;
 }
}
*/
/*
void search()
{
 struct node *t;
 int n,found=0;
 printf("\nEnter the employee id to be searched:"); 
 scanf("%d",&n);
 while(t!=NULL)
 {
 if(t->empid==n)
 {
 printf("\nThe id found\nNAME:%s",t->name);
 found=1;
 break;
 }
 }
 if(found==0)
 printf("\nThe id not found!!!");
}

*/
 main()
{
 int choice;
//system("cls");

 
 printf("\nMENU");
 printf("\nEnter 1 for INSERTING DETAILS OF EMPLOYEE DATA AT THE BEGINNING");
 printf("\nEnter 2 for DISPLAYING THE EMPLOYEE DATA");
 printf("\nEnter 3 for DELETING AN EMPLOYEE DETAIL AT THE END");
 printf("\nEnter 0 for Exit");
 while(1)
 {
 
 printf("\nEnter your Option :- ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 insert_beg();
 break; 
 case 2:
 display();
 break;
 case 3:
 del_end();
 break;
 case 0:
 exit(0);
 default:
 printf("\nYou have entered a wrong choice!!");
 }
 }
 getch();
}
