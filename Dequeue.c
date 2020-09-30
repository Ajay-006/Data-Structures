#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *Prev;
    int Data;
    struct Node *Next;
};
struct Node *Front = NULL;
struct Node *Rear = NULL;

struct Node *createNode(int Data)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->Data = Data;
    New->Prev = NULL;
    New->Next = NULL;
    return New;
}

void insertAtFront(int Data)
{
    struct Node *New = createNode(Data);
    if(Front == NULL)
    {
        New->Prev = New;
        New->Next = New;
        Front = New;
        Rear = New;
        return;
    }
    New->Next = Front;
    Front->Prev = New;
    Rear->Next = New;
    Front = New;
}

void insertAtRear(int Data)
{
    struct Node *New = createNode(Data);
    if(Rear == NULL)
    {
        New->Prev = New;
        New->Next = New;
        Front = New;
        Rear = New;
        return;
    }
    New->Next = Front;
    Rear->Next = New;
    Front->Prev = New;
    Rear = New;
}

void print()
{
    struct Node *Ptr = Front;
    if(Ptr == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    do
    {
        printf("The Data is %d\n",Ptr->Data);
        Ptr = Ptr->Next;
    }while(Ptr!=Front);
}

int deleteAtFront()
{
    if(Front == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int Data = Front->Data;
    if(Front == Rear)
    {
        free(Front);
        Front = NULL;
        Rear = NULL;
        return Data;
    }
    Front = Front->Next;
    free(Rear->Next);
    Rear->Next = Front;
    Front->Prev = Rear;
    return Data;
}

int deleteAtRear()
{
    if(Rear == NULL)
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int Data = Rear->Data;
    if(Front == Rear)
    {
        free(Rear);
        Front = NULL;
        Rear = NULL;
        return Data;
    }
    Rear = Rear->Prev;
    free(Front->Prev);
    Front->Prev = Rear;
    Rear->Next = Front;
    return Data;
}

void deleteQueue()
{
    struct Node *Ptr = Front;
    struct Node *Temp;
    do
    {
        Temp = Ptr;
        Ptr = Ptr->Next;
        free(Temp);
    }while(Ptr!=Front);
}

int main()
{
    int Choice,Data;
    do
    {
        printf("+-----------------------------------------------+\n");
        printf("| C Program to Implement Dequeue Data Structure |\n");
        printf("+-----------------------------------------------+\n");
        printf("| 1. Insert an Element at Front of the Queue    |\n");
        printf("| 2. Insert an Element at Rear of the Queue     |\n");
        printf("| 3. Print the Elements in the Queue            |\n");
        printf("| 4. Delete the Element at Front of the Queue   |\n");
        printf("| 5. Delete the Element at Rear of the Queue    |\n");
        printf("| 6. Exit the Program                           |\n");
        printf("+-----------------------------------------------+\n");
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
                print();
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
                deleteQueue();
                printf("The Memory Freed Successfully\n");
                break;
            }
        }
    }while(Choice!=6);   
    return 0;
}