#include <stdio.h>
#include <conio.h>
#define MAX 100

typedef struct
{
    char tenHang[25];
    int donGia;
    int soLuong;
    int thanhTien;
}MatHang;

MatHang nhapDuLieuMatHang()
{
    MatHang mh;

    printf("\tNhap ten hang:");
    fflush(stdin);
    gets(mh.tenHang);

    printf("\tNhap don gia:");
    fflush(stdin);
    scanf("%d",&mh.donGia);

    printf("\tNhap so luong:");
    fflush(stdin);
    scanf("%d",&mh.soLuong);

    mh.thanhTien =mh.donGia *mh.soLuong;
    return mh;
}
void nhapDanhSach(MatHang ds[],int n)
{
    for(int i=0;i<n;i++)
    {
        ds[i] = nhapDuLieuMatHang();
    }
    printf("\n");

}

int getTongTien(MatHang ds[],int n)
{
    int tong =0;
    for(int i=0;i<n;i++)
    {
        tong+=ds[i].thanhTien;
    }
    return tong;
}
void hienThiDanhSach_dangBang(MatHang mh)
{
    printf("%25s%10d%10d%10d\n",mh.tenHang,mh.donGia,mh.soLuong,mh.thanhTien);
}
void hienThiDanhSach(MatHang ds[],int n)
{

    printf("\t%5s%25s%10s%10s%10s\n","STT","Ten hang","Don gia","So luong","Thanh tien");
    int stt=0;
    for(int i=0;i<n;i++)
    {
        printf("\t%5d",++stt);
        hienThiDanhSach_dangBang(ds[i]);
    }
    printf("\t%50s%10d","Tong tien",getTongTien(ds,n));
}

void ghiFile(MatHang ds[],int n)
{
    FILE* f= fopen("solieu.txt","wb");

    for(int i=0;i<n;i++)
    {
        fwrite(&ds[i],sizeof(ds[i]),1,f);
    }

    fclose(f);


}
void docFile(MatHang ds[],int *n)
{
    FILE* f= fopen("solieu.txt","rb");

    int i=0;
    while(1)
    {
        fread(&ds[i],sizeof(ds[i]),1,f);
        if(feof(f))
           break;
        i++;
    }
    *n=i;

    fclose(f);
}

void ghiMatHangVaoCuoi(MatHang mh)
{
    FILE* f= fopen("solieu.txt","ab");

    mh=nhapDuLieuMatHang();
    fwrite(&mh,sizeof(mh),1,f);

    fclose(f);
}

int menu()
{
    int chon;
    printf("\t\t--MENU--\n");
    printf("\t1.	Nhap so lieu ban hang len tep\n");
    printf("\t2.	Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.C\n");
    printf("\t3.	Hien thi noi dung tep SO_LIEU.C\n");
    printf("\t4.	Ket thuc\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;

}

void main()
{
    int n;
    MatHang ds[100];
    while(1)
    {
        int chon = menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                printf("\tNhap so luong mat hang:");
                scanf("%d",&n);
                nhapDanhSach(ds,n);
                ghiFile(ds,n);
                printf("\tThem vao tep thanh cong!!!\n");
                break;
            }

            case 2:
            {
                MatHang mh;
                ghiMatHangVaoCuoi(mh);

                break;
            }

            case 3:
            {
                docFile(ds,&n);
                hienThiDanhSach(ds,n);
                break;
            }

            case 4:
            {
                printf("\t\tBYE!!\n");
                return;
            }
            default:
                printf("\tVui long nhap lai!!!\n");
        }

        printf("\n\n\t Nhap phim bat ki de tro ve!!\n");
        getch();
        system("cls");
    }
}

