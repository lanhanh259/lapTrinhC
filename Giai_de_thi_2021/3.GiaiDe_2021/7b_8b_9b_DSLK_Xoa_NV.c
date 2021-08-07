#include<stdio.h>
#include<conio.h>
#define MAX 100

typedef struct
{
    char id[25];
    char hoTen[25];
    char chucVu[25];
    int sdt;
}NhanVien;

NhanVien nhapDuLieuNhanVien()
{
    NhanVien nv;

    printf("Nhap ID:");
    fflush(stdin);
    gets(nv.id);

    printf("Nhap ho ten:");
    fflush(stdin);
    gets(nv.hoTen);

    printf("Nhap chuc vu:");
    fflush(stdin);
    gets(nv.chucVu);

    printf("Nhap SDT:");
    fflush(stdin);
    scanf("%d",&nv.sdt);

    printf("\n");
    return nv;
}

typedef struct node
{
    NhanVien data;
    struct node* next;
}Node;

Node* first = NULL;

Node* capPhat()
{
    Node *pNode = (Node*)malloc(sizeof(Node));
    if(pNode==NULL)
    {
        printf("Khong du bo nho");
        return NULL;
    }
    return pNode;
}

Node* taoNode(NhanVien nv)
{
    Node* pNode = capPhat();
    if(pNode==NULL)
        return;
    pNode->data=nv;
    pNode->next=NULL;

    return pNode;
}

Node* taoVaNhapNode()
{
    NhanVien nv =nhapDuLieuNhanVien();
    Node* pNode = taoNode(nv);
    return pNode;
}

void themNodeDau(NhanVien nv)
{
    Node* pNode = taoNode(nv);
    if(pNode==NULL)
        return;
    pNode->next =first;
    first= pNode;

}

Node* timNodeCuoi()
{
    Node* i =first;
    while(i->next!=NULL)
        i=i->next;
    return i;
}

void themNodeCuoi(NhanVien nv)
{
    if(first==NULL)
    {
        themNodeDau(nv);
        return;
    }
    Node* pNode = taoNode(nv);
    Node* last = timNodeCuoi();
    pNode->next = NULL;
    last->next =pNode;
}

void themVaNhapNodeCuoi()
{
    NhanVien nv =nhapDuLieuNhanVien();
    themNodeCuoi(nv);
}

Node* timNodeTheoID(char* id)
{
    for(Node* i=first;i!=NULL;i=i->next)
    {
        if(strcmp(i->data.id,id)==0)
            return i;
    }
    return NULL;
}
void xoaNode(Node* delNode)
{
    if(delNode==NULL)
        return;
    if(delNode==first)
    {
        first=first->next;
        free(delNode);
    }else
    {
        Node* i = first;
        while(i->next!=delNode)
            i=i->next;
        i->next = delNode->next;
        free(delNode);

    }
}

void xoaDanhsach()
{
    while(1)
    {
        if(first!=NULL)
        {
            xoaNode(first);
        }
    }
}

void hienThiDangBang(NhanVien nv)
{
    printf("%25s%25s%25s%10d\n",nv.id,nv.hoTen,nv.chucVu,nv.sdt);
}
void hienThiDanhSach()
{
    int stt=0;
    printf("%5s%25s%25s%25s%10s\n","STT","ID","HO TEN","CHUC VU","SDT");
    for(Node* i=first;i!=NULL;i=i->next)
    {
        printf("%5d",++stt);
        hienThiDangBang(i->data);
    }
}

int menu()
{
    int chon;
    printf("\t1.Tao danh sach \n");
    printf("\t2.Hien thi danh sach\n");
    printf("\t3.Xoa\n");
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
                printf("Nhap ID muon xoa:");
                char id[25];
                fflush(stdin);
                gets(id);
                Node* pNode = timNodeTheoID(id);
                if(pNode!=NULL)
                {
                    xoaNode(pNode);
                    printf("Xoa xong!!\n\n");
                    break;
                }else
                {
                    printf("ID khong ton tai !\n");
                    break;
                }
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
