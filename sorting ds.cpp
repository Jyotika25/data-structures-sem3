#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 5

void heap_sort();

void heap_adjust(int, int);
int arr_sort[MAX_SIZE], t, a;
void heap_sort() {
  for (int i = MAX_SIZE / 2 - 1; i >= 0; i--)
    heap_adjust(MAX_SIZE, i);

  for (int i = MAX_SIZE - 1; i >= 0; i--) {
    //Swapping Values 
    t = arr_sort[0];
    arr_sort[0] = arr_sort[i];
    arr_sort[i] = t;
    heap_adjust(i, 0);

    printf("\nHeap Sort Iteration %d : ", i);
    for (a = 0; a < MAX_SIZE; a++) {
      printf("\t%d", arr_sort[a]);
    }
  }
}

void heap_adjust(int n, int i) {
  int large = i, left = 2 * i + 1, right = 2 * i + 2;

  // adjest left child
  if (left < n && arr_sort[left] > arr_sort[large])
    large = left;

  // adjest right child
  if (right < n && arr_sort[right] > arr_sort[large])
    large = right;


  if (large != i) {
    //Swapping Values 
    t = arr_sort[i];
    arr_sort[i] = arr_sort[large];
    arr_sort[large] = t;
    heap_adjust(n, large);
  }
}
 
void mergeSort(int list[],int low,int mid,int high)
{
    int i, mi, k, lo, temp[50];
 
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (list[lo] <= list[mi])
        {
            temp[i] = list[lo];
            lo++;
        }
        else
        {
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
             temp[i] = list[k];
             i++;
        }
    }
 
    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
}
void partition(int list[],int low,int high)
{
    int mid;
 
    if(low < high)
    {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
}
 

void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}



 main()
{
int choice, num, i;
unsigned long int fact;

while(1)
{
printf("\n\n1.Insertion Sort\n");
printf("2.Merge Sort\n");
printf("3.Quick Sort\n");
printf("4.Bubble Sort\n");
printf("5.Selection Sort\n");
printf("6.Heap Sort\n");
printf("7.Exit\n");
printf("\nEnter Your choice?");
scanf("%d",&choice);
system("cls");
switch(choice)
{
case 1:
	{
	
printf("\nInsertion sort\n");
 int i, j, count, temp, number[25];

   printf("How many numbers u are going to enter?: ");
   scanf("%d",&count);

   printf("\nEnter %d elements: \n", count);
   // This loop would store the input numbers in array
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   // Implementation of insertion sort algorithm
   for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }

   printf("\nOrder of Sorted elements: \n");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

}
break;

case 2:{
printf("\nMerge sort\n");
 int list[50];
    int i, size;
 
    printf("\nEnter total number of elements:");
    scanf("%d", &size);
    printf("\nEnter the elements:\n");
    for(i = 0; i < size; i++)
    {
         scanf("%d", &list[i]);
    }
    partition(list, 0, size - 1);
    printf("After merge sort:\n");
    for(i = 0;i < size; i++)
    {
         printf("%d   ",list[i]);
    }
 
}break;

case 3:
{
printf("\nQuick sort\n");
int i, count, number[25];

   printf("\nHow many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("\nEnter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("\nOrder of Sorted elements: \n");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
}break;

case 4:
	{
	
printf("\nBubble sort\n");
int count, temp, i, j, number[30];

   printf("\nHow many numbers are u going to enter?: ");
   scanf("%d",&count);

   printf("\nEnter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);

   /* This is the main logic of bubble sort algorithm 
    */
   for(i=count-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("\nSorted elements:\n ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
}
break;

case 5:
{
printf("\nSelection sort\n");
int i, j, count, temp, number[25];

   printf("\nHow many numbers u are going to enter?: ");
   scanf("%d",&count);

   printf("\nEnter %d elements: ", count);
   // Loop to get the elements stored in array
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);
 
   // Logic of selection sort algorithm
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }

   printf("\nSorted elements: \n");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
}
break;

case 6:
{printf("\nHeap sort\n");
int i;

  printf("\nEnter %d Elements for Sorting\n", MAX_SIZE);
  for (i = 0; i < MAX_SIZE; i++)
    scanf("%d", &arr_sort[i]);

  printf("\nYour Data   :\n\n");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }

  heap_sort();

  printf("\n\nSorted Data :");
  for (i = 0; i < MAX_SIZE; i++) {
    printf("\t%d", arr_sort[i]);
  }
}
break;
default:
printf("\nyou entered a wrong choice");
exit(0);
}
}
getch();
return 0;
}
