#include<stdio.h>
#include<conio.h>
#define MAX 100


void nhapMang(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&a[i]);
    }
}

int dem(int a[],int n,int x)
{
    int dem=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            dem=dem+1;
    }
    return dem;
}

void main()
{
    int x,n;
    int a[MAX];
    printf("Nhap so luong phan tu mang:");
    scanf("%d",&n);
    nhapMang(a,n);

    printf("\nNhap x:");
    scanf("%d",&x);
    printf("%d xuat hien %d lan\n",x,dem(a,n,x));
    printf("Khong co %d trong danh sach",x);
}
