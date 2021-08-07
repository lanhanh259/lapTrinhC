#include<stdio.h>
#include<conio.h>
#define MAX 100

void nhapMang(int a[],int n)
{
    for(int i = 0;i<n; i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("\n");
}

void hienThiMang(int a[],int n)
{
    for(int i = 0;i<n; i++)
    {

        printf("\t%5d",a[i]);
    }
}
void ghepDaySo(int a[],int b[],int c[],int n,int m)
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i];
            i++;
        }else
        {
            c[k++]=b[j];
            j++;
        }
    }
    while(i<n)
        c[k++]=a[i++];
    while(j<m)
        c[k++]=b[j++];

}

int menu()
{
    int chon;
    printf("\t\tMENU\n");
    printf("\t1.	Nhap 2 day so nguyen theo chieu tang dan\n");
    printf("\t2.	Ghep hai day \n");
    printf("\t3.	In 3 day so \n");
    printf("\t4.    Ket thuc\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;

}

void main()
{
    int a[MAX],b[MAX],c[MAX],n,m;
    int flag1=0,flag2=0;
    while(1)
    {
        int chon = menu();
        int n,m;
        system("cls");
        switch(chon)
        {
            case 1:
            {
                printf("Nhap day thu nhat:\n");
                printf("Nhap so luong phan tu:");
                scanf("%d",&n);
                nhapMang(a,n);
                printf("Nhap day thu hai:\n");
                printf("Nhap so luong phan tu:");
                scanf("%d",&m);
                nhapMang(b,m);
                flag1 =1;
                break;
            }

            case 2:
            {
                if(flag1)
                {
                    ghepDaySo(a,b,c,n,m);
                    printf("\tGhep thanh cong!!\n");
                    flag2=1;
                    break;
                }else
                {
                    printf("Nhap day so truoc!!");
                    break;
                }
            }

            case 3:
            {
                if(flag1)
                {
                    if(flag2)
                    {
                        printf("\nDay thu nhat:");
                        hienThiMang(a,n);
                        printf("\nDay thu hai:");
                        hienThiMang(b,m);
                        printf("\nDay sau khi sap xep:");
                        hienThiMang(c,m+n);
                        break;
                    }else
                    {
                        printf("Ghep day so truoc!!");
                        break;
                    }
                }else
                {
                    printf("Nhap day so truoc!!");
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

