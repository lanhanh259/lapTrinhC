#include<stdio.h>
#include<conio.h>
#define MAX 100

int nhap()
{
    int n;
    while(1)
    {
        printf("Nhap n: ");
        scanf("%d",&n);
        if(n<0)
        {
            printf("n la so duong! Nhap lai n!!\n");
        }else
            break;
    }

    return n;
}
int getGiaiThua(int n)
{
    //Cach 1
    int gt=1;
    for(int i = 1; i<=n; i++)
    {
       gt=gt*i;
    }
    //Cach 2
    /*
    int gt,i;
    for(gt = i = 1; i<=n; gt*=i++);
    */
    return gt;
}

void main()
{
    int n;
    n= nhap();
    printf("%d! = %d\n",n,getGiaiThua(n));

}
