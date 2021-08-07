#include <stdio.h>
#include <conio.h>
#define MAX 100

void nhapMang(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&a[i]);
    }
    printf("\n");
}

void inMang(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%5d",a[i]);
    printf("\n");
}

int tongMang(int a[],int b[],int c[],int n,int m)
{
    int p=0,i=0,j=0;
    while(i<n&&j<m)
    {
        c[p++]=a[i++]+ b[j++];
    }
    while(i<n)
        c[p++]=a[i++];
    while(j<m)
        c[p++]=b[j++];

    return p;
}

float giaTriDaThuc(int a[],int n, float x)
{
    float tong=0;
    for (int i=0;i<n;i++)
    {
        tong+=(a[i]*pow(x,i)); //pow là hàm tính lũy thừa(hàm này có sẵn trong thư viện C) 
    }
    return tong;
}


int menu()
{
    int chon;
    printf("\t1.	Nhap he so cua 2 da thuc P, Q \n");
    printf("\t2.	Tinh he so cua da thuc T\n");
    printf("\t3.	In he so cua 3 da thuc P, Q, T \n");
    printf("\t4.	In gia tri cua 3 da thuc P, Q, T\n");
    printf("\t5.    Ket thuc\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;
}

void main()
{
    int a[MAX],b[MAX],c[MAX];
    int n,m,p;
    int flag1=0,flag2=0;
    while(1)
    {
        int chon=menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                printf("Nhap so luong he so P:");
                scanf("%d",&n);
                nhapMang(a,n);
                printf("Nhap so luong he so Q:");
                scanf("%d",&m);
                nhapMang(b,m);
                flag1=1;
                break;
            }

            case 2:
            {
                if(flag1)
                {
                    p=tongMang(a,b,c,n,m);
                    printf("\tTinh xong he so cua da thuc T\n");
                    flag2=1;
                    break;
                }else
                {
                    printf("Nhap he so truoc\n");
                    break;
                }
            }

            case 3:
            {
                if(flag1)
                {
                    if(flag2)
                    {
                        printf("\t%25s","Da thuc P:");
                        inMang(a,n);
                        printf("\t%25s","Da thuc Q:");
                        inMang(b,m);
                        printf("\t%25s","Da thuc T:");
                        inMang(c,p);
                        break;
                    }else
                    {
                        printf("Tinh tong he so truoc!!\n");
                        break;
                    }
                }else
                {
                    printf("Nhap he so truoc!!\n");
                    break;
                }

            }

            case 4:
            {
                if(flag1)
                {
                    if(flag2)
                    {
                        printf("%20s","Da thuc P:");
                        inMang(a,n);
                        printf("%20s","Da thuc Q:");
                        inMang(b,m);
                        printf("%20s","Da thuc T:");
                        inMang(c,p);
                        float x;
                        printf("Nhap x:");
                        scanf("%f",&x);
                        printf("\tDa thuc P: %.2f\n",giaTriDaThuc(a,n,x));
                        printf("\tDa thuc Q: %.2f\n",giaTriDaThuc(b,m,x));
                        printf("\tDa thuc T: %.2f\n",giaTriDaThuc(c,p,x));
                        break;
                    }else
                    {
                        printf("Tinh tong he so truoc!!\n");
                        break;
                    }
                }else
                {
                    printf("Nhap he so truoc!!\n");
                    break;
                }

            }
            case 5:
            {
                printf("BYE\n");
                return;
            }
            default:
                printf("Nhap 1->5!!\n");
        }
        printf("\nNhap phim bat ki de ve menu");
        getch();
        system("cls");
    }
}

