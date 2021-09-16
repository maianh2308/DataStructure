#include "iostream"

using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node Node;
struct stack
{
    Node *pTop;
};
typedef struct stack Stack;
Node *khoiTaoNode(int x){
    Node *p=new Node();
    p->data=x;
    p->pNext=NULL;
}
void khoiTaoStack(Stack &s){
    s.pTop==NULL;
}
bool IsEmpty(Stack s){
    if(s.pTop==NULL){
        return true;
    }
    return false;
}
bool Push(Stack &s,Node *p){
    if(p==NULL){
        return false;
    }
    if(IsEmpty(s)==true){
        s.pTop=p;
    }else{
        p->pNext=s.pTop;
        s.pTop=p;
    }
    return true;
}
bool Pop(Stack &s, int &x){
    if(IsEmpty(s)==true){
        return false;
    }else{
        Node *p=s.pTop;
        x=p->data;
        s.pTop=s.pTop->pNext;
        delete p;
    }
    return true;
}
bool Top(Stack &s,int &x){
    if(IsEmpty(s)==true){
        return false;
    }else{
        x=s.pTop->data;
    }
    return true;
}
void XuatStack(Stack s){
    while(IsEmpty(s)==false)
    {
        int x;
        Pop(s,x);
        cout << x<< " ";
    }
    
}
void NhapStack(Stack &s){
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n====================MENU==============";
        cout << "\n1. Them phan tu vao Stack";
        cout << "\n2. Xuat danh sach Stack ra man hinh";
        cout << "\n0. Ket thuc";
        cout << "\n====================END=================";
        cout << "\nNhap lua chon:";
        cin >> luachon;
        system("cls");
        if(luachon==1){
            int x;
            cout << "\nNhap phan tu can them";
            cin >> x;
            Node *p=khoiTaoNode(x);
            Push(s,p);
        }else if(luachon==2){
            XuatStack(s);
            system("pause");
        }else{
            break;
        }
    }
    
}
int main(){
    Stack s;
    khoiTaoStack(s);
    NhapStack(s);
    system("pause");
    return 0;
}
 