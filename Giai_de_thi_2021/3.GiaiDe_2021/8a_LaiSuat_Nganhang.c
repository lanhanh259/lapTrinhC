#include<stdio.h>
#include<conio.h>

void main()
{
    float tienGoc,tienLai;
    printf("Tien goc = ");
    scanf("%d",&tienGoc);

    tienLai=tienGoc;
    int thang=0;
    while(tienLai<(tienGoc*1.5))
    {
            tienLai=tienLai+(tienLai*0.008);
            thang++;
    }
    printf("\tSau %d thang,tien lai gap 1.5 tien goc.\n",thang);
}
