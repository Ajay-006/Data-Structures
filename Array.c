/*
 * A C Program to Implement the Linked List Using Array
 * This Program was Written by J.Ajay
 * B.E Cse 2nd Year
 */
#include<stdio.h>
#include<stdlib.h>
int SIZE = 2;

int* extendMemory(int *Arr)
{
    SIZE *= 2;
    Arr = (int*)realloc(Arr,SIZE);
    printf("The Array is Resized to %d\n",SIZE);
    return Arr;
}

int errorHandler(int Type)
{
    if(Type == 1)
        return 1;
    switch(Type)
    {
        case 0:
            printf("The Memory gets Overflowed....\n");
            break;
        case 2:
            printf("The List is Empty\n");
            break;
        case -1:
            printf("The Value Entered is Not Found in the Array\n");
            break;
    }
    return 0;
}

int moveElementsForward(int *Arr, int Length, int Data, int Index)
{
    // If the Previously Allocated Memory is Finished then again allocate New Memory
    if(Length >= SIZE)
        Arr = extendMemory(Arr);
    // If There is No Memory realloc() will return a NULL Pointer If we Received that Our Memory got Full
    if(Arr == NULL)
        return 0;
    while(Length>Index)
    {
        Arr[Length] = Arr[Length-1];
        Length -= 1;
    }
    Arr[Index] = Data;
    return 1;
}

void moveElementsBackward(int *Arr, int Length, int Index)
{
    while(Index < Length-1)
    {
        Arr[Index] = Arr[Index+1];
        Index += 1;
    }
    Arr[Index] = 0;
}

int insertAtBegin(int *Arr, int Length, int Data)
{
    if(Length == 0)
    {
        Arr[0] = Data;
        return 1;
    }
    return moveElementsForward(Arr, Length, Data, 0);
}

int insertBeforeElement(int *Arr, int Length, int Element, int Data)
{
    int i = 0;
    // Traverse The Array Until the Given Element is Found
    while(Arr[i]!=Element && i<Length)
        i += 1;
    // If the Element Entered by the User is not Present We wil End up in the Length value So we are returning 0
    if(i == Length)
        return -1;
    // Moving Elements from i to Last to 1 Step
    return moveElementsForward(Arr, Length, Data, i);
}

int insertAfterElement(int *Arr, int Length, int Element, int Data)
{
    int i = 0;
    while(Arr[i]!=Element && i<Length)
        i += 1;
    if(i == Length)
        return -1;
    // Moving Elements after i to Last to 1 Step
    return moveElementsForward(Arr, Length, Data, i+1);
}

int insertAtTail(int *Arr, int Length, int Data)
{
    if(Length == SIZE)
        Arr = extendMemory(Arr);
    if(Arr == NULL)
        return 0;
    Arr[Length] = Data;
    return 1;
}

int printList(int *Arr, int Length)
{
    if(Length == 0)
        return 2;
    int i = 0;
    while(i<Length)
    {
        printf("The Data is %d\n",Arr[i]);
        i += 1;
    }
    return 1;
}

int deleteAtBegin(int *Arr, int Length)
{
    if(Length == 0)
        return 2;
    moveElementsBackward(Arr, Length,0);
    return 1;
}

int deleteBeforeElement(int *Arr, int Length, int Element)
{
    int i =0;
    while(Arr[i]!=Element && i<Length)
        i += 1;
    if(i == Length)
        return -1;
    moveElementsBackward(Arr, Length, i-1);
    return 1;
}

int deleteAfterElement(int *Arr, int Length, int Element)
{
    int i =0;
    while(Arr[i]!=Element && i<Length)
        i += 1;
    if(i == Length)
        return -1;
    moveElementsBackward(Arr, Length, i+1);
    return 1;
}

int deleteAtTail(int *Arr, int Length)
{
    if(Length == 0)
        return 2;
    Arr[Length-1]=0;
    return 1;
}

int main()
{
    int *Arr;
    int Choice, Length, Data, Error, Element;
    Arr = (int*)malloc(sizeof(int)*SIZE);
    Length = 0;
    do
    {
    printf("+------------------------------------------------+\n");
    printf("| C Program to Implement Linked List Using Array |\n");
    printf("+------------------------------------------------+\n");
    printf("| 1. Insert New Element at Beginning             |\n");
    printf("| 2. Insert New Element Before an Element        |\n");
    printf("| 3. Insert New Element After an Element         |\n");
    printf("| 4. Insert New Element at the End               |\n");
    printf("| 5. Print the Linked List                       |\n");
    printf("| 6. Delete the Element at Beginnning            |\n");
    printf("| 7. Delete the Element Before an Element        |\n");
    printf("| 8. Delete the Element After an Element         |\n");
    printf("| 9. Delete the Element at the End               |\n");
    printf("| 10. Exit the Program                           |\n");
    printf("+------------------------------------------------+\n");
    printf("Enter Your Choice:");
    scanf("%d",&Choice);
    switch(Choice)
    {
        case 1:
        {
            printf("Enter the Data:");
            scanf("%d",&Data);
            Error = insertAtBegin(Arr, Length, Data);
            Length += errorHandler(Error);
            break;
        }
        case 2:
        {
            printf("Enter the Data:");
            scanf("%d",&Data);
            printf("Enter the Element Data:");
            scanf("%d",&Element);
            Error = insertBeforeElement(Arr, Length, Element, Data);
            Length += errorHandler(Error);
            break;
        }
        case 3:
        {
            printf("Enter the Data:");
            scanf("%d",&Data);
            printf("Enter the Element Data:");
            scanf("%d",&Element);
            Error = insertAfterElement(Arr, Length, Element, Data);
            Length += errorHandler(Error);
            break;
        }
        case 4:
        {
            printf("Enter the Data:");
            scanf("%d",&Data);
            Error = insertAtTail(Arr, Length, Data);
            Length += errorHandler(Error);
            break;
        }
        case 5:
        {
            Error = printList(Arr,Length);
            errorHandler(Error);
            break;
        }
        case 6:
        {
            Error = deleteAtBegin(Arr, Length);
            Length -= errorHandler(Error);
            break;
        }
        case 7:
        {
            printf("Enter the Element Data:");
            scanf("%d",&Element);
            Error = deleteBeforeElement(Arr, Length, Element);
            Length -= errorHandler(Error);
            break;
        }
        case 8:
        {
            printf("Enter the Element Data:");
            scanf("%d",&Element);
            Error = deleteAfterElement(Arr, Length, Element);
            Length -= errorHandler(Error);
            break;
        }
        case 9:
        {
            Error = deleteAtTail(Arr, Length);
            Length -= errorHandler(Error);
            break;
        }
        case 10:
        {
            free(Arr);
            printf("The Memory Freed Successfully\n");
            break;
        }
    }
    }while(Choice!=10);
}