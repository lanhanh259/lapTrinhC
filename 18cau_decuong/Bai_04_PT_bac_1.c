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
/*#include<stdio.h>
#include<conio.h>

int nhap(float n,char ch)
{
    printf("Nhap %c:",ch); scanf("%f",&n);
    return n;
}

void main(){
    printf("Giai phuong trinh bac nhat 2 an:");
    float x,y,a,b,c,d,e,f,dd,dx,dy;
    a = nhap(a,'a');
    b = nhap(b,'b');
    c = nhap(c,'c');
    d = nhap(d,'d');
    e = nhap(e,'e');
    f = nhap(f,'f');

    dd=a*e-d*b;
    dx=c*e-b*f;
    dy=a*f-d*c;

    if(dd==0)
    {
        if(dx==dy)
            printf("vo so nghiem");
        else
            printf("vo nghiem");
    }else
    {
        x = dx/dd;
        y = dy/dd;
        printf("Phuong trinh co nghiem: x=%.2f,y=%.2f",x,y);
    }
}

*/
