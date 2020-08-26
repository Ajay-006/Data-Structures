#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
struct Node *Front = NULL;
struct Node *Rear = NULL;

struct Node *createNode(int Data)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->Data = Data;
    New->Next = NULL;
    return New;
}

void enqueue(int Data)
{
    struct Node *New = createNode(Data);
    if(Front == NULL)
    {
        Front = Rear = New;
        return;
    }
    Rear->Next = New;
    Rear = Rear->Next;
}

void print()
{
    struct Node *Ptr = Front;
    while(Ptr!=NULL)
    {
        printf("The Data is %d\n",Ptr->Data);
        Ptr=Ptr->Next;
    }
}

int dequeue()
{
    if(Front == NULL)
        return -1;
    struct Node *Temp = Front;
    int Data = Temp->Data;
    Front = Front->Next;
    free(Temp);
    return Data;
}

void deleteQueue()
{
    struct Node *Ptr = Front;
    while(Ptr!=NULL)
    {
        Rear = Ptr;
        Ptr=Ptr->Next;
        free(Rear);
    }
    printf("Memory Freed Successfully\n");
}

int main()
{
    int Choice,Data;
    do
    {
        printf("+---------------------------------------------+\n");
        printf("| C Program to Implement Queue Data Structure |\n");
        printf("+---------------------------------------------+\n");
        printf("| 1. Insert an Element into the Queue         |\n");
        printf("| 2. Print the Elements in the Queue          |\n");
        printf("| 3. Delete the Element from the Queue        |\n");
        printf("| 4. Exit the Program                         |\n");
        printf("+---------------------------------------------+\n");
        printf("Enter Your Choice:");
        scanf("%d",&Choice);
        switch(Choice)
        {
            case 1:
            {
                printf("Enter the Element Data:");
                scanf("%d",&Data);
                enqueue(Data);
                break;
            }
            case 2:
            {
                print();
                break;
            }
            case 3:
            {
                printf("The Data is %d\n",dequeue());
                break;
            }
            case 4:
            {
                deleteQueue();
                break;
            }
        }
    }while(Choice!=4);
    return 0;
}