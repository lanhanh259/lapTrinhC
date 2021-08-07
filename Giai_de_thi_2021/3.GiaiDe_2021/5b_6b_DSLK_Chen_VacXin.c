#include <stdio.h>
#include<conio.h>

typedef struct
{
    int  soCCCD;
    char hoTen[25];
    int tuoi;
    char ngheNghiep[25];
}Nguoi;

Nguoi nhapDuLieuNguoi()
{
    Nguoi ng;
    printf("Nhap so CCCD:");
    fflush(stdin);
    scanf("%d",&ng.soCCCD);

    printf("Nhap ho ten:");
    fflush(stdin);
    gets(ng.hoTen);

    printf("Nhap tuoi:");
    fflush(stdin);
    scanf("%d",&ng.tuoi);

    printf("Nhap nge nghiep:");
    fflush(stdin);
    gets(ng.ngheNghiep);
    printf("\n");

    return ng;
}

typedef struct node
{
    Nguoi data;
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

Node* taoNode(Nguoi ng)
{
    Node* pNode = capPhat();
    if(pNode==NULL)
        return;
    pNode->data = ng;
    pNode->next = NULL;
    return pNode;
}
Node* taoVaNhapNode()
{
    Nguoi ng = nhapDuLieuNguoi();
    Node* pNode = taoNode(ng);
    return pNode;
}
void themNodeDau(Nguoi ng)
{
    Node* pNode = taoNode(ng);
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

void themNodeCuoi(Nguoi ng)
{
    if(first==NULL)
    {
        themNodeDau(ng);
        return;
    }
    Node* pNode= taoNode(ng);
    Node* lastNode = timNodeCuoi();
    pNode->next =NULL;
    lastNode->next= pNode;

}

void themVaNhapNodeCuoi()
{
    Nguoi ng= nhapDuLieuNguoi();
    themNodeCuoi(ng);
}


Node* timNodeTheoSoCanCuoc(int d)
{

    for(Node* i =first;i!=NULL; i=i->next)
    {
        if(i->data.soCCCD==d)
            return i;
    }
    return NULL;
}
void chenPNodeSauQNode(Node* pNode,Node* qNode)
{
    if(pNode==NULL&&qNode==NULL)
        return;
    pNode->next = qNode->next;
    qNode->next = pNode;
}
void hienThiDangBang(Nguoi ng)
{
    printf("%25d%25s%10d%25s\n",ng.soCCCD,ng.hoTen,ng.tuoi,ng.ngheNghiep);
}
void hienThiDanhSach()
{

    printf("%5s%25s%25s%10s%25s\n","STT","So CCCD","Ho Ten","Tuoi","Nghe nghiep");
    int stt=0;
    for(Node* i =first;i!=NULL;i=i->next)
    {
        printf("%5d",++stt);
        hienThiDangBang(i->data);
    }
}

int menu()
{
    int chon;
    printf("\t1.Tao danh sach.\n");
    printf("\t2.Hien thi danh sach\n");
    printf("\t3.Chen nguoi dang ki\n");
    printf("\t4.Ket thuc\n");
    printf("\t-->Vui long chon:");
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
                printf("Nhap so CCCD muon chen:");
                int scccd;
                scanf("%d",&scccd);
                Node* qNode= timNodeTheoSoCanCuoc(scccd);
                if(qNode!=NULL)
                {
                    Node* pNode=taoVaNhapNode();
                    chenPNodeSauQNode(pNode,qNode);

                }else
                {
                    printf("Khong tim thay so ccccd tren.");
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
