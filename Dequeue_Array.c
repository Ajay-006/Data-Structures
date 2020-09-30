#include<stdio.h>
#include<stdlib.h>
#define Size 2
int *Arr;
int Front=-1, Rear=-1;

int isEmpty()
{
    return Front==-1 || Rear == -1;
}

int isFull()
{
    if((Front == 0 && Rear == Size-1)||(Rear == Front-1))
    {
        printf("Memory OverFlow Error\n");
        return 1;
    }
    return 0;
}
void insertAtFront(int Data)
{
    if(isEmpty())
    {
        Front = Rear = 0;
        Arr[0] = Data;
        return;
    }
    if(isFull())
        return;
    if(Front == 0)
        Front = Size - 1;
    else
        Front -= 1;
    Arr[Front] = Data;
}

void insertAtRear(int Data)
{
    if(isEmpty())
    {
        Front = Rear = 0;
        Arr[0] = Data;
        return;
    }
    if(isFull())
        return;
    if(Rear == Size-1)
        Rear = 0;
    else
        Rear += 1;
    Arr[Rear] = Data;
}

void print()
{
    if(isEmpty())
        return;
    for(int i = Front; i!=Rear;i = (i+1)%Size)
        printf("The Data is %d\n",Arr[i]);
    printf("The Data is %d\n",Arr[Rear]);
}

int deleteAtFront()
{
    if(isEmpty())
    {
        printf("Memory UnderFlow Error\n");
        return -1;
    }
    int Data = Arr[Front];
    if(Front == 0 && Rear == 0)
    {
        Front = -1;
        Rear = -1;
        return Data;
    }
    if(Front == Size-1)
        Front = 0; 
    else
        Front += 1;
    return Data;
}

int deleteAtRear()
{
    if(isEmpty())
    {
        printf("Memory UnderFlow Error\n");
        return -1;
    }
    int Data = Arr[Rear];
    if(Front == 0 && Rear == 0)
    {
        Front = -1;
        Rear = -1;
        return Data;
    }
    if(Rear == 0)
        Rear = Size-1; 
    else
        Rear -= 1;
    return Data;
}

int main()
{
    int Choice,Data;
    Arr = (int*)malloc(sizeof(int)*Size);
    if(Arr == NULL)
    {
        printf("Sorry Not Enough Memory to Allocate\n");
        return 0;
    }
    do
    {
        printf("+-----------------------------------------------------------+\n");
        printf("| C Program to Implement Dequeue Data Structure Using Array |\n");
        printf("+-----------------------------------------------------------+\n");
        printf("| 1. Insert an Element at Front of the Queue                |\n");
        printf("| 2. Insert an Element at Rear of the Queue                 |\n");
        printf("| 3. Print the Elements in the Queue                        |\n");
        printf("| 4. Delete the Element at Front of the Queue               |\n");
        printf("| 5. Delete the Element at Rear of the Queue                |\n");
        printf("| 6. Exit the Program                                       |\n");
        printf("+-----------------------------------------------------------+\n");
        printf("Enter Your Choice:");
        scanf("%d",&Choice);
        switch(Choice)
        {
            case 1:
            {
                printf("Enter the Element Data:");
                scanf("%d",&Data);
                insertAtFront(Data);
                break;
            }
            case 2:
            {
                printf("Enter the Element Data:");
                scanf("%d",&Data);
                insertAtRear(Data);
                break;
            }
            case 3:
            {
                print(Arr);
                break;
            }
            case 4:
            {
                printf("The Data is %d\n",deleteAtFront());
                break;
            }
            case 5:
            {
                printf("The Data is %d\n",deleteAtRear());
                break;
            }
            case 6:
            {
                free(Arr);
                break;
            }
        }
    }while(Choice!=6);    
    return 1;
}