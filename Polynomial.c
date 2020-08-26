#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct Node
{
    int Coefficient;
    int Power;
    struct Node *Next;
};

struct Node *createNewNode(int Coefficient, int Power)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->Coefficient = Coefficient;
    New->Power = Power;
    New->Next = NULL;
    return New;
}

struct Node *insertNewNode(struct Node *Head, int Power, int Coefficient)
{
    printf("The Power & Coefficient is %d & %d\n",Power,Coefficient);
    struct Node *New = createNewNode(Coefficient, Power);
    if(Head == NULL)
        return New;
    struct Node *Ptr = Head;
    while(Ptr->Next != NULL)
        Ptr = Ptr->Next;
    Ptr->Next = New;
    return Head;
}

struct Node *createNewPolynomial()
{
    // Head : The Newly Created Linked List Start Address
    struct Node *Head = NULL;
    int Power, Coefficient;
    int Choice = 1;
    do
    {
        printf("Enter the Coefficient: ");
        scanf("%d",&Coefficient);
        printf("Enter the Power:");
        scanf("%d",&Power);
        Head = insertNewNode(Head, Power, Coefficient);
        printf("*Note: Enter 0 to Stop Adding Variables\n");
        printf("Do You Want to add Another Variable? ");
        scanf("%d",&Choice);
    }while(Choice != 0);
    return Head;
}

void displayPolynomial(struct Node *Head)
{
    struct Node *Ptr = Head;
    printf("The Polynomial is ");
    while(Ptr!=NULL)
    {
        printf("%d X %d\t", Ptr->Coefficient, Ptr->Power);
        Ptr = Ptr->Next;
    }
    printf("\n");
}



struct Node *addPolynomial(struct Node *Result,struct Node *Head1)
{
    struct Node *Ptr1 = Head1;
    struct Node *Ptr2;
    while(Ptr1 != NULL)
    {
        Ptr2 = Result;
        while(Ptr2 != NULL && Ptr1->Power != Ptr2->Power)
            Ptr2 = Ptr2->Next;
        if(Ptr2 == NULL)
            Result = insertNewNode(Result , Ptr1->Power, Ptr1->Coefficient);
        else
            Ptr2->Coefficient += Ptr1->Coefficient;
        Ptr1 = Ptr1->Next;
    }
    return Result;
}

struct Node *subtractPolynomial(struct Node *Result, struct Node *Head1)
{
    struct Node *Ptr1 = Head1;
    struct Node *Ptr2;
    if(Result == NULL)
    {
        while(Ptr1 != NULL)
        {
            Result = insertNewNode(Result, Ptr1->Power, Ptr1->Coefficient);
            Ptr1 = Ptr1->Next;
        }
        return Result;
    }
    while(Ptr1 != NULL)
    {
        Ptr2 = Result;
        while(Ptr2 != NULL && Ptr1->Power != Ptr2->Power)
            Ptr2 = Ptr2->Next;
        if(Ptr2 == NULL)
            Result = insertNewNode(Result , Ptr1->Power, -Ptr1->Coefficient);
        else
            Ptr2->Coefficient -= Ptr1->Coefficient;
        Ptr1 = Ptr1->Next;
    }
    return Result;
}

void deleteList(struct Node *Head)
{
    struct Node *Ptr = Head;
    while(Ptr != NULL)
    {
        Head = Ptr;
        Ptr = Ptr->Next;
        free(Head);
    }
}

void deletePolynomial(struct Node *Arr, int Length, int n)
{
    deleteList(&Arr[n-1]);
    while(n<Length)
    {
        Arr[n-1] = Arr[n];
        n += 1;
    }
}

int main()
{
    /*
     * Polynomials : An Pointer Array to Store the Linked List Start Addresses
     * Length : It is Used to Denote the Number of Polnomial in Array
     */
    struct Node *Polynomials[MAX];
    int Choice, Length, n;
    Length = 0;
    do
    {
    printf("+-----------------------------------------+\n");
    printf("| Polynomial Manipulation Using C Program |\n");
    printf("+-----------------------------------------+\n");
    printf("| 1. Create a New Polynomial              |\n");
    printf("| 2. Display a Polynomial                 |\n");
    printf("| 3. Add the Polynomials                  |\n");
    printf("| 4. Subtract the Polynomials             |\n");
    printf("| 5. Delete a Polynomial                  |\n");
    printf("| 6. Exit the Program                     |\n");
    printf("+-----------------------------------------+\n");
    printf("Enter Your Choice:");
    scanf("%d",&Choice);
    switch(Choice)
    {
        case 1:
        {
            printf("Enter the Values for the Polynomial %d\n",Length+1);
            Polynomials[Length] = createNewPolynomial();
            Length += 1;
            break;
        }
        case 2:
        {
            printf("Enter the Number of Polynomial to Display:");
            scanf("%d",&n);
            if(n>0 && n <=Length)
                displayPolynomial(Polynomials[n-1]);
            else
                printf("Index Error: Sorry! Only %d Polynomials is Available\n",Length);
            break;
        }
        case 3:
        {
            int Low, High;
            struct Node *Answer = NULL;
            printf("Enter the Range:");
            scanf("%d %d",&Low, &High);
            if(Low<1 || High>Length)
                printf("Index Error: Sorry! Only %d Polynomials is Available\n",Length);
            else
                while(Low <= High)
                {
                    Answer = addPolynomial(Answer, Polynomials[Low-1]);
                    Low+=1;
                }
            displayPolynomial(Answer);
            break;
        }
        case 4:
        {
            int Low, High;
            struct Node *Answer = NULL;
            printf("Enter the Range:");
            scanf("%d %d",&Low, &High);
            if(Low<1 || High>Length)
                printf("Index Error: Sorry! Only %d Polynomials is Available\n",Length);
            else
                while(Low <= High)
                {
                    Answer = subtractPolynomial(Answer, Polynomials[Low-1]);
                    Low+=1;
                }
            displayPolynomial(Answer);
            break;
        }
        case 5:
        {
            printf("Enter the Polynomial to be Deleted:");
            scanf("%d",&n);
            deletePolynomial(Polynomials[0], Length, n);
            Length -= 1;
            printf("The Polynomial Deleted Succesfully\n");
        }
        case 6:
        {
            while(Length>0)
            {
                deletePolynomial(Polynomials[0],Length,1);
                Length -= 1;
            }
            printf("The Memory Freed Successfully\n");
            break;
        }
    }
    }while(Choice!=6);
    return 0;
}