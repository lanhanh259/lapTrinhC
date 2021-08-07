#include<conio.h>
#include<stdio.h>
#define MAX 100

void main()
{
    int a;
    int chuVi,dienTich;
    do
    {
        printf("Nhap vao chu vi hinh chu nhat:");
        scanf("%d",&chuVi);

    }while(chuVi<0);

    a=chuVi/4;
    dienTich =a*a;

    printf("\nDien tich lon nhat cua hinh chu nhat la:%d",dienTich);

}
