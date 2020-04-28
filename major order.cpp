#include<stdio.h> 4
#include<conio.h> 
#include<stdlib.h> 
int RowMajor(int arr[20][20], int row, int col); 
int ColumnMajor(int arr[20][20], int, int); 
 main() 
{ 
    int r,c,arr[20][20],i,j,flag=1; 
    printf("\nEnter the number of row elements in array: "); 
    scanf("%d",&r); 
    printf("\nEnter the number of column elements in array: "); 
    scanf("%d",&c); 
    printf("\nEnter elements of 2-D array: \n"); 
    for (i=0;i<r;++i) 
    { 
        for(j=0;j<c;++j) 
        { 
            scanf("%d", &arr[i][j]); 
        } 
        printf("\n"); 
    } 





    printf("\n Checking for Row Major and Column Major Storage"); 
    flag = RowMajor(arr,r,c); 
    if(flag==0) 
    { 
        ColumnMajor(arr,r,c); 
        printf("\n Array is stored in Column Major format"); 
    } 
    else 
        printf("\n Array is stored in Row Major format"); 
} 
int RowMajor(int arr[20][20], int row, int col) 
{ 
    int array[100],k=0,size,flag=1; 
    size=row*col; 
    for(int i=0;i<row;++i){ 
        for(int j=0;j<col;++j){ 
            array[k++]=arr[i][j]; 
        } 
    } 
    k=0; 
    for(int i=0;i<row;++i){ 
        for(int j=0;j<col;++j){ 





            if(array[k]==arr[i][j]) 
                ++k; 
            else 
              { 
                 flag=0; 
                 break; 
              }         } 
    } 
return flag; 
} 
int ColumnMajor(int arr[20][20], int row, int col) 
{ 
    int array[100],k=0,size,flag=1,i,j; 
    size=row*col; 
    for(i=0;i<row;++i){ 
        for(j=0;j<col;++j){ 
            array[k++]=arr[i][j]; 
        } 
    } 
    k=0; 
    for(j=0;i<col;++i){ 
        for(i=0;j<row;++j){ 
            

if(array[k]==arr[i][j]) 
                ++k; 
            else 
              { 
                 flag=0; 
                 break; 
              } 
        } 
    } 
return flag; 
} 
 
 
 
 
 
 
 
 
 

