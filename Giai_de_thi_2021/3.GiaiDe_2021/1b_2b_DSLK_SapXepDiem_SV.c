#include <stdio.h>
#include<conio.h>

typedef struct
{
    char soBaoDanh[25];
    char hoTen[25];
    float toan;
    float ly;
    float anh;
    float tongDiem;
}SinhVien;

SinhVien nhapDuLieuSinhVien()
{
    SinhVien sv;
    printf("Nhap so bao danh:");
    fflush(stdin);
    gets(sv.soBaoDanh);

    printf("Nhap ho ten:");
    fflush(stdin);
    gets(sv.hoTen);

    printf("Nhap toan:");
    fflush(stdin);
    scanf("%f",&sv.toan);

    printf("Nhap ly:");
    fflush(stdin);
    scanf("%f",&sv.ly);

    printf("Nhap anh:");
    fflush(stdin);
    scanf("%f",&sv.anh);
    printf("\n");

    sv.tongDiem = sv.toan+sv.ly+sv.anh;
    return sv;
}

typedef struct node
{
    SinhVien data;
    struct node* next;
}Node;

Node* first = NULL;

Node* capPhat()
{
    Node* pNode = (Node*)malloc(sizeof(Node));
    if(pNode==NULL)
    {
        printf("Khong du bo nho cap phat.\n");
        return NULL;
    }
    return pNode;
}

Node* taoNode(SinhVien sv)
{
    Node* pNode = capPhat();
    if(pNode==NULL)
        return;
    pNode->data = sv;
    pNode->next = NULL;
    return pNode;
}

void themNodeDau(SinhVien sv)
{
    Node* pNode = taoNode(sv);
    if(pNode==NULL)
        return;
    pNode->next = first;
    first = pNode;
}
Node* timNodeCuoi()
{
    Node* i = first;
    while(i->next!=NULL)
        i=i->next;
    return i;
}

void themNodeCuoi(SinhVien sv)
{
    if(first==NULL)
    {
        themNodeDau(sv);
        return;
    }
    Node* pNode= taoNode(sv);
    Node* lastNode = timNodeCuoi();
    pNode->next =NULL;
    lastNode->next= pNode;

}

void themVaNhapNodeCuoi()
{
    SinhVien sv= nhapDuLieuSinhVien();
    themNodeCuoi(sv);
}

void hienThiDangBang(SinhVien sv)
{
    printf("%25s%25s%10.2f%10.2f%10.2f%10.2f\n",sv.soBaoDanh,sv.hoTen,sv.toan,sv.ly,sv.anh,sv.tongDiem);
}
void hienThiDanhSach()
{

    printf("%5s%25s%25s%10s%10s%10s%10s\n","STT","So Bao Danh","Ho Ten","Diem toan","Diem ly","Diem anh","tong");
    int stt=0;
    for(Node* i =first;i!=NULL;i=i->next)
    {
        printf("%5d",++stt);
        hienThiDangBang(i->data);
    }
}
void sapXepDiemToan()
{
    for(Node* i=first;i!=NULL;i=i->next)
    {
        for(Node* j=i->next;j!=NULL;j=j->next)
        {
            if(i->data.toan > j->data.toan)
            {
                SinhVien tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void sapXepDiemLy()
{
    for(Node* i=first;i!=NULL;i=i->next)
    {
        for(Node* j=i->next;j!=NULL;j=j->next)
        {
            if(i->data.ly > j->data.ly)
            {
                SinhVien tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void sapXepDiemAnh()
{
    for(Node* i=first;i!=NULL;i=i->next)
    {
        for(Node* j=i->next;j!=NULL;j=j->next)
        {
            if(i->data.anh > j->data.anh)
            {
                SinhVien tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void sapXepDiemTong()
{
    for(Node* i=first;i!=NULL;i=i->next)
    {
        for(Node* j=i->next;j!=NULL;j=j->next)
        {
            if(i->data.tongDiem > j->data.tongDiem)
            {
                SinhVien tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}
int menu()
{
    int chon;
    printf("\t1.Tao danh sach.\n");
    printf("\t2.Hien thi danh sach\n");
    printf("\t3.Sap xep diem thi\n");
    printf("\t4.Ket thuc\n");
    printf("\t-->Vui long chon:");
    scanf("%d",&chon);
    return chon;
}

int sapxep()
{
    int chon;
    printf("\t1.Sap xep danh sach theo diem Toan.\n");
    printf("\t2.Sap xep danh sach theo diem Ly\n");
    printf("\t3.Sap xep danh sach theo diem Anh\n");
    printf("\t4.Sap xep danh sach theo diem tong\n");
    scanf("%d",&chon);
    return chon;
}
void main()
{
    while(1)
    {
        int chon=menu();
        system("cls");
        switch(chon)
        {
            case 1:
            {
                int n;
                first = NULL;
                printf("Nhap so luong:");
                scanf("%d",&n);
                while(n--)
                {
                    themVaNhapNodeCuoi();
                }
                break;
            }

            case 2:
            {
                hienThiDanhSach();
                break;
            }

            case 3:
            {

                int chon=sapxep();
                system("cls");
                switch(chon)
                {
                    case 1:
                    {
                        printf("\tSap xep theo diem Toan\n");
                        sapXepDiemToan();
                        hienThiDanhSach();
                        break;
                    }
                    case 2:
                    {
                        printf("\tSap xep theo diem Ly\n");
                        sapXepDiemLy();
                        hienThiDanhSach();
                        break;
                    }
                    case 3:
                    {
                        printf("\tSap xep theo diem Anh\n");
                        sapXepDiemAnh();
                        hienThiDanhSach();
                        break;
                    }
                    case 4:
                    {
                        printf("\tSap xep diem tong\n");
                        sapXepDiemTong();
                        hienThiDanhSach();
                        break;
                    }
                    default:
                        printf("Nhap 1->4!!\n");
                }
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
        printf("Nhap phim bat ki de ve menu");
        getch();
        system("cls");
    }
}
