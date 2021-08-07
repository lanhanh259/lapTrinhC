#include<conio.h>
#include<stdio.h>
#define MAX 100

void main()
{
    int a,b;
    int chuVi,dienTich;
    do
    {
        printf("Nhap vao chu vi hinh chu nhat:");
        scanf("%d",&chuVi);

    }while(chuVi<0);
    //Cach 1:
    if(chuVi%4==0)
    {
        a=chuVi/4;
        b=chuVi/4;
    }else
    {
        a=(int)(chuVi/4);
        b=(int) (chuVi/4)+1;
    }
    //Cach 2:
    /*
    int nuaChuVi=chuVi/2;
    if(nuaChuVi%2==0)
    {
        a=nuaChuVi/2;
        b=nuaChuVi/2;
    }
    else
    {
        a=nuaChuVi/2+1;
        b=nuaChuVi/2;
    }
    */
    dienTich =a*b;

    printf("\nDien tich lon nhat cua hinh chu nhat la:%d",dienTich);

}
