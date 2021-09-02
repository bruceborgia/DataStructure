//线性表 顺序表和链表

#include "iostream"
using namespace std;

#define maxSize 100

typedef struct DLNode
{
    int data;
    struct DLNode *prior;//前驱
    struct DLNode *next;//后继
}DLNode;

void createDlist_Tail(DLNode *&L, int a[], int n)//尾插法建立双链表
{
    DLNode *s,*r;//r指向终端节点
    int i;
    L = (DLNode*)malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r=L;
    for (int i = 0; i < n; ++i)
    {
        s = (DLNode*)malloc(sizeof(DLNode));//创建新节点
        s->data = a[i];
        //下边3句将s插入到L的尾部，并且r指向s，
        r->next = s;
        s->prior = r;
        r = s;
    }


}

DLNode* findNode(DLNode *C, int x)
{
    DLNode * p = C->next;
    while (p != NULL)
    {
        if (p->data == x)
        {
            break;
        }
        p = p->next;
    }
    return p;//如果找到，则p中的内容是节点地址，如果没找到，则p中内容是NULL；
}

void insertDLNode(DLNode *&L,int x, int n)//在第n个位置上插入x
{
    DLNode *s,*p;

    p=L;
    for (int i = 0; i < n-1; ++i) {
        p=p->next;
    }
    s = (DLNode*)malloc(sizeof(DLNode));
    s->data=x;
    //插入操作
    s->next = p->next;
    s->prior = p;
    p->next = s;
    if (s->next!= NULL)
    {
        s->next->prior=s;//p指向的不是最后一个节点
    }

}

void deleteDLNode(DLNode *&L, int n, int &e)//删除第n个位置节点，并用e返回
{
    DLNode*p,*q;
    p=L;
    for (int i = 0; i < n-1; ++i) {
        p = p->next;
    }
    q=p->next;
    p->next=q->next;
    q->next->prior=p;
    e=q->data;
    free(q);
}

void showDlist(DLNode *l)
{
    l=l->next;
    while (l->next!=NULL)
    {
        cout<<l->data<<"\t";
        l=l->next;
    }
    cout<<l->data<<endl;
}

int main(){

    int a[5] = {2,5,6,8,9};
    int e;
    DLNode *l1;
    DLNode *p;
    createDlist_Tail(l1,a,5);
    showDlist(l1);
    p= findNode(l1,8);
    cout<<p->data<<endl;
    insertDLNode(l1,7,4);//插入
    showDlist(l1);
    deleteDLNode(l1,4,e);//删除
    cout<<"e:"<<e<<"\n";
    showDlist(l1);

    return 0;
}

