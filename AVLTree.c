#include<stdio.h>
#include<stdlib.h>
int balanceFactor;
struct Node
{
    struct Node *Left;
    int Data;
    int Height;
    struct Node *Right;
};

int max(struct Node *Node1,struct Node *Node2)
{
    if(Node1 == NULL && Node2 == NULL)
        return 0;
    if(Node1 == NULL)
        return Node2->Height;
    if(Node2 == NULL)
        return Node1->Height;
    return (Node1->Height > Node2->Height)? Node1->Height : Node2->Height;
}

int isBalanced(int Val)
{
    if(Val>=-1 && Val<=1)
        return 1;
    return 0;
}

int calculateBalanceFactor(struct Node *Left, struct Node *Right)
{
    if(Left == NULL && Right == NULL)
        return 0;
    if(Left == NULL)
        return -1*Right->Height;
    if(Right == NULL)
        return Left->Height;
    return Left->Height-Right->Height;
}

struct Node *LeftRotate(struct Node *Root)
{
    struct Node *Temp = Root->Right;
    Root->Right = Temp->Left;
    Temp->Left = Root;
    Root->Height = 1 + max(Root->Left,Root->Right);
    Temp->Height = 1 + max(Temp->Left,Temp->Right);
    return Temp;    
}

struct Node *RightRotate(struct Node *Root)
{
    struct Node *Temp = Root->Left;
    Root->Left = Temp->Right;
    Temp->Right = Root;
    Root->Height = 1 + max(Root->Left,Root->Right);
    Temp->Height = 1 + max(Temp->Left,Temp->Right);
    return Temp;    
}

struct Node *createNode(int Data)
{
    struct Node *New = (struct Node*)malloc(sizeof(struct Node));
    New->Data = Data;
    New->Left = NULL;
    New->Height = 1;
    New->Right = NULL;
    return New;
}

struct Node *findMaxLeftChild(struct Node *Root)
{
    if(Root->Right == NULL)
        return Root;
    return findMaxLeftChild(Root->Right);
}

struct Node *insertNode(struct Node *Root,int Data)
{
    if(Root == NULL)
        return createNode(Data);
    if(Data <= Root->Data)
        Root->Left = insertNode(Root->Left,Data);
    else
        Root->Right = insertNode(Root->Right,Data);
    Root->Height = 1 + max(Root->Left,Root->Right);
    balanceFactor = calculateBalanceFactor(Root->Left,Root->Right); 
    if (!isBalanced(balanceFactor))
    {
        if(balanceFactor == 2)
        {
            if(calculateBalanceFactor(Root->Left->Left,Root->Left->Right) == 1)
            {
                // printf("Left-Left Imbalance...\n");
                return RightRotate(Root);
            }
            else
            {
                // printf("Left-Right Imbalance...\n");
                Root->Left = LeftRotate(Root->Left);
                return RightRotate(Root);
            }
        }
        else
        {
            if(calculateBalanceFactor(Root->Right->Left,Root->Right->Right) == -1)
            {
                // printf("Right-Right Imbalance...\n");
                return LeftRotate(Root);
            }
            else
            {
                // printf("Right-Left Imbalance...\n");
                Root->Right = RightRotate(Root->Right);
                return LeftRotate(Root);
            }
        }
    }
    return Root;
}

void prefixTraversal(struct Node *Root)
{
    if(Root == NULL)
        return;
    printf("The Data is %d\n",Root->Data,Root->Height);
    prefixTraversal(Root->Left);
    prefixTraversal(Root->Right);
}

void infixTraversal(struct Node *Root)
{
    if(Root == NULL)
        return;
    infixTraversal(Root->Left);
    printf("The Data is %d\n",Root->Data,Root->Height);
    infixTraversal(Root->Right);
}

void postfixTraversal(struct Node *Root)
{
    if(Root == NULL)
        return;
    postfixTraversal(Root->Left);
    postfixTraversal(Root->Right);
    printf("The Data is %d\n",Root->Data,Root->Height);
}

struct Node *deleteNode(struct Node *Root,int Data)
{
    if(Root == NULL)
        return NULL;
    if(Root->Data == Data)
    {
        if(Root->Left == NULL && Root->Right == NULL)
        {
            free(Root);
            return NULL;
        }
        struct Node *Temp;
        if(Root->Left == NULL)
        {
            Temp = Root->Right;
            free(Root);
            return Temp;
        }
        if(Root->Right == NULL)
        {
            Temp = Root->Left;
            free(Root);
            return Temp;
        }
        Temp = findMaxLeftChild(Root->Left);
        Root->Data = Temp->Data;
        Root->Left = deleteNode(Root->Left,Temp->Data);
    }       
    if(Data < Root->Data)
        Root->Left = deleteNode(Root->Left,Data);
    else
        Root->Right = deleteNode(Root->Right,Data);    
    Root->Height = 1 + max(Root->Left,Root->Right);
    balanceFactor = calculateBalanceFactor(Root->Left,Root->Right); 
    if (!isBalanced(balanceFactor))
    {
        if(balanceFactor == 2)
        {
            if(calculateBalanceFactor(Root->Left->Left,Root->Left->Right) >= 0)
            {
                // printf("Left-Left Imbalance...\n");
                return RightRotate(Root);
            }
            else
            {
                // printf("Left-Right Imbalance...\n");
                Root->Left = LeftRotate(Root->Left);
                return RightRotate(Root);
            }
        }
        else
        {
            if(calculateBalanceFactor(Root->Right->Left,Root->Right->Right) <= 0)
            {
                printf("Right-Right Imbalance...\n");
                return LeftRotate(Root);
            }
            else
            {
                printf("Right-Left Imbalance...\n");
                Root->Right = RightRotate(Root->Right);
                return LeftRotate(Root);
            }
        }
    }
    return Root;
}

void freeMemory(struct Node *Root)
{
    if(Root == NULL)
        return;
    freeMemory(Root->Left);
    freeMemory(Root->Right);
    free(Root);
}

int main()
{
    int Choice,Data;
    struct Node *Root = NULL;
    do
    {
    printf("+------------------------------------------+\n");
    printf("| Implementing the AVL Tree Data Structure |\n");
    printf("+------------------------------------------+\n");
    printf("| 1. Insert a New Node in the AVL Tree     |\n");
    printf("| 2. Prefix Traversal of AVL Tree          |\n");
    printf("| 3. Infix Traversal of AVL Tree           |\n");
    printf("| 4. Postfix Traversal of AVL Tree         |\n");
    printf("| 5. Deleting a Node in the AVL Tree       |\n");
    printf("| 6. Exit the Program                      |\n");
    printf("+------------------------------------------+\n");
    printf("Enter Your Choice:");
    scanf("%d",&Choice);
    switch(Choice)
    {
        case 1:
        {
            printf("Enter the New Node Data:");
            scanf("%d",&Data);
            Root = insertNode(Root,Data);
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
        case 5:
        {
            printf("Enter the Node Data:");
            scanf("%d",&Data);
            Root = deleteNode(Root,Data);
            break;
        }
        case 6:
        {
            freeMemory(Root);
            printf("Memory Successfully Freed");
            break;
        }
    }
    }while(Choice!=6);
    return 0;
}