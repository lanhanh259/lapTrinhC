#include <stdio.h>
#include <conio.h>
#define MAX 100

int laNguyenTo(int n)
{
    if(n<2)
        return 0;

    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;

}
void inNguyenTo(int n)
{
    for(int i=0;i<n;i++)
    {
        if(laNguyenTo(i))
            printf("%5d",i);
    }
}
void main()
{
    int n;
    printf("Nhap n:");
    scanf("%d",&n);
    printf("Cac so nguyen to:");
    inNguyenTo(n);
}
