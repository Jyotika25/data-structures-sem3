#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
 void Linearsearching(int *, int, int); 
void Binarysearching(int *, int, int); 
 main() 
{ 
    int ans=0, choice; 
    do 
    { 
      system("cls"); 
      printf("\t \t Searching \n"); 
      printf("\t 1.Linear \n \t 2.Binary \n"); 
      printf("Enter choice: "); 
      scanf("%d",&choice); 
      switch(choice) 
      { 
        case 1:   { 
                int arr[100],n,search,c; 
                printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array: \n", n); 
 	for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
 



                printf("\nEnter the number to search: "); 
                scanf("%d", &search); 
 
                Linearsearching(arr, n, search); 
                break; 
            } 
        case 2:             { 
                int arr[100],n,search,c; 
printf("\nEnter the number of elements in array: "); 
                scanf("%d",&n); 
                printf("\nEnter elements of array(sorted order): \n", n); 
 for (c = 0; c < n; c++) 
                    scanf("%d", &arr[c]); 
 	 printf("\nEnter the number to search: "); 
                scanf("%d", &search); 
                Binarysearching(arr, n, search); 
                break; 
            } 
        default: {
      	    printf("Entered wrong choice"); 
                   break; 
            } 
      } 
      



printf("\n Want to continue(enter 0 to continue): "); 
      scanf("%d",&ans); 
      }while(ans==0); 
} 
void Linearsearching(int *arr, int size, int search) 
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
void Binarysearching(int *array, int size, int search) 
{ 
    //Binary Searching 
     int c, first, last, middle; 




      first = 0; 
      last = size - 1; 
      middle = (first+last)/2; 
 
      while (first <= last) { 
        if (array[middle] < search) 
            first = middle + 1; 
        else if (array[middle] == search) { 
            printf("%d found at location %d.\n", search, middle+1); 
            break; 
            } 
        else 
            last = middle - 1; 
 
        middle = (first + last)/2; 
    } 
      if (first > last) 
         printf("Not found! %d is not present in the list.\n", search); 
} 
 

