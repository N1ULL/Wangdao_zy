#include <stdio.h>
int main()
{
    int year,a;
    scanf("%d",&year);
    if(year%400==0)
        a=1;
    else
    {
        if(year%4==0&&year%100!=0)
            a=1;
        else
            a=0;
    }
    if(a==1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}