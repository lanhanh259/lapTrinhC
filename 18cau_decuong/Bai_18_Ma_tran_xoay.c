#include<stdio.h>
#include<conio.h>
#define MAX 100

int nhapSoNguyenDuong()
{
    int n;
    do{
        printf("\tNhap n:");
        scanf("%d",&n);
        if(n<0)
            printf("Nhap n>=0. Nhap lai:");
    }while(n<0);
    return n;
}
void tinhMaTran(int a[][MAX],int n)
{
    int i,j=1;
    int top = 0,left = 0;
    int bot = n-1,right = n-1;

    while(1)
    {
        //Dien tu trai qua phai
        for(i=left;i<=right;i++)
            a[top][i]=j++;
        top++;

        if(j>n*n)
            break;

        //Dien tu tren xuong duoi
        for(i=top; i<=bot;i++)
            a[i][right]=j++;
        right--;

        if(j>n*n)
            break;

        //Dien tu phai qua trai
        for(i=right; i>=left;i--)
            a[bot][i]=j++;
        bot--;

        if(j>n*n)
            break;

        //Dien tu duoi len tren
        for(i=bot; i>=top;i--)
            a[i][left]=j++;
        left++;

        if(j>n*n)
            break;

    }
}
void hienThiMaTran(int a[][MAX],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%5d",a[i][j]);
        printf("\n");
    }
}

int menu()
{
    int chon;
    printf("\t\t--MENU--\n");
    printf("\t1. Nhap n\n");
    printf("\t2. Tinh ma tran\n");
    printf("\t3. Hien thi ma tran\n");
    printf("\t0.Thoat\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;

}

void main()
{
    int a[MAX][MAX],n;
    int flag1=0,flag2=0;
    while(1)
    {
        int chon = menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                n=nhapSoNguyenDuong();
                flag1=1;
                break;
            }

            case 2:
            {
                if(flag1)
                {
                    tinhMaTran(a,n);
                    printf("\tTinh ma tran xong!\n");
                    flag2=1;
                    break;
                }else
                {
                    printf("\tNhap n truoc!!\n");
                    break;
                }
            }

            case 3:
            {
                if(flag1)
                {
                    if(flag2)
                    {
                        printf("\tMa tran xoay cap %d\n\n",n);
                        hienThiMaTran(a,n);
                        break;
                    }else
                    {
                        printf("\tTinh ma tran truoc!!\n");
                        break;
                    }

                }else
                {
                    printf("Nhap n truoc!!\n");
                    break;
                }
            }

            case 4:
            {
                printf("\n\tBYE!!!\n");
                return;
            }
            default:
                printf("\tVui long nhap lai.!!!\n\n");
        }
        printf("\n\t Nhap phim bat ki ve menu.\n");
        getch();
        system("cls");
    }
}

