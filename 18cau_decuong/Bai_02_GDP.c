#include<stdio.h>
#include<conio.h>

void main()
{
    float GDP_2014,GDP;
    float toc_do_tang;
    int nam = 2014;

    printf("Nhap GDP 2014: ");
    scanf("%f",&GDP_2014);
    GDP = GDP_2014;

    printf("Nhap vao toc do tang truong(%%): ");
    scanf("%f",&toc_do_tang);
    toc_do_tang = toc_do_tang/100;

    printf("%8s%8s\n","Nam","GDP");

    while(GDP <= (GDP_2014*2))
    {
        printf("%8d%8.2f\n",nam,GDP);
        nam++;
        GDP = GDP + GDP * toc_do_tang;
    }

}
