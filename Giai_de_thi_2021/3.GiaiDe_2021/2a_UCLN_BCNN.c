#include <stdio.h>
#include <conio.h>

int UCLN(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
void main()
{
    int a,b;
    printf("Nhap a:");  scanf("%d",&a);
    printf("Nhap b:");  scanf("%d",&b);
    printf("UCLN(%d,%d) =%d\n",a,b,UCLN(a,b));
    printf("BCNN(%d,%d) =%d\n",a,b,a*b/UCLN(a,b));
}
