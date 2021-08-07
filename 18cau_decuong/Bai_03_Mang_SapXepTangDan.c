#include<stdio.h>
#include<conio.h>
#define MAX 100

void nhapMang(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\t[i] = ");
        scanf("%d",&a[i]);
    }
}

void sapXepTangDan(int a[],int n)
{
    int i,j,tmp;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                tmp = a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}
void inMang(int a[],int n)
{
    for(int i = 0; i<n; i++)
        printf("%5d",a[i]);
    printf("\n");
}

void main()
{
    int a[MAX];
    int n;
    printf("Nhap so phan tu mang: ");
    scanf("%d",&n);
    nhapMang(a,n);
    printf("\nMang ban dau:");
    inMang(a,n);
    sapXepTangDan(a,n);
    printf("\nMang sau khi sap xep:");
    inMang(a,n);
}
