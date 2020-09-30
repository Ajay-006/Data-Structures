#include<stdio.h>
#include<stdlib.h>
int size = 0, front = -1, rear = -1;

int isFull()
{
    return rear == size-1; 
}

int isEmpty()
{
    return front == -1 && rear == -1;
}

void insert(int *Arr, int Data)
{
    if(isFull())
        return;
    if(isEmpty())
        front = 0;
    rear += 1;
    Arr[rear] = Data;
}

void print(int *Arr)
{
    if(isEmpty())
        return;
    for(int i=front;i<=rear;i++)
        printf("The Data is %d\n",Arr[i]);
}

int delete(int *Arr)
{
    if(isEmpty())
        return -1;
    int Data = Arr[front];
    if(front == rear)
        rear = front = -1;
    else 
        front += 1;
    return Data;
}

int main()
{
    int Choice,Data;
    int *Arr;
    printf("Enter the Value of Size of Array:");
    scanf("%d",&size);
    Arr = (int*)malloc(sizeof(int)*size);
    if(Arr == NULL)
    {
        printf("Sorry Not Enough Memory to Allocate\n");
        return 0;
    }
    do
    {
        printf("+---------------------------------------------------------+\n");
        printf("| C Program to Implement Queue Data Structure Using Array |\n");
        printf("+---------------------------------------------------------+\n");
        printf("| 1. Insert an Element into the Queue                     |\n");
        printf("| 2. Print the Elements in the Queue                      |\n");
        printf("| 3. Delete the Element from the Queue                    |\n");
        printf("| 4. Exit the Program                                     |\n");
        printf("+---------------------------------------------------------+\n");
        printf("Enter Your Choice:");
        scanf("%d",&Choice);
        switch(Choice)
        {
            case 1:
            {
                printf("Enter the Element Data:");
                scanf("%d",&Data);
                insert(Arr, Data);
                break;
            }
            case 2:
            {
                print(Arr);
                break;
            }
            case 3:
            {
                printf("The Data is %d\n",delete(Arr));
                break;
            }
            case 4:
            {
                free(Arr);
                break;
            }
        }
    }while(Choice!=4);    
    return 1;
}