#include <conio.h>
#include<stdio.h>

void main()
{
    float a,b,c;
    printf("Nhap a:");
    scanf("%f",&a);
    printf("Nhap b:");
    scanf("%f",&b);
    printf("Nhap c:");
    scanf("%f",&c);

    if(a+b<=c||b+c<=a||c+a<=b)
        printf("Khong phai la tam giac.\n");
    else if (a==b||a==c||c==a)
    {
        if(a==b&&a==c)
            printf("La tam giac deu.\n");
        else if(a*a+b*b==c*c||c*c+b*b==a*a||a*a+c*c==b*b)
            printf("La tam giac vuong can.\n");
        else
            printf("La tam giac can.\n");
    }else if(a*a+b*b==c*c||c*c+b*b==a*a||a*a+c*c==b*b)
        printf("La tam giac vuong.");
    else
        printf("La tam giac thuong.\n");

}
