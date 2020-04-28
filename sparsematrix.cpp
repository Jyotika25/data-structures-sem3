#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
 
void addition(int sparse1[10][3], int sparse2[10][3], int r, int c, int t1, int t2); 
void subtraction(int sparse1[10][3], int sparse2[10][3], int r, int c, int t1, int t2); 
int **transpose(int sparse2[10][3], int t2); 
 
 main() 
{ 
    int sparse1[10][3],sparse2[10][3],sum[10][3],diff[10][3]; 
    int **sparse3; 
    int r,c,p,q,t1,t2,s,d,element; 
    int i,j,ans=0,choice; 
    do 
    { 
      system("cls"); 
      printf("\t \t Operations on Sparse Matrices \n"); 
      printf("\t 1.Addition \n \t 2.Subtraction \n"); 
      printf("Enter choice: "); 
      scanf("%d",&choice); 





      printf("\nEnter the number of row elements in array: "); 
      scanf("%d",&r); 
      printf("\nEnter the number of column elements in array: "); 
      scanf("%d",&c); 
      t1=t2=0; 
    printf("\n Enter first matrix:\n"); 
    for(i=1;i<=r;i++) 	
      { 
        for(j=1;j<=c;j++) 
        { 
            scanf("%d", &element); 
            if(element!=0) 
            { 
                t1=t1+1; 
                sparse1[t1][1]=i; 
                sparse1[t1][2]=j; 
                sparse1[t1][3]=element; 
            }         } 
      } 
    sparse1[0][1]=r; 
    sparse1[0][2]=c; 
    sparse1[0][3]=t1; 
  




  printf("\n Enter second matrix:\n"); 
    for(i=1;i<=r;i++) 
      { 
        for(j=1;j<=c;j++) 
        { 
            scanf("%d", &element); 
            if(element!=0) 
            { 
                t2=t2+1; 
                sparse2[t2][1]=i; 
                sparse2[t2][2]=j; 
                sparse2[t2][3]=element; 
            }   } 
      } 
    sparse2[0][1]=r; 
    sparse2[0][2]=c; 
    sparse2[0][3]=t2; 
 switch(choice)      { 
        case 1: { 
                addition(sparse1,sparse2,r,c,t1,t2); 
                break; 
            } 
        




case 2:             { 
                subtraction(sparse1,sparse2,r,c,t1,t2); 
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
    getch(); 
} 

 
void addition(int sparse1[10][3],int sparse2[10][3], int r, int c, int t1, int t2) 
{ 	int i,j,s,sum[10][3],p=0; 
    i=j=s=1; 
    while((i<=t1)&&(j<=t2)) 
    { 
      




if(sparse1[i][1]==sparse2[j][1])    // if rows are equal 
      { 
        if(sparse1[i][2]==sparse2[j][2]) // if columns are equal 
        { 
            sum[s][1]=sparse1[i][1]; 
            sum[s][2]=sparse1[i][2]; 
            sum[s][3]=sparse1[i][3]+sparse2[j][3]; 
            i++; 
            j++; 
            if(sum[s][3]!=0) 
                s++; 
        } 
        else   // if columns are not equal 
        { 
            if(sparse1[i][2]<sparse2[j][2]) 
            { 
                sum[s][1]=sparse1[i][1]; 
                sum[s][2]=sparse1[i][2]; 
                sum[s][3]=sparse1[i][3]; 
                i++; 
                s++; 
        } 





            else 
            { 
                sum[s][1]=sparse2[j][1]; 
                sum[s][2]=sparse2[j][2]; 
                sum[s][3]=sparse2[j][3]; 
                j++; 
                s++; 
            }        } 
      } 
      else   //   if rows are not equal 
      { 
        if(sparse1[i][1]<sparse2[j][1]) 
        { 
            sum[s][1]=sparse1[i][1]; 
            sum[s][2]=sparse1[i][2]; 
            sum[s][3]=sparse1[i][3]; 
            i++; 
            s++; 
        } 
        else 
        { 
            sum[s][1]=sparse2[j][1]; 
            




sum[s][2]=sparse2[j][2]; 
            sum[s][3]=sparse2[j][3]; 
            j++; 
            s++; 
      } } 
   }  // end of while 
   if(i<=t1)    { 
      for(p=i;p<=t1;p++) 
      { 
        sum[s][1]=sparse1[p][1]; 
        sum[s][2]=sparse1[p][2]; 
        sum[s][3]=sparse1[p][3]; 
        s++; 
      }    } 
   else if(j<=t2) 
   { 
      for(p=j;p<=t2;p++) 
      { 
        sum[s][1]=sparse2[p][1]; 
        sum[s][2]=sparse2[p][2]; 
        sum[s][3]=sparse2[p][3]; 
        s++;      } } 





  // end of addition 
  sum[0][1]=r; 
  sum[0][2]=c; 
  sum[0][3]=s-1;  
  printf("\nThe sum is:\n Row \t \tColumn \t \tValue \n"); 
  for(i=1;i<s;++i) 
    printf(" %d \t \t %d \t \t %d \n", sum[i][1], sum[i][2], sum[i][3]); 
} 
void subtraction(int sparse1[10][3],int sparse2[10][3], int r, int c, int t1, int t2) 
{ 
    int i,j,d,diff[10][3],p=0; 
    i=j=d=1; 
    while((i<=t1)&&(j<=t2)) 
    { 
      if(sparse1[i][1]==sparse2[j][1])    // if rows are equal 
      { 
        if(sparse1[i][2]==sparse2[j][2]) // if columns are equal 
        { 
            diff[d][1]=sparse1[i][1]; 
            diff[d][2]=sparse1[i][2]; 
            diff[d][3]=sparse1[i][3]-sparse2[j][3]; 
            i++; 
  




          j++; 
            if(diff[d][3]!=0) 
                d++; 
        } 
        else   // if columns are not equal 
        { 
            if(sparse1[i][2]<sparse2[j][2]) 
            { 
                diff[d][1]=sparse1[i][1]; 
                diff[d][2]=sparse1[i][2]; 
                diff[d][3]=sparse1[i][3];i++; 
                d++; 
        } 
            else 
            { 
                diff[d][1]=sparse2[j][1]; 
                diff[d][2]=sparse2[j][2]; 
                diff[d][3]=0-sparse2[j][3]; 
                j++; 
                d++; 
            }         } 
      } 
      




else   //   if rows are not equal 
      { 
        if(sparse1[i][1]<sparse2[j][1]) 
        { 
            diff[d][1]=sparse1[i][1]; 
            diff[d][2]=sparse1[i][2]; 
            diff[d][3]=sparse1[i][3]; 
            i++; 
            d++; 
        } 
        else 
        { 
            diff[d][1]=sparse2[j][1]; 
            diff[d][2]=sparse2[j][2]; 
            diff[d][3]=0-sparse2[j][3];j++; 
            d++; 
        }       } 
   }  // end of while 
   if(i<=t1)    { 
      for(p=i;p<=t1;p++) 
      { 
        diff[d][1]=sparse1[p][1]; 
       




 diff[d][2]=sparse1[p][2]; 
        diff[d][3]=sparse1[p][3]; 
        d++; 
      } 
   } 
   else if(j<=t2) 
   { 
      for(p=j;p<=t2;p++) 
      { 
        diff[d][1]=sparse2[p][1]; 
        diff[d][2]=sparse2[p][2]; 
        diff[d][3]=0-sparse2[j][3]; 
        d++; 
      }    } // end of addition 
  diff[0][1]=r; 
  diff[0][2]=c; 
  diff[0][3]=d-1; 
  printf("\nThe difference is:\n Row \t \tColumn \t \tValue \n"); 
  for(i=1;i<d;++i) 
    printf(" %d \t \t %d \t \t %d \n", diff[i][1], diff[i][2], diff[i][3]); 
} 
 





int **transpose(int sparse2[10][3],int t2) 
{ 
    int **sparse3;  
    for(int i=1;i<=t2;++i) 
    { 
            sparse3[i][1]=0 + sparse2[i][2]; 
            sparse3[i][2]=0 + sparse2[i][1]; 
            sparse3[i][3]=0 + sparse2[i][3]; 
    } 
return sparse3; 
} 

