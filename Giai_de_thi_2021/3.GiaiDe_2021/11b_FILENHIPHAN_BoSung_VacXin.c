#include <stdio.h>

typedef struct
{
    int sdt;
    int soTien;
}ThongTin;

ThongTin nhapDuLieuThongTin()
{
    ThongTin tt;
    printf("SDT:");
    scanf("%d",&tt.sdt);

    printf("So tien:");
    scanf("%d",&tt.soTien);

    printf("\n");

    return tt;
}

int getTongTien(ThongTin ds[],int n)
{
    int tong=0;
    for(int i=0;i<n;i++)
    {
        tong+=ds[i].soTien;
    }
    return tong;
}
void hienThiDangBang(ThongTin tt)
{
    printf("%25d%25d\n",tt.sdt,tt.soTien);
}

void hienThiDanhSach(ThongTin ds[],int n)
{
    int stt=0;
    printf("\t\tDANH SACH UNG HO QUY VACXIN\n\n");
    printf("%5s%25s%25s\n","STT","So dien thoai","So tien");
    for(int i=0;i<n;i++)
    {
        printf("%5d",++stt);
        hienThiDangBang(ds[i]);
    }
    printf("%30s%25d\n","Tong tien",getTongTien(ds,n));
}
void ghiFile(ThongTin ds[],int n)
{
    FILE* f = fopen("SO_LIEU.c","wb");
    for(int i=0;i<n;i++)
    {
        fwrite(&ds[i],sizeof(ds[i]),1,f);
    }

    fclose(f);
}

void docFile(ThongTin ds[],int*n)
{
    FILE* f = fopen("SO_LIEU.c","rb");
    if(f==NULL)
        printf("khong co file\n");

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

void ghiBoSung(ThongTin tt)
{
    FILE* f = fopen("SO_LIEU.c","ab");

    tt=nhapDuLieuThongTin();
    fwrite(&tt,sizeof(tt),1,f);
    printf("Bo sung xong!");
    fclose(f);

}
int menu()
{
    int chon;
    printf("\t1.Nhap so lieu \n");
    printf("\t2.Bo sung so lieu\n");
    printf("\t3.Hien thi noi dung\n");
    printf("\t4.Ket thuc\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;
}

void main()
{
    ThongTin ds[100];
    int n;
    while(1)
    {
        int chon=menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                printf("Nhap so luong:");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                    ds[i]=nhapDuLieuThongTin();
                }
                ghiFile(ds,n);
                break;
            }

            case 2:
            {
                ThongTin tt;
                ghiBoSung(tt);
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
                printf("BYE\n");
                return;
            }
            default:
                printf("Nhap 1->4!!\n");
        }
        printf("\nNhap phim bat ki de ve menu");
        getch();
        system("cls");
    }
}
