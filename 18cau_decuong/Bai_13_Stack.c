#include<stdio.h>
#include<conio.h>
#define MAX 100

int top=-1;
int uStack[MAX];

int isEmpty()
{
    return top==-1;
}
int isFull()
{
    return top==MAX-1;
}

int push(int d)
{
    if(isFull())
        return 0;
    top++;
    uStack[top]= d;
    return 1;
}
int pop()
{
    int d;
    if(isEmpty())
        return -1;
    d=uStack[top];
    top--;
    return d;
}


void chuyenCoSo(int n,int heso)
{
    //Lam rong stack
    top = -1;

    //Luu cac phan du vao stack
    while(n!=0)
    {
        push(n%heso);
        n/=heso;
    }
}

void hienThiKetQua()
{
    //in toan bo stack ra ngoai
    while(!isEmpty())
    {
        int n= pop();
        if(n<10)
            printf("%d ",n);
        else
            printf("%c",n-10+'a');
    }
    printf("\n");

}
int menu()
{
    int chon;
    printf("\t1.    Nhap n\n");
    printf("\t2.	Chuyen mot so nguyen duong sang he 2\n");
    printf("\t3.	Chuyen mot so nguyen duong sang he 8\n");
    printf("\t4.	Chuyen mot so nguyen duong sang he 16\n");
    printf("\t5.	Ket thuc\n");
    printf("\t-->Chon:");
    scanf("%d",&chon);
    return chon;

}
void main()
{
    while(1)
    {
        int chon=menu();
        system("cls");
        int n;
        switch(chon)
        {
            int flag=0;
            case 1:
            {
                printf("\nNhap n:");
                scanf("%d",&n);
                printf("Nhap xong!!");
                flag=1;
                break;
            }
            case 2:
            {
                if(flag)
                {
                    chuyenCoSo(n,2);
                    hienThiKetQua();
                    break;
                }else
                {
                    printf("\tNhap n truoc!!\n\n");
                    break;
                }
            }
            case 3:
            {

                if(flag)
                {
                    chuyenCoSo(n,8);
                    hienThiKetQua();
                    break;
                }else
                {
                    printf("\tNhap n truoc!!\n\n");
                    break;
                }
            }
            case 4:
            {
                if(flag)
                {
                    chuyenCoSo(n,16);
                    hienThiKetQua();
                    break;
                }else
                {
                    printf("\tNhap n truoc!!\n\n");
                    break;
                }
            }
            case 5:
            {
                printf("\tBYE!!");
                return;
            }
            default:
                printf("\tNhap lai!!!\n");
        }
        printf("Nhap phim bat ki ve menu.\n");
        getch();
        system("cls");
    }
}

