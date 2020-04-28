#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
 
void searching(int *, int, int); 
void insertion(int *, int); 
void deletion(int *, int); 
void traversal(int *, int); 
void sorting(int *, int); 
void reversal(int *, int); 
 
main() 
{ 
    int ans=0; 
    int choice; 
    do  { 
      system("cls"); 
      printf("\t \t Menu for 1-D Array \n"); 
      printf("\t 1.Traversal \n \t 2.Insertion \n \t 3.Deletion \n \t 4.Searching \n \t 5.Sorting \n \t 6.Reversal\n"); 






      printf("Enter choice: "); 
      scanf("%d",&choice); 
 
      switch(choice)    { 
        case 1: 
            { 
                int arr[100],n,search,c; 
                printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array: \n", n); 
 
                for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
                traversal(arr, n);
break; 
            } 
 
        case 2:             { 
                int arr[100],n,search,c; 
                printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array: \n", n); 
 
                



for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
                insertion(arr, n); 
                break; 
            } 
 
        case 3:     { 
                int arr[100],n,search,c; 
                printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array: \n", n); 
 
                for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
                deletion(arr, n); 
                break; 
            } 
 
        case 4:      { 
                int arr[100],n,search,c; 
                printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                




printf("\nEnter elements of array: \n", n); 
 	 for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
                printf("\nEnter the number to search: "); 
                scanf("%d", &search); 
                searching(arr, n, search); 
                break; 
            } 
        case 5:{ 
                int arr[100],n,search,c; 
                printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array: \n", n); 
 
                for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
                sorting(arr, n); 
                break; 
            } 
 
        case 6:  { 
                int arr[100],n,search,c; 
                




printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array: \n", n); 
 	 for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
                reversal(arr, n); 
                break; 
            } 
        default: 
            { 
                printf("Entered wrong choice");
              break; 
            } 
      } 
      printf("\n Want to continue(enter 0 to continue): "); 
      scanf("%d",&ans); 
      }while(ans==0); 
} 
 
void traversal(int *arr, int size) 
{ 
    printf("Elements of array entered: \n"); 
    




for(int i=0;i<size;++i) 
      printf(" %d ", arr[i]); 
} 
 
void insertion(int *arr, int size) 
{ 
    int pos,i,data; 
    printf("\nEnter the position of the new element: "); 
    scanf("%d",&pos); 
    printf("\nEnter the data element you want to insert: "); 
    scanf("%d",&data); 
    for(i=size-1;i>=pos-1;i--) 
        { 
           arr[i+1]=arr[i]; 
        } 
    arr[pos-1]=data; 
    size+=1; 
    printf("New array is :\n"); 
    for(i=0;i<size;i++) 
        { 
           printf("%d ",arr[i]); 
        } 
} 
 



void deletion(int *arr, int size) 
{ 
    int pos,i,data; 
    printf("\nEnter the position of element to delete: "); 
    scanf("%d",&pos); 
    for(i=pos-1;i<=size-1;i++) 
        { 
           arr[i]=arr[i+1]; 
        } 
    size-=1; 
    printf("New array is :\n"); 
    for(i=0;i<size;i++) 
        { 
           printf("%d ",arr[i]); 
        } 
} 
 
void searching(int *arr, int size, int search) 
{ 
     //Linear Searching 
    int c; 
    for (c = 0; c<size; c++) 





    { 
        if (arr[c] == search)     /* if required element found */ 
        { 
            printf("%d is present at location %d.\n", search, c+1); 
            break; 
         } 
     } 
     if (c == size) 
        printf("%d is not present in array.\n", search); 
} 
 
void sorting(int *arr, int size) 
{ 
  int i,j,swap; 
  for (i=0 ; i<size-1; i++) 
  { 
    for (j=0 ; j<size-i-1; j++) 
    { 
        if (arr[j]>arr[j+1]) /* Sorted in increasing order */ 
            { 
                swap       = arr[j]; 
                arr[j]   = arr[j+1]; 





                arr[j+1] = swap; 
            } 
    } 
  } 
 
  printf("\nSorted list in ascending order: "); 
  for(i=0;i<size;++i) 
   printf(" %d ", arr[i]); 
} 
 
void reversal(int *arr,int size) 
{ 
    int barr[100],i,j; 
     for(i=0,j=size-1; j>=0;++i,--j) 
        barr[i]=arr[j]; 
    printf("Reversed Array is: "); 
    for(i=0;i<size;++i) 
        printf(" %d ", barr[i]); 
} 

