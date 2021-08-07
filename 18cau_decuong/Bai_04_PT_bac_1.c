#include<stdio.h>
#include<conio.h>


void main(){
    printf("Giai phuong trinh bac nhat 2 an:\n");
    float x,y,a,b,c,d,e,f,dd,dx,dy;
    printf("\tNhap a:"); scanf("%f",&a);
    printf("\tNhap b:"); scanf("%f",&b);
    printf("\tNhap c:"); scanf("%f",&c);
    printf("\tNhap d:"); scanf("%f",&d);
    printf("\tNhap e:"); scanf("%f",&e);
    printf("\tNhap f:"); scanf("%f",&f);

    dd=a*e-d*b;
    dx=c*e-b*f;
    dy=a*f-d*c;

    if(dd==0)
    {
        if(dx==dy)
            printf("\tvo so nghiem\n");
        else
            printf("\tvo nghiem\n");
    }else
    {
        x = dx/dd;
        y = dy/dd;
        printf("\tPhuong trinh co nghiem: x=%.2f, y=%.2f\n",x,y);
    }
}
