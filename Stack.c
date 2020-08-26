#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
struct Node *Top = NULL;

struct Node *createNode(int Data)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->Data = Data;
    New->Next = Top;
    return New;
}

void push(int Data)
{
    struct Node *New = createNode(Data);
    Top = New;
}

void print()
{
    struct Node *Ptr = Top;
    while(Ptr!=NULL)
    {
        printf("The Data is %d\n",Ptr->Data);
        Ptr=Ptr->Next;
    }
}

int pop()
{
    if(Top == NULL)
        return -1;
    struct Node *Temp = Top;
    int Data = Temp->Data;
    Top = Temp->Next;
    free(Temp);
    return Data;
}

void deleteList()
{
    struct Node *Ptr = Top;
    while(Ptr!=NULL)
    {
        Top = Ptr;
        Ptr=Ptr->Next;
        free(Top);
    }
    printf("Memory Freed Successfully\n");
}

int main()
{
    int Choice,Data;
    do
    {
        printf("+---------------------------------------------+\n");
        printf("| C Program to Implement Stack Data Structure |\n");
        printf("+---------------------------------------------+\n");
        printf("| 1. Insert an Element into the Stack         |\n");
        printf("| 2. Print the Elements in the Stack          |\n");
        printf("| 3. Delete the Element from the Stack        |\n");
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
                push(Data);
                break;
            }
            case 2:
            {
                print();
                break;
            }
            case 3:
            {
                printf("The Data is %d\n",pop());
                break;
            }
            case 4:
            {
                deleteList();
                break;
            }
        }
    }while(Choice!=4);
    return 0;
}