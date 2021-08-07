#include<stdio.h>
#include<conio.h>
#define MAX 100

int nhapMaTran(int a[][MAX],int h,int c)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<c;j++){
            printf("\t[i][j]= ");
            scanf("%d",&a[i][j]);
        }
        printf("\n");
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
void tichMaTran(int a[][MAX], int b[][MAX], int tich[][MAX], int h1, int n, int c2)
{
    int tong;
    for(int i=0; i<h1;i++)
    {
        for(int j=0; j<c2;j++)
        {
            tong=0;
            for(int k=0;k<n;k++)
                tong+=(a[i][k]*b[k][j]);
            tich[i][j]=tong;
        }
    }
}
int menu()
{
    int chon;
    printf("\t\tMENU\n");
    printf("\t1.Nhap 2 ma tran\n");
    printf("\t2.Tinh tich 2 ma tran\n");
    printf("\t3.Hien thi 3 ma tran\n");
    printf("\t4.Ket thuc\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;
}
void main()
{
    int a[MAX][MAX],b[MAX][MAX],tich[MAX][MAX];
    int h1,n,c2,kt;
    int flag1=0,flag2=0;

    while(1)
    {
        int chon= menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                printf("Nhap ma tran thu nhat:\n");
                printf("\tNhap so hang: ");
                scanf("%d",&h1);
                printf("\tNhap so cot: ");
                scanf("%d",&n);
                nhapMaTran(a,h1,n);

                printf("Nhap ma tran thu hai:\n");
                do{
                    printf("\tNhap so hang: ");
                    scanf("%d",&kt);

                    if(kt!=n)
                        printf("So hang phai bang so cot ma tran truoc!!\n");

                }while(kt!=n);

                printf("\tNhap so cot: ");
                scanf("%d",&c2);
                nhapMaTran(b,n,c2);
                flag1=1;
                break;
            }

            case 2:
            {
                if(flag1)
                {
                    tichMaTran(a,b,tich,h1,n,c2);
                    printf("\tDa tinh tich ma tran.\n");
                    flag2=1;
                    break;
                }else
                {
                    printf("\tNhap ma tran truoc!!\n");
                    break;
                }
            }

            case 3:
            {
                if(flag1)
                {
                    if(flag2)
                    {
                        printf("Ma tran thu nhat\n");
                        hienThiMaTran(a,h1,n);
                        printf("Ma tran thu hai\n");
                        hienThiMaTran(b,n,c2);
                        printf("Tich hai ma tran\n");
                        hienThiMaTran(tich,h1,c2);
                        break;
                    }
                    else
                    {
                        printf("\tTinh ma tran truoc!!\n");
                        break;
                    }
                }else
                {
                    printf("\tNhap ma tran truoc!!\n");
                    break;
                }
            }
            case 4:
            {
                printf("\t\tBYE!!");
                exit(0);
            }
            default:
                printf("Chon lai!!");
        }
        printf("\tBam phim bat ky de ve menu\n");
        getch();
        system("cls");
    }
}
