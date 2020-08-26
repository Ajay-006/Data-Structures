#include<stdio.h>
#include<stdlib.h>
int Size = 2;
int *Arr;
int Top = 0;

int *extendMemory()
{
    Size *= 2;
    Arr=(int*)realloc(Arr,Size);
    printf("The Array is Reallocated to %d\n",Size);
    return Arr;
}

void push(int Data)
{
    if(Top == Size)
        Arr=extendMemory();
    if(Arr == NULL)
    {
        printf("The Memory Cannot be Created\n");
        return;
    }
    Arr[Top]=Data;
}

int peek()
{
    if(Top == 0)
    {
        printf("The Stack is Empty\n");
        return -1;
    }
    return Arr[Top-1];
}

int pop()
{
    if(Top == 0)
    {
        printf("The Stack is Empty\n");
        return -1;
    }
    int Data =  Arr[Top-1];
    Arr[Top-1]=0;
    return Data;
}

void print(int Top)
{
    if(Top == 0)
    {
        printf("The Stack is Empty\n");
        return;
    }
    while(Top>0)
    {
        printf("The Data is %d\n",Arr[Top-1]);
        Top -= 1;
    }
}

int main()
{
    Arr = (int*)malloc(sizeof(int)*Size);
    int Choice,Data;
    do
    {
        printf("+---------------------------------------------+\n");
        printf("| C Program to Implement Stack Data Structure |\n");
        printf("+---------------------------------------------+\n");
        printf("| 1. Insert an Element into the Stack         |\n");
        printf("| 2. Print the Elements in the Stack          |\n");
        printf("| 3. Peek the Top Element of the Stack        |\n");
        printf("| 4. Delete the Element from the Stack        |\n");
        printf("| 5. Exit the Program                         |\n");
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
                Top += 1;
                break;
            }
            case 2:
            {
                print(Top);
                break;
            }
            case 3:
            {
                Data = peek();
                printf("The Data is %d\n",Data);
                break;
            }
            case 4:
            {
                Data = pop();
                printf("The Data is %d\n",Data);
                Top -= 1;
                break;
            }
            case 5:
            {
                free(Arr);
                break;
            }
        }
    }while(Choice!=5);
    return 0;
}