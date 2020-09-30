#include<stdio.h>
int centuryCode[] = {6,4,2,0};
int monthCode[] = {1,4,4,0,2,5,0,3,6,1,4,6};
int calculateCenturyCode(int i)
{
    // printf("The Century is %d and Index is %d\n",i,i%4);
    return centuryCode[i%4];
}
int calculateMonthCode(int i)
{
    return monthCode[i-1];
}
int main()
{
    int d,m,y,Res;
    printf("Enter a Date [dd/mm/yyyy]: ");
    scanf("%d/%d/%d",&d,&m,&y);
    // printf("The Month Code & Century Code is %d & %d",calculateMonthCode(m),calculateCenturyCode(y/100));
    Res = d + calculateMonthCode(m) + calculateCenturyCode(y/100) + y%2 + y/4;
    printf("The Res is %d\n",Res);
    Res %= 7;
    switch(Res)
    {
        case 0:
            printf("The Day at %d/%d/%d is Saturday\n",d,m,y);
            break;
        case 1:
            printf("The Day at %d/%d/%d is Sunday\n",d,m,y);
            break;
        case 2:
            printf("The Day at %d/%d/%d is Monday\n",d,m,y);
            break;
        case 3:
            printf("The Day at %d/%d/%d is Tuesday\n",d,m,y);
            break;
        case 4:
            printf("The Day at %d/%d/%d is Wednesday\n",d,m,y);
            break;
        case 5:
            printf("The Day at %d/%d/%d is Thursday\n",d,m,y);
            break;
        case 6:
            printf("The Day at %d/%d/%d is Friday\n",d,m,y);
            break;
    }
    return 0;
}