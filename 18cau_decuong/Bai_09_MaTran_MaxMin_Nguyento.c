#include<stdio.h>
#include<conio.h>
#define MAX 100

void nhapMaTran(int a[][MAX],int h,int c)
{
    for(int i = 0;i<h; i++)
    {
        for(int j= 0;j< c; j++)
        {
            printf("\t[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
}

void hienThiMatran(int a[][MAX],int h,int c)
{
    for(int i = 0;i<h; i++)
    {
        for(int j= 0;j< c; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int getMax(int a[][MAX],int h,int c)
{
    int max = a[0][0];
    for(int i = 0;i<h; i++)
    {
        for(int j= 0;j< c; j++)
        {
            if(a[i][j]>max)
                max = a[i][j];
        }
    }
    return max;
}

int getMin(int a[][MAX],int h,int c)
{
    int min = a[0][0];
    for(int i = 0; i<h; i++)
    {
        for(int j= 0; j< c; j++)
        {
            if(a[i][j]< min)
                min = a[i][j];
        }
    }
    return min;
}
int laNguyenTo(int n)
{
    if(n<2)
        return 0;
    int i;
    for(i=2;i<n; i++)
    {
        if(n%i==0)
            return 0;
    }
        return 1;
}
void inNguyenTo(int a[MAX][MAX],int h,int c)
{
    printf("\nCac so nguyen to la:");
    for(int i = 0; i<h; i++)
    {
        for(int j= 0; j< c; j++)
        {
            if(laNguyenTo(a[i][j]))
                printf("\t%d",a[i][j]);
        }
    }
}
int tongNguyenTo(int a[MAX][MAX],int h,int c)
{
    int tong=0;
    for(int i = 0; i<h; i++)
    {
        for(int j= 0; j< c; j++)
        {
            if(laNguyenTo(a[i][j]))
                tong+=a[i][j];
        }
    }
    return tong;
}
void main()
{
    int a[MAX][MAX],h,c;
    printf("Nhap hang:");  scanf("%d",&h);
    printf("Nhap cot:");  scanf("%d",&c);
    nhapMaTran(a,h,c);
    printf("Ma tran vua nhap la:\n");
    hienThiMatran(a,h,c);
    printf("Gia tri lon nhat trong mang: %d \n",getMax(a,h,c));
    printf("Gia tri nho nhat trong mang: %d \n",getMin(a,h,c));
    inNguyenTo(a,h,c);
    printf("\nTong cac so nguyen to trong mang:%d \n",tongNguyenTo(a,h,c));
}

