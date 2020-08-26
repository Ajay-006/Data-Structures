#include<stdio.h>
// A Library that Conatins the basic I/O Statements
#include<stdlib.h>
// A Library Used to Dynamically Allocate the Memory for the Program
// Which contains malloc(), calloc(), realloc() and free()
struct Node
{
    /*
     * A Structure to Denote a Node in a Linked List
     * It Consists of 2 Parts:
     *           => Data (Value to be Stored)
     *           => Next (Pointer to Store the Next Address of the Node in the List)
     */
    int Data;
    struct Node *Next;
};

struct Node* createNode(int Data)
{
    // New => Pointer which Points to a Address that Containing Dynamically Created New Node 
    struct Node* New = (struct Node*)malloc(sizeof(struct Node));
    New->Data = Data;
    New->Next = NULL;
    return New;
}

struct Node* insertNodeAtBegin(struct Node *Head,int Data)
{
    /*
     * 1. Creating a New Node
     * 2. Head = NULL (return New)
     * 3. New->Next = Head
     * 4. return New
     */
    struct Node *New = createNode(Data);
    if(Head == NULL)
        return New;
    New->Next = Head;
    return New;
}

void printList(struct Node *Head)
{
    // A Function to Print the Data in the Linked List
    struct Node *Ptr = Head;
    while(Ptr != NULL)
    {
        printf("The Data is %d\n",Ptr->Data);
        Ptr = Ptr->Next;
    }
}

void insertNodeBeforeNode(struct Node *Head,int NodeVal,int Data)
{
    /* 
     * Here 2 Pointers are Used to Denote the Previous Using (prev) pointer and Current using (ptr) Pointer
     * We had to Traverse the Linked List until we reach the Condition Ptr->Data == NodeVal
     * Once We Reached at the Position the Previous will be Pointing to the Previous node of Ptr
     * Now Change Prev->Next  to the New Node's Address
     * Then Change the New Node's Address to the Ptr
     */
    struct Node *New = createNode(Data);
    struct Node *Prev = Head;
    struct Node *Ptr = Prev->Next;
    while(Ptr->Data != NodeVal)
    {
        Prev = Ptr;
        Ptr = Ptr->Next;
    }
    Prev->Next = New;
    New->Next = Ptr;
}

void insertNodeAfterNode(struct Node *Head,int NodeVal,int Data)
{
    /* 
     * Here 2 Pointers are Used to Denote the Previous Using (prev) pointer and Current using (ptr) Pointer
     * We had to Traverse the Linked List until we reach the Condition Prev->Data == NodeVal
     * Once We Reached at the Position the Previous will be Pointing to the Previous node of Ptr
     * Now Change Prev->Next  to the New Node's Address
     * Then Change the New Node's Address to the Ptr
     */
    struct Node *New = createNode(Data);
    struct Node *Prev = Head;
    struct Node *Ptr = Prev->Next;
    while(Prev->Data != NodeVal)
    {
        Prev = Ptr;
        Ptr = Ptr->Next;
    }
    Prev->Next = New;
    New->Next = Ptr;
}

void insertNodeAtTail(struct Node *Head,int Data)
{
    struct Node *New = createNode(Data);
    struct Node *Ptr = Head;
    while(Ptr->Next != NULL)
        Ptr=Ptr->Next;
    Ptr->Next = New;
}

struct Node* deleteNodeAtBegin(struct Node* Head)
{
    if (Head == NULL)
    {
        printf("The Linked List is Empty\n");
        return Head;
    }
    struct Node *Ptr = Head->Next;
    free(Head);
    return Ptr;
}

void deleteNodeBeforeNode(struct Node* Head,int NodeVal)
{
    // Here 3 Pointers are Used Ptr is Used to Point the Current Data Mid is Going 
    // To Point the Data Before the Ptr and Prev is going to Point Data Before Mid
    struct Node *Prev = Head;
    struct Node *Mid = Head->Next;
    struct Node *Ptr = Mid->Next;
    while(Ptr->Data!=NodeVal)
    {
        Prev=Mid;
        Mid=Ptr;
        Ptr=Ptr->Next;
    }
    free(Mid);
    Prev->Next=Ptr;
}

void deleteNodeAfterNode(struct Node* Head,int NodeVal)
{
    // Here 3 Pointers are Used Ptr is Used to Point the Current Data Mid is Going 
    // To Point the Data Before the Ptr and Prev is going to Point Data Before Mid
    struct Node *Prev = Head;
    struct Node *Mid = Prev->Next;
    struct Node *Ptr = Mid->Next;
    while(Prev->Data!=NodeVal)
    {
        Prev=Mid;
        Mid=Ptr;
        Ptr=Ptr->Next;
    }
    printf("Completed Traversing....");
    free(Mid);
    Prev->Next=Ptr;
}

void deleteNodeAtTail(struct Node* Head)
{
    struct Node *Prev = Head;
    struct Node *Ptr = Prev->Next;
    while(Ptr->Next != NULL)
    {
        Prev = Ptr;
        Ptr = Ptr->Next;
    }
    free(Ptr);
    Prev->Next = NULL;
}

void deleteList(struct Node* Head)
{
    struct Node *Ptr=Head;
    while(Ptr != NULL)
    {
        Head=Ptr;
        Ptr=Ptr->Next;
        free(Head);
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
    int Data,NodeVal;
    do
    {
        printf("+---------------------------------------------------+\n");
        printf("| A Program to Implement Linked List Data Structure |\n");
        printf("+---------------------------------------------------+\n");
        printf("| 1.Insert a New Node at Beginning                  |\n");
        printf("| 2.Insert a New Node Before a given Node           |\n");
        printf("| 3.Insert a New Node After a given Node            |\n");
        printf("| 4.Insert a New Node at the Tail                   |\n");
        printf("| 5.Print the Linked List                           |\n");
        printf("| 6.Delete a Node at Beginning                      |\n");
        printf("| 7.Delete a Node Before a given Node               |\n");
        printf("| 8.Delete a Node After a given Node                |\n");
        printf("| 9.Delete a Node at the Tail                       |\n");
        printf("| 10.Exit the Program                               |\n");
        printf("+---------------------------------------------------+\n");
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