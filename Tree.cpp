#include "iostream"

using namespace std;

struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node Node;
typedef Node* TREE;
void khoiTaoTree(TREE &t){
    t=NULL;
}
void themVaoTree(TREE &t,int x){
    if(t==NULL){
        Node *p=new Node;
        p->data=x;
        p->pLeft=NULL;
        p->pRight=NULL;
        t=p;
    }else if(x<t->data){
           themVaoTree(t->pLeft,x);
    }else if(x>t->data){
        themVaoTree(t->pRight,x);
    }
}
void HienThiTree(TREE t){
    if(t!=NULL){
        cout << t->data<< "  ";
        HienThiTree(t->pLeft);
        HienThiTree(t->pRight);
    }
}
Node* TimKiemNode(TREE t, int x){
    if(t==NULL){
        return NULL;
    }else {
        if(x<t->data){
        TimKiemNode(t->pLeft,x);
        }else 
        if(x> t->data){
        TimKiemNode(t->pRight,x);
        }else{
        return t;
    }
}
}
void XoaNode(TREE &t,int x){
    if(t==NULL){
        return;
    }else if(x>t->data){
        XoaNode(t->pRight,x);
    }else if(x<t->data){
        XoaNode(t->pLeft,x);
    }else{
    Node *x=t;
    if(t->pLeft==NULL){
        t=t->pRight;
    }else if(t->pRight==NULL){
        t=t->pLeft;
    }
    delete x;}
}
void Menu(TREE &t){
    while (true)
    {
        int luachon;
        system("cls");
        cout << "\n==================MENU======================";
        cout << "\n1. Nhap Vao Cay";
        cout << "\n2. Hien Thi Cay";
        cout << "\n3. Tim kiem Node";
        cout << "\n4. Xoa Node 1 con va node la";
        cout << "\n5. Xoa Node 2 con";
        cout << "\n0. Ket Thuc";
        cout << "\n=================END========================";
        cout << "\nNhap Lua Chon:";
        cin >> luachon;
        system("cls");
        if(luachon<0||luachon>5){
            cout << "\nNhap Sai. Vui Long Nhap Lai!";
        }else if(luachon==1){
            int x;
            cout << "\nNhap vao x:";
            cin >> x;
            themVaoTree(t,x);
        }else if(luachon==2){
            HienThiTree(t);
            system("pause");
        }else if(luachon==3){
            int x;
            cout << "\nNhap Vao Node Can Tim:";
            cin >> x;
            Node *p= TimKiemNode(t,x);
            if(p==NULL){
                cout << "\n"<< x<< "Khong Ton Tai Trong Cay";
            }else{
                cout << "\n"<< x<< "Ton Tai Trong Cay";
            }
            system("pause");
        }
        else if(luachon==4){
            int x;
            cout << "\nNhap Vao Node Can Xoa:";
            cin >> x;
            XoaNode(t,x);
        }
        else if(luachon==5){

        }
        else{
            break;
        }
    }
    
}
int main(){
    TREE t;
    khoiTaoTree(t);
    Menu(t);
}
