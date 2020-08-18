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

void insertNodeBeforeNode(struct Node *Head, int NodeVal, int Data)
{
    struct Node *New=createNode(Head, Data);
    struct Node *Prev=Head;
    struct Node *Ptr=Prev->Next;
    while (Ptr->Data != NodeVal)
    {
        Prev=Ptr;
        Ptr=Ptr->Next;
    }
    Prev->Next=New;
    New->Next=Ptr;
}

void insertNodeAfterNode(struct Node *Head, int NodeVal, int Data)
{
    struct Node *New=createNode(Head, Data);
    struct Node *Prev=Head;
    struct Node *Ptr=Prev->Next;
    while (Prev->Data != NodeVal)
    {
        Prev=Ptr;
        Ptr=Ptr->Next;
    }
    Prev->Next=New;
    New->Next=Ptr;
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

struct Node* deleteNodeAtBegin(struct Node *Head)
{
    struct Node *Ptr=Head;
    while (Ptr->Next!=Head)
        Ptr=Ptr->Next;
    free(Ptr->Next);
    Ptr->Next=Head->Next;
    return Head->Next;
}

void deleteNodeBeforeNode(struct Node *Head, int Data)
{
    struct Node* Prev=Head;
    struct Node* Mid=Prev->Next;
    struct Node* Ptr=Mid->Next;
    while (Ptr->Data != Data)
    {
        Prev=Mid;
        Mid=Ptr;
        Ptr=Ptr->Next;
    }
    free(Mid);
    Prev->Next=Ptr;
}

void deleteNodeAfterNode(struct Node *Head, int Data)
{
    struct Node* Prev=Head;
    struct Node* Mid=Prev->Next;
    struct Node* Ptr=Mid->Next;
    while (Prev->Data != Data)
    {
        Prev=Mid;
        Mid=Ptr;
        Ptr=Ptr->Next;
    }
    free(Mid);
    Prev->Next=Ptr;
}

void deleteNodeAtTail(struct Node *Head)
{
    struct Node* Ptr=Head;
    while (Ptr->Next->Next!=Head)
        Ptr=Ptr->Next;
    free(Ptr->Next);
    Ptr->Next=Head;
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
    /*
     * Head   -> A Pointer Pointing to the Start of the Linked List
     * Choice -> A Variable to fetch the Action the User Want to Perform in Linked list
     */
    struct Node *Head = NULL;
    int Choice = 0;
    int Data, NodeVal;
    do
    {
        printf("+--------------------------------------------------------------+\n");
        printf("| A Program to Implement Circularly Linked List Data Structure |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("| 1.Insert a New Node at Beginning                             |\n");
        printf("| 2.Insert a New Node Before a given Node                      |\n");
        printf("| 3.Insert a New Node After a given Node                       |\n");
        printf("| 4.Insert a New Node at the Tail                              |\n");
        printf("| 5.Print the Linked List                                      |\n");
        printf("| 6.Delete a Node at Beginning                                 |\n");
        printf("| 7.Delete a Node Before a given Node                          |\n");
        printf("| 8.Delete a Node After a given Node                           |\n");
        printf("| 9.Delete a Node at the Tail                                  |\n");
        printf("| 10.Exit the Program                                          |\n");
        printf("+--------------------------------------------------------------+\n");
        printf("Enter Your Choice:");
        scanf("%d", &Choice);
        switch (Choice)
        {
        case 1:
        {
            printf("Enter the Data for New Node:");
            scanf("%d", &Data);
            Head = insertNodeAtBegin(Head, Data);
            break;
        }
        case 2:
        {
            printf("Enter the Data for New Node:");
            scanf("%d", &Data);
            printf("Enter the Node Data Before the New Node to be Inserted:");
            scanf("%d", &NodeVal);
            insertNodeBeforeNode(Head, NodeVal, Data);
            break;
        }
        case 3:
        {
            printf("Enter the Data for New Node:");
            scanf("%d", &Data);
            printf("Enter the Node Data After the New Node to be Inserted:");
            scanf("%d", &NodeVal);
            insertNodeAfterNode(Head, NodeVal, Data);
            break;
        }
        case 4:
        {
            printf("Enter the Data for New Node:");
            scanf("%d", &Data);
            insertNodeAtTail(Head, Data);
            break;
        }
        case 5:
        {
            printList(Head);
            break;
        }
        case 6:
        {
            Head = deleteNodeAtBegin(Head);
            break;
        }
        case 7:
        {
            printf("Enter the Node Data Before the Node is Deleted:");
            scanf("%d", &NodeVal);
            deleteNodeBeforeNode(Head, NodeVal);
            break;
        }
        case 8:
        {
            printf("Enter the Node Data After the Node is Deleted:");
            scanf("%d", &NodeVal);
            deleteNodeAfterNode(Head, NodeVal);
            break;
        }
        case 9:
        {
            deleteNodeAtTail(Head);
            break;
        }
        case 10:
        {
            deleteList(Head);
            break;
        }
        }
    } while (Choice!=10);
    return 0;
}