#include<stdio.h>
#include<conio.h>
#define MAX 100

void getChinhPhuong(int n)
{
    for(int i=0;i<n;i++)
    {
        int can=(int)sqrt(i);
        if(can*can==i)
            printf("%5d",i);
    }
}

void main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    getChinhPhuong(n);

}

