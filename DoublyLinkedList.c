#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *Prev;
    int Data;
    struct Node *Next;
};

struct Node* createNode(int Data)
{
    struct Node *New=(struct Node*)malloc(sizeof(struct Node));
    New->Prev=New->Next=NULL;
    New->Data=Data;
    return New;
}

struct Node* insertNodeAtBegin(struct Node *Head, int Data)
{
    struct Node *New = createNode(Data);
    if(Head == NULL)
        return New;
    New->Next = Head;
    Head->Prev = New;
    return New;
}

struct Node* insertNodeBeforeNode(struct Node *Head, int NodeVal, int Data)
{
    struct Node *New = createNode(Data);
    struct Node *Ptr = Head;
    while(Ptr->Data!=NodeVal)
        Ptr=Ptr->Next;
    New->Prev = Ptr->Prev;
    New->Next = Ptr->Prev->Next;  // Ptr->Prev->Next <=> Ptr
    Ptr->Prev->Next = New;
    Ptr->Prev = New;
}

struct Node* insertNodeAfterNode(struct Node *Head, int NodeVal, int Data)
{
    struct Node *New = createNode(Data);
    struct Node *Ptr = Head;
    while(Ptr->Data!=NodeVal)
        Ptr=Ptr->Next;
    New->Prev = Ptr->Next->Prev;  // Ptr->Next->Prev <=> Ptr
    New->Next = Ptr->Next;
    Ptr->Next = New;
    Ptr->Next->Prev = New;
}

struct Node* insertNodeAtTail(struct Node *Head, int Data)
{
    struct Node *New = createNode(Data);
    struct Node *Ptr = Head;
    while(Ptr->Next!=NULL)
        Ptr=Ptr->Next;
    New->Prev = Ptr;
    Ptr->Next = New;
}

void printList(struct Node  *Head)
{
    struct Node *Ptr = Head;
    while(Ptr!=NULL)
    {
        printf("The Data is %d\n",Ptr->Data);
        Ptr=Ptr->Next;
    }
}

struct Node* deleteNodeAtBegin(struct Node *Head)
{
    if(Head == NULL)
        return Head;
    Head = Head->Next;
    free(Head->Prev);
    Head->Prev = NULL;
    return Head;
}

void deleteNodeBeforeNode(struct Node *Head,int NodeVal)
{
    struct Node *Ptr = Head;
    while(Ptr->Data != NodeVal)
        Ptr = Ptr->Next;
    Ptr->Prev = Ptr->Prev->Prev;
    free(Ptr->Prev->Next);
    Ptr->Prev->Next = Ptr;
}

void deleteNodeAfterNode(struct Node *Head,int NodeVal)
{
    struct Node *Ptr = Head;
    while(Ptr->Data != NodeVal)
        Ptr = Ptr->Next;
    Ptr->Next = Ptr->Next->Next;
    free(Ptr->Next->Prev);
    Ptr->Next->Prev = Ptr;
}

void deleteNodeAtTail(struct Node *Head)
{
    struct Node *Ptr = Head;
    while(Ptr->Next->Next != NULL)
        Ptr = Ptr->Next;
    free(Ptr->Next);
    Ptr->Next = NULL;
}

void deleteList(struct Node *Head)
{
    struct Node *Ptr = Head;
    while(Ptr!=NULL)
    {
        Head=Ptr;
        Ptr=Ptr->Next;
        free(Head);
    }
}

int main()
{
    /*
     * Head   -> A Pointer Pointing to the Start of the Doubly Linked List
     * Choice -> A Variable to fetch the Action the User Want to Perform in Linked list
     */
    struct Node *Head = NULL;
    int Choice = 0;
    int Data,NodeVal;
    do
    {
        printf("+----------------------------------------------------------+\n");
        printf("| A Program to Implement Doubly Linked List Data Structure |\n");
        printf("+----------------------------------------------------------+\n");
        printf("| 1.Insert a New Node at Beginning                         |\n");
        printf("| 2.Insert a New Node Before a given Node                  |\n");
        printf("| 3.Insert a New Node After a given Node                   |\n");
        printf("| 4.Insert a New Node at the Tail                          |\n");
        printf("| 5.Print the Doubly Linked List                           |\n");
        printf("| 6.Delete a Node at Beginning                             |\n");
        printf("| 7.Delete a Node Before a given Node                      |\n");
        printf("| 8.Delete a Node After a given Node                       |\n");
        printf("| 9.Delete a Node at the Tail                              |\n");
        printf("| 10.Exit the Program                                      |\n");
        printf("+----------------------------------------------------------+\n");
        printf("Enter Your Choice:");
        scanf("%d",&Choice);
        switch(Choice)
        {
            case 1:
            {
                printf("Enter the Data for New Node:");
                scanf("%d",&Data);
                Head = insertNodeAtBegin(Head,Data);
                break;
            }
            case 2:
            {
                printf("Enter the Data for New Node:");
                scanf("%d",&Data);
                printf("Enter the Node Data Before the New Node to be Inserted:");
                scanf("%d",&NodeVal);
                insertNodeBeforeNode(Head,NodeVal,Data);
                break;
            }
            case 3:
            {
                printf("Enter the Data for New Node:");
                scanf("%d",&Data);
                printf("Enter the Node Data After the New Node to be Inserted:");
                scanf("%d",&NodeVal);
                insertNodeAfterNode(Head,NodeVal,Data);
                break;               
            }
            case 4:
            {
                printf("Enter the Data for New Node:");
                scanf("%d",&Data);
                insertNodeAtTail(Head,Data);
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
                scanf("%d",&NodeVal);
                deleteNodeBeforeNode(Head,NodeVal);   
                break;
            }
            case 8:
            {
                printf("Enter the Node Data After the Node is Deleted:");
                scanf("%d",&NodeVal);
                deleteNodeAfterNode(Head,NodeVal);   
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
    }while(Choice!=10);
    return 0;
}