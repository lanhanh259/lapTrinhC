#include <stdio.h>
#include <conio.h>
#define MAX 100

typedef struct
{
    char masv[25];
    char hoTen[25];
    int namSinh;
}SinhVien;

SinhVien nhapDuLieuSV()
{
    SinhVien sv;
    printf("\tNhap maSV:");
    fflush(stdin);
    gets(sv.masv);

    printf("\tNhap hoTen:");
    fflush(stdin);
    gets(sv.hoTen);

    printf("\tNhap nam sinh:");
    fflush(stdin);
    scanf("%d",&sv.namSinh);

    return sv;

}
void hienThiDanhSachTheoBang(SinhVien sv)
{
    printf("%25s%25s%10d\n",sv.masv,sv.hoTen,sv.namSinh);
}
void hienThiDanhSach(SinhVien ds[],int n)
{
    int stt=0;
    printf("\t%5s%25s%25s%10s\n","STT","Ma SV","Ho Ten","Nam sinh");
    for(int i=0;i<n;i++)
    {
        printf("\t%5d",++stt);
        hienThiDanhSachTheoBang(ds[i]);
    }

}

void ghiFile(SinhVien ds[],int n)
{
    FILE* f =fopen("DS.C","wb");

    for(int i= 0;i<n; i++)
    {
        fwrite(&ds[i],sizeof(ds[i]),1,f);
    }
    fclose(f);
}

void docFile(SinhVien ds[],int *n)
{
    FILE* f =fopen("DS.C","rb");
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
void suaSV(SinhVien ds[],int n,char* msv)
{
    for(int i=0;i<n;i++)
    {
        if(strcmp(ds[i].masv,msv)==0)
        {
            printf("Nhap lai ten:");
            gets(ds[i].hoTen);
            printf("Nam Sinh:");
            scanf("%d",&ds[i].namSinh);
            return;
        }
    }
    printf("\tMSV khong ton tai trong ds!\n");
}

int menu()
{
    int chon;
    printf("\t1.Tao danh sach\n");
    printf("\t2.Hien danh sach\n");
    printf("\t3.Sua thong tin theo maSV\n");
    printf("\t4.Thoat\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;
}
void main()
{
    SinhVien ds[MAX];
    int n;
    while(1)
    {
        int chon = menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                printf("\tNhap so luong:");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                    ds[i] = nhapDuLieuSV();
                }
                ghiFile(ds,n);
                printf("\tGhi thanh cong\n");
                break;
            }

            case 2:
            {
                docFile(ds,&n);
                hienThiDanhSach(ds,n);
                break;
            }

            case 3:
            {
                char msv[25];
                printf("Nhap MSV muon sua:");
                fflush(stdin);
                gets(msv);
                suaSV(ds,n,msv);
                ghiFile(ds,n);

                break;
            }

            case 4:
            {
                printf("\tBYE!!\n");
                break;
            }

            default:
                printf("\tChon 1->4!!!\n");
        }
        printf("\tVe menu");
        getch();
        system("cls");
    }
}


