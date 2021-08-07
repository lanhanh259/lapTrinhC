#include <stdio.h>
#include <conio.h>

void nhapMang(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&a[i]);
    }
}
int getTBC(int a[],int n)
{
    int tong =0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>5)
        {
            if(a[i]%2==0)
                tong=tong+a[i];
        }
    }
    return tong;
}

void main()
{
    int a[100];
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    nhapMang(a,n);
    printf("TBC cac so chan(>5) trong day la: %d",getTBC(a,n));
}
