#include <conio.h>
#include <stdio.h>
#define MAX 100

int tongMaTran(int a[][MAX],int b[][MAX],int tong[][MAX],int h,int c)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<c;j++)
            tong[i][j] =a[i][j]+b[i][j];
    }
}

void hienThiMaTran(int a[][MAX],int h,int c)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<c;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

void docMaTran(int a[][MAX],int b[][MAX],int* h,int* c)
{
    FILE* f = fopen("MATRAN.c","r");

     //Doc h c
     fscanf(f,"%d%d\n",h,c);
     //Doc ten ma tran A
     char tmp[50];
     fgets(tmp,20,f);
     //Doc ma tran A
     for(int i=0;i<*h;i++)
     {
        for(int j=0;j<*c;j++)
            fscanf(f,"%d",&a[i][j]);
     }

     //Doc ten ma tran B
     fgets(tmp,20,f);// Xuong dong
     fgets(tmp,20,f);

     //Doc ma tran B
     for(int i=0;i<*h;i++)
     {
        for(int j=0;j<*c;j++)
            fscanf(f,"%d",&b[i][j]);
     }

    fclose(f);
}

void ghiMaTran(int a[][MAX],int h,int c)
{
    FILE* f = fopen("MATRAN.c","a");

    fprintf(f,"TONG MA TRAN\n");
    for(int i=0;i<h;i++)
     {
        for(int j=0;j<c;j++)
            fprintf(f,"%5d",a[i][j]);
        fprintf(f,"\n");
     }
    fclose(f);

}
int menu()
{
    int chon;

    printf("\t\t--MENU--\n");
    printf("\t1.	Doc tep MATRAN.C\n");
    printf("\t2.	Ghi ma tran C bo sung vao cuoi tep tren \n");
    printf("\t3.	Ket thuc.\n");
    printf("\t->>Vui long chon:");
    scanf("%d",&chon);
    return chon;
}

void main()
{
    while(1)
    {
        int chon = menu();
        system("cls");

        switch(chon)
        {
            int h,c;
            int a[MAX][MAX], b[MAX][MAX],tong[MAX][MAX];
            int flag1 = 0;

            case 1:
                {
                    printf("%d",flag1);
                    docMaTran(a,b,&h,&c);
                    printf("\t MA TRAN A\n");
                    hienThiMaTran(a,h,c);
                    printf("\t MA TRAN B\n");
                    hienThiMaTran(b,h,c);
                    flag1=1;
                    break;
                }

            case 2:
                {
                    if(flag1)
                    {
                        ghiMaTran(tong,h,c);
                        printf("\tGhi xong!!\n");
                        break;
                    }else
                    {
                        printf("\tDoc ma tran truoc!!\n");
                        break;
                    }
                }

            case 3:
                {
                    printf("\n\tBYE!!!\n");
                    return;
                }
            default:
                printf("\tVui long nhap lai.!!!\n\n");
        }
        printf("\t Nhap phim bat ki ve menu.\n");
        getch();
        system("cls");
    }
}
