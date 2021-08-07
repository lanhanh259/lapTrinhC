#include<stdio.h>
#include<conio.h>

//Cach 1:
/*
void main()
{
    int a,b,i;
    printf("Nhap 2 so:");
    scanf("%d%d",&a,&b);
    for(i = a>b?a:b;; i++)
        if(i%a==0&&i%b==0)
            break;
    printf("BCNN(%d,%d) la: %d ",a,b,i);
}
*/

//Cach 2:
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
    printf("BCNN(%d,%d) =%d\n",a,b,a*b/UCLN(a,b));
}
