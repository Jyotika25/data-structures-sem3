#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
 
struct node 
{ 
    int value; 
    struct node *next; 
}; 
void create_node(int); 
void insert_node_pos(); 
void delete_pos(); 
void search(); 
void display(); 
 typedef struct node snode; 
snode *newnode, *ptr, *prev, *temp; 
snode *first = NULL, *last = NULL; 
 int main() 
 { 
    int ch; 
    char ans = 'Y'; 
 




   do 
    { 
        system("cls"); 
        printf("\n\tOperations on singly linked list\n"); 
        printf("\n\t1.Insert Node"); 
        printf("\n\t2.Delete Node"); 
        printf("\n\t3.Searching"); 
        printf("\n\t4.Traversal"); 
        printf("\n\tEnter your choice: "); 
        scanf("%d", &ch); 
 
        switch (ch) 
        { 
        case 1: 
            insert_node_pos(); 
            break; 
        case 2: 
            delete_pos(); 
            break; 
        case 3: 
            search(); 
            break; 





        case 4: 
            printf("\nElements of Linked List: "); 
            display(); 
            break; 
        default: 
            printf("\n...Invalid Choice...\n"); 
            break; 
        } 
        printf("\nYOU WANT TO CONTINUE (Y/N)"); 
        scanf(" %c", &ans); 
     }while (ans == 'Y'||ans == 'y'); 
    return 0; 
 } 
/* 
 * Creating Node 
 */ 
void create_node(int val) 
{    newnode = (snode *)malloc(sizeof(snode)); 
    if (newnode == NULL) 
    { 
        printf("\nMemory was not allocated"); 
    } 
  




  else     { 
        newnode->value = val; 
        newnode->next = NULL; 
    } 	} 
/* 
 * Inserting Node at position 
 */ 
void insert_node_pos() 
{ 
    int pos, val, cnt = 0, i; 
    printf("\nEnter the value for the Node:"); 
    scanf("%d", &val); 
    create_node(val); 
    printf("\nEnter the position "); 
    scanf("%d", &pos); 
    ptr = first; 
    while (ptr != NULL) 
    { 
        ptr = ptr->next; 
        cnt++; 
    } 
    





//Insertion in beginning 
    if (pos == 1) 
    { 
        if (first == last && first == NULL) 
        { 
            first = last = newnode; 
            first->next = NULL; 
            last->next = NULL; 
        } 
        else         { 
            temp = first; 
            first = newnode; 
            first->next = temp; 
        } 
    } 
    else if (pos>1 && pos<=cnt) 
    { 
        ptr = first; 
        for (i = 1;i < pos;i++) 
        { 
            prev = ptr; 
            ptr = ptr->next; 
        } 
        



prev->next = newnode; 
        newnode->next = ptr; 
    } 
    else     { 
        printf("Position is out of range"); 
    } 
    printf("\n Linked list after insertion: "); 
    display(); 
} 
/* 
 * Delete Node from specified position in a non-empty list 
 */ 
void delete_pos() 
{ 
    int pos, cnt = 0, i; 
 	if (first == NULL) 
    { 
        printf("No node to delete\n"); 
    } 
    else     { 
        printf("\nEnter the position of value to be deleted:"); 
        scanf(" %d", &pos); 
        




ptr = first; 
        if (pos == 1) 
        { 
            first = ptr->next; 
            printf("\nElement deleted"); 
        } 
        else         { 
            while (ptr != NULL) 
            { 
                ptr = ptr->next; 
                cnt = cnt + 1; 
            } 
            if (pos > 0 && pos <= cnt) 
            { 
                ptr = first; 
                for (i = 1;i < pos;i++) 
                { 
                    prev = ptr; 
                    ptr = ptr->next; 
                } 
                prev->next = ptr->next; 
            } 
          




  else      { 
                printf("Position is out of range"); 
            } 
        free(ptr); 
        printf("\nElement deleted"); 
        }     } 
    printf("\n Linked list after deletion: "); 
    display(); 
} 
/* 
 * searching an element in a non-empty list 
 */ 
void search() 
{ 
    int flag = 0, key, pos = 0; 
    if (first == NULL) 
    { 
        printf("No nodes in the list\n"); 
    } 
    else     { 
        printf("\nEnter the value to search"); 
        scanf("%d", &key); 
     




   for (ptr = first;ptr != NULL;ptr = ptr->next) 
        { 
            pos = pos + 1; 
            if (ptr->value == key) 
            { 
                flag = 1; 
                break; 
            }         } 
        if (flag == 1) 
        { 
            printf("\nElement %d found at %d position\n", key, pos); 
        } 
        else         { 
            printf("\nElement %d not found in list\n", key); 
        } 
    }	} 
/* 
 * Displays non-empty List from Beginning to End 
 */ 
void display() 
{ 	if (first == NULL) 
    { 
      




  printf("No nodes in the list to display\n"); 
    } 
    else 
    { 
        for (ptr = first;ptr != NULL;ptr = ptr->next) 
        { 
            printf("%d  ", ptr->value); 
        } 
    } 
} 
 


