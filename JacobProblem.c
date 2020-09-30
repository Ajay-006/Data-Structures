#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

struct Node* createNode(struct Node *Head, int Data)
{
    struct Node *New=(struct Node*)malloc(sizeof(struct Node));
    New->Data=Data;
    New->Next=Head;
    return New;
}

struct Node* insertNodeAtBegin(struct Node *Head, int Data)
{
    struct Node *New=createNode(Head, Data);
    if (Head==NULL)
    {
        New->Next=New;
        return New;
    }
    struct Node *Ptr=Head->Next;
    while (Ptr->Next!=Head)
        Ptr=Ptr->Next;
    Ptr->Next=New;
    return New;
}

void insertNodeAtTail(struct Node *Head, int Data)
{
    struct Node *New=createNode(Head, Data);
    struct Node *Ptr=Head;
    while (Ptr->Next!=Head)
        Ptr=Ptr->Next;
    Ptr->Next=New;
}

void printList(struct Node *Head)
{
    struct Node *Ptr=Head;
    do
    {
        printf("The Data is %d\n", Ptr->Data);
        Ptr=Ptr->Next;
    } while (Ptr!=Head);
}

void solveProblem(struct Node *Head, int k)
{
    struct Node *Ptr = Head;
    struct Node *Temp;
    int Count = 1;
    while(Ptr != Ptr->Next)
    {
        if(Count == k-1)
        {
            Count = 1;
            Temp = Ptr->Next;
            Ptr->Next = Temp->Next;
            printf("The Data that is going to be removed is %d\n",Temp->Data);
            free(Temp);
        }
        else
            Count += 1;
         Ptr = Ptr->Next;
    }
    printf("The Winner is %d\n", Ptr->Data);
}

void deleteList(struct Node *Head)
{
    struct Node *Ptr=Head;
    struct Node *Temp;
    while (Ptr!=Head)
    {
        Temp=Ptr;
        free(Temp);
        Ptr=Ptr->Next;
    }
}

int main()
{
    struct Node *Head = NULL;
    Head = insertNodeAtBegin(Head,10);
    insertNodeAtTail(Head,20);
    insertNodeAtTail(Head,30);
    insertNodeAtTail(Head,40);
    insertNodeAtTail(Head,50);
    printList(Head);
    solveProblem(Head,2);
    deleteList(Head);
    printf("The Memory Freed Successfully\n");
    return 0;
}