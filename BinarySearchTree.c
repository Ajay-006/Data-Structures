#include<stdio.h>
#include<stdlib.h>
int Counter=0;
struct Node
{
    int Data;
    struct Node *Left;
    struct Node *Right;
};

struct Node *createNode(int Data)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->Data = Data;
    New->Left = NULL;
    New->Right = NULL;
    return New;
}

struct Node *insert(struct Node *Root,int Data)
{
    struct Node *New = createNode(Data);
    if(Root == NULL)
        return New;
    struct Node *Ptr = Root;
    while(Ptr!=NULL)
    {
        if(Data <= Ptr->Data)
        {
            if(Ptr->Left == NULL)
            {
                Ptr->Left = New;
                break;
            }
            Ptr = Ptr->Left;
        }
        else
        {
            if(Ptr->Right == NULL)
            {
                Ptr->Right = New;
                break;
            }
            Ptr = Ptr->Right;
        }
    }
    return Root;
}

int findNoofNodes(Root)
{
    if(Root == NULL)
    {
        Counter+=1;
        findNoofNodes(Root->Left);
        findNoofNodes(Root->Right);
    }
}

void prefixTraversal(struct Node *Root)
{
    if(Root == NULL)
        return;
    printf("The Data is %d\n",Root->Data);
    prefixTraversal(Root->Left);
    prefixTraversal(Root->Right);
}

void infixTraversal(struct Node *Root)
{
    if(Root == NULL)
        return;
    infixTraversal(Root->Left);
    printf("The Data is %d\n",Root->Data);
    infixTraversal(Root->Right);
}

void postfixTraversal(struct Node *Root)
{
    if(Root == NULL)
        return;
    postfixTraversal(Root->Left);
    postfixTraversal(Root->Right);
    printf("The Data is %d\n",Root->Data);
}

int main()
{
    int Choice,Data;
    struct Node *Root = NULL;
    do
    {
    printf("+----------------------------------------------------+\n");
    printf("| Implementing the Binary Search Tree Data Structure |\n");
    printf("+----------------------------------------------------+\n");
    printf("| 1. Insert a New Node in the Binary Search Tree     |\n");
    printf("| 2. Prefix Traversal of Binary Search Tree          |\n");
    printf("| 3. Infix Traversal of Binary Search Tree           |\n");
    printf("| 4. Postfix Traversal of Binary Search Tree         |\n");
    printf("| 5. Deleting a Node in the Binary Search Tree       |\n");
    printf("| 6. Exit the Program                                |\n");
    printf("+----------------------------------------------------+\n");
    printf("Enter Your Choice:");
    scanf("%d",&Choice);
    switch(Choice)
    {
        case 1:
        {
            printf("Enter the New Node Data:");
            scanf("%d",&Data);
            Root = insert(Root,Data);
            break;
        }
        case 2:
            prefixTraversal(Root);
            break;
        case 3:
            infixTraversal(Root);
            break;
        case 4:
            postfixTraversal(Root);
            break;
    }
    }while(Choice!=6);
    return 0;
}