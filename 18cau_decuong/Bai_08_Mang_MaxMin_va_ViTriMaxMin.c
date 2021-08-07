#include<stdio.h>
#include<conio.h>
#define MAX 100

void nhapMang(int a[],int n)
{
    for(int i = 0;i<n; i++)
    {
        printf("\t[%d]= ",i);
        scanf("%d",&a[i]);
    }
}

void inMang(int a[],int n)
{
    for(int i = 0;i<n; i++)
    {
        printf("\t%d",a[i]);
    }
}
int timMax(int a[],int n)
{
    int max = a[0];
    for(int i = 0;i<n; i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    return max;
}

int timMin(int a[],int n)
{
    int min = a[0];
    for(int i = 0;i<n; i++)
    {
        if(a[i]<min)
            min = a[i];
    }
    return min;
}

void timViTri(int a[],int n,int d)
{
    printf("\tO vi tri thu:");
    for(int i = 0;i<n; i++)
    {
        if(a[i]==d)
            printf("\t%d",i+1);
    }
}
void main()
{
    int a[MAX],n;
    printf("Nhap n:");  scanf("%d",&n);
    nhapMang(a,n);
    printf("Mang vua nhap la:");
    inMang(a,n);
    printf("\nGia tri lon nhat trong mang: %d \n",timMax(a,n));
    timViTri(a,n,timMax(a,n));
    printf("\nGia tri nho nhat trong mang: %d \n",timMin(a,n));
    timViTri(a,n,timMin(a,n));

}
