#include<stdio.h>
#include<stdlib.h>
int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;
/*Function Prototype*/
void create();
void display();
void insert();
void del();
void search();
void reverse();
void sort();
int main()
{
        int choice;
        do{
                printf("\n\n--------Menu-----------\n");
                printf("1.Create\n");
                printf("2.Display\n");
                printf("3.Insert\n");
                printf("4.Delete\n");
                printf("5.Search\n");
                printf("6.Sort\n");
                printf("7.reverse\n");
                printf("8.Exit\n");
                printf("-----------------------");
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert();
                                        break;
 
                        case 4:
                                        del();
                                        break;
                        case 5:
                                        search();
                                        break;
                        case 6:
                                        sort();
                                        break;
                        case 7:
                                        reverse();
                                        break;
                        case 8:
                                        exit(0);
                                        break;
                        default:
                                        printf("\nInvalid choice:\n");
                                        break;
                }
        }while(choice!=8);
return 0;
}
void create() //creating an array
{
        printf("\nEnter the size of the array elements:\t");
        scanf("%d",&n);
        printf("\nEnter the elements for the array:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
}//end of create()
void display()  //displaying an array elements
{
        int i;
        printf("\nThe array elements are:\n");
        for(i=0;i<n;i++){
                 printf("%d\t",a[i]);         
         }
 }//end of display() 
void insert()   //inserting an element in to an array  
{         
    printf("\nEnter the position for the new element:\t");         
    scanf("%d",&pos);         
    printf("\nEnter the element to be inserted :\t");         
    scanf("%d",&val);         
    for(i=n-1;i>=pos;i--)
        {
                a[i+1]=a[i];
        }
        a[pos]=val;
        n=n+1;
}//end of insert()
 
 
void del()      //deleting an array element
{
        printf("\nEnter the position of the element to be deleted:\t");
        scanf("%d",&pos);
        val=a[pos];
        for(i=pos;i<n-1;i++)
        {
                a[i]=a[i+1];
        }
        n=n-1;
        printf("\nThe deleted element is =%d",val);
}//end of delete()
void search()   //searching an array element
{
        printf("\nEnter the element to be searched:\t");
        scanf("%d",&key);
        for(i=0;i<n;i++)
        {
                if(a[i]==key)
                {
                        printf("\nThe element is present at position %d",i);
                        break;
                }
        }
        if(i==n)
        {
                printf("\nThe search is unsuccessful");
        }
}//end of serach()
void sort()     //sorting the array elements
{
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1-i;j++)                 {                         if(a[j]>a[j+1])
                        {
                                temp=a[j];
                                a[j]=a[j+1];
                                a[j+1]=temp;
                        }
                }
        }
        printf("\nAfter sorting the array elements are:\n");
        display();
}//end of sort
void reverse()    //merging two arrays
{
	
 
   for (i = n - 1, j = 0; i >= 0; i--, j++)
      b[j] = a[i];
 
   /*
    * Copying reversed array into the original.
    * Here we are modifying original array, this is optional.
    */
 
   for (i = 0; i < n; i++)
      a[i] = b[i];
 
   printf("Reverse array is\n");
 
   for (i = 0; i < n; i++)
      printf("%d\t", a[i]);
}//end of reverse()
