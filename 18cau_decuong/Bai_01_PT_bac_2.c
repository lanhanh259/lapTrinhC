#include<stdio.h>
#include<conio.h>

void main()
{
    while(1)
    {
        float a,b,c;
        float denta,can,x;
        printf("Nhap a: ");     scanf("%f",&a);
        printf("Nhap b: ");     scanf("%f",&b);
        printf("Nhap c: ");     scanf("%f",&c);
        if(a==0)
        {
            if(b==0)
            {
                if(c==0)
                    printf("Phuong trinh vo so nghiem\n");
                else
                    printf("Phuong trinh vo nghiem\n");
            }
            else
                printf("Phuong trinh co 1 nghiem la:x=%.2f\n",-c/b);
        }else
        {
            denta=(b*b)-(4*a*c);
            can = sqrt(denta);
            if(denta<0)
                printf("Phuong trinh vo nghiem\n");
            else if(denta == 0)
            {
                printf("Phuong trinh co nghiem kep x1 = x2 = %.2f\n",-b/(2*a));
            }
            else
            {
                printf("Phuong trinh co 2 nghiem la:\n");
                printf("x1 = %.2f\t",(-b+can)/(2*a));
                printf("x2 = %.2f\t",(-b-can)/(2*a));
            }

        }
    }
}
