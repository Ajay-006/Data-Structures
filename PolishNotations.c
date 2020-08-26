#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char Data;
    struct Node *Next;
};
struct Node *Top = NULL;

int get_precedence(char c)
{
    // If Operator is + or - return Precedence as 1 else 2
    if(c == 43 || c == 45)
        return 1;
    return 2;
}

int isOperator(char c)
{
    // Check Whether the Given Characher is an Operator 
    if(c == 43 || c == 45 || c == 47 || c == 42 || c == 37 || c == 40 || c == 41)
        return 1;
    return 0;
}

int isSwap(char c1, char c2)
{
    // Check Whether we are Comparing Brackets or null Characker with Other Characters
    if(c1 == 0 || c1 == 40 || c2 == 40)
        return 0;
    // If the Precedence of Already Presented Character is Higher or Equal to the New Char then We had to Swap
    if(get_precedence(c1) >= get_precedence(c2))
        return 1;
    return 0;
}

void push(char Operator)
{
    struct Node *New = (struct Node *)malloc(sizeof(struct Node));
    if(New == NULL)
    {
        printf("Memory Overflow....\n");
        return;
    }
    New->Data = Operator;
    New->Next = Top;
    Top = New;
}

void print()
{
    if(Top == NULL)
    {
        printf("The Stack is Empty\n");
        return;
    }
    struct Node *Ptr = Top;
    while(Ptr != NULL)
    {
        printf("The Data is %c\n",Ptr->Data);
        Ptr = Ptr->Next;
    }
}

char peek()
{
    if(Top == NULL)
        return '\0';
    return Top->Data;
}

char pop()
{
    if(Top == NULL)
        return '\0';
    char Data = Top->Data;
    struct Node *Temp = Top;
    Top = Top->Next;
    free(Temp);
    return Data;
}

void infixtopostfix(char* Expr,char *Result, int Length)
{
    int i,j=0;
    char Temp;
    for(i=0; i<Length; i++)
    {
        // Check the Character is a Operator or Not
        if(isOperator(Expr[i]) == 1)
        {
            // Check the Operator is Closing Bracket
            if(Expr[i] == 41)
            {
                Temp = pop();
                while(Temp != 40)
                {
                    Result[j] = Temp;
                    Temp = pop();
                    j+=1;
                }
            }
            // Checking whether the New Operator is Precedence is lower than already Present Operator
            else if(isSwap(peek(), Expr[i]) == 1)
            {
                Result[j] = pop();
                j += 1;
                push(Expr[i]);
            }

            else
                push(Expr[i]);
        }
        else
        {
            Result[j] = Expr[i];
            j += 1;
        }
    }
    while(Top!=NULL)
    {
        Result[j] = pop();
        j += 1;
    }
    Result[j]='\0';
}

void reverse(char *Expr, char *Result, int Length)
{
    int i = 0;
    while(Length>0)
    {
        if(Expr[Length-1] == 40)
            Result[i] = 41;
        else if(Expr[Length-1] == 41)
            Result[i] = 40;
        else
            Result[i] = Expr[Length-1];
        i += 1;
        Length -= 1;
    }   
    Result[i]='\0';
}

void infixtoprefix(char *Expr, char *Result, int Length)
{
    char Temp[Length];
    reverse(Expr, Temp, Length);
    infixtopostfix(Temp, Temp, Length);
    Length = 0;
    while(Temp[Length]!='\0')
        Length+=1;
    reverse(Temp, Result, Length);
}

int main()
{
    char *Expression, *Result;
    int Length, i, Choice;
    Length = 0;
    printf("Enter the Expression:");
    scanf("%s",Expression);
    for(i=0; Expression[i]!='\0'; i++)
        Length+=1;
    Result = (char*)malloc(sizeof(char)*Length);        
    printf("+-------------------------------------+\n");
    printf("| Infix to Prefix,Postfix Using Stack |\n");
    printf("+-------------------------------------+\n");
    printf("| 1. Convert Infix to Prefix          |\n");
    printf("| 2. Convert Infix to Postfix         |\n");
    printf("| 3. Exit the Program                 |\n");
    printf("+-------------------------------------+\n");
    printf("Enter your Choice:");
    scanf("%d",&Choice);
    switch(Choice)
    {
        case 1:
        {
            infixtoprefix(Expression, Result, Length);
            printf("The Prefix Expression is %s\n",Result);
            break;
        }
        case 2:
        {
            infixtopostfix(Expression, Result, Length);
            printf("The Postfix Expression is %s\n",Result);
            break;
        }
    }
    return 0;
}