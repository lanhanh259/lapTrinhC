#include<stdio.h>
#include<conio.h>
#define MAX 100

void main()
{
    int h,c,a[MAX][MAX];
    printf("Nhap hang:");  scanf("%d",&h);
    printf("Nhap cot:");  scanf("%d",&c);

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0||i==h-1||j==0||j==c-1)
                printf("*\t");
            else
                printf("\t");
        }
        printf("\n");
    }

}
