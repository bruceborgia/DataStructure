//线性表 顺序表和链表

#include "iostream"
using namespace std;

#define maxSize 100

typedef struct Sqlist//顺序表结构体
{
    int data[maxSize];
    int length;


}Sqlist;

typedef struct LNode//单链表节点
{
    int data;
    struct LNode *next;//后继
}LNode;

typedef struct DLNode
{
    int data;
    struct DLNode *prior;//前驱
    struct DLNode *next;//后继
}DLNode;

void initList(Sqlist &L){//初始化
    L.length=0;
}

int findinsertElem(Sqlist L,int x)//返回第一个比x大的元素的位置
{
    int i;
    for (int i = 0; i < L.length; ++i) {
        if (x<L.data[i])//对顺序表中元素从小到大逐个判断，看x是否小于所扫描的元素，如果小于则返回当前位置
        {
            return i;
        }
    }
    return i;//不存在则返回要插入的位置，即末尾
}

void insertElem(Sqlist &L, int x)//因为L本身要变化，所以使用引用型
{
    int p,i;
    p= findinsertElem(L,x);//找到要插入的位置
    for (int i = L.length-1; i >= p; --i) {//从右往左，逐个将元素右移一个位置
        L.data[i+1]=L.data[i];
    }
    L.data[p]=x;//将x放在插入位置p上
    ++(L.length);//长度+1
}

int findElem(Sqlist L, int e)//查找第一个值等于e的元素
{
    int i;
    for(i=0; i<L.length;++i){
        if (e==L.data[i])
        {
            return i;
        }
    }
    return -1;

}

int insertElem(Sqlist &L,int p,int e)//p是要插入的位置，e是要插入的值
{
    int i;
    if (p<0||p>L.length||L.length==maxSize){
        return 0;
    }
    for(i=L.length-1;i>=p;--i){
        L.data[i+1]=L.data[i];
    }
    L.data[p]=e;
    ++(L.length);
    return 1;
}

int deleteElem(Sqlist &L,int p,int &e)//删除l位置p上的值并用e返回
{
    int i;
    if (p<0||p>L.length-1){
        return 0;
    }
    e=L.data[p];
    for(i=p;i<L.length-1;++i){
        L.data[i]=L.data[i+1];
    }
    --(L.length);
    return 1;
}

int getElem(Sqlist L,int p,int &e){
    int i;
    if (p<0||p>L.length){
        return 0;
    }
    e=L.data[p];
    return 1;
}

void showElem(Sqlist L){
    for (int i = 0; i < L.length; ++i) {
        cout<<L.data[i]<<"\t";
    }
}

//单链表操作

void createlist_tail(LNode*&C,int a[],int n)//尾插法
{
    LNode *s, *r;
    C = (LNode*)malloc(sizeof(LNode));//申请C的头节点空间
    r=C;
    for (int i = 0; i < n; ++i) {
        s=(LNode*) malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}

void createlist_head(LNode*&C, int a[], int n)//头插法
{
    LNode *s,*r;
    C=(LNode*)malloc(sizeof(LNode));
    C->next=NULL;
    for (int i = 0; i < n; ++i) {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=C->next;//s所指的新节点的指针域next指向c的开始节点
        C->next=s;//头结点的指针域next指向s节点，使得s成为新的开始节点
    }
}

void merge(LNode *A,LNode *B,LNode *&C)//合并两个递增链表，合并后哦依然递增
{
    LNode *p=A->next;//p跟踪A的最小值节点
    LNode *q = B->next;//q跟踪B的最小值节点
    LNode *r;//指向C的终端节点
    C=A;//用A的头结点来做C的头结点
    C->next=NULL;
    free(B);//B的头结点已经无用，则释放掉
    r=C;//r指向C，因此时头结点也是终端节点
    while(p!=NULL&&q!=NULL)
    {
        if (p->data<=q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else{
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    r->next=NULL;
    if (p!=NULL)
    {
        r->next=p;
    }
    if (q!=NULL)
    {
        r->next=q;
    }
}

void merge1(LNode *A,LNode *B, LNode *&C)
{
    LNode * p = A->next;
    LNode * q = B->next;
    LNode * s;
    C=A;
    C->next=NULL;
    free(B);
    while (p!=NULL&&q!=NULL)
    {
        if (p->data<=q->data)
        {
            s=p;
            p=p->next;
            s->next=C->next;
            C->next=s;
        }
        else
        {
            s=q;
            q=q-> next;
            s->next=C->next;
            C->next=s;
        }

    }
    while(p!=NULL)
    {
        s=p;
        p=p->next;
        s->next=C->next;
        C->next=s;
    }
    while(q!=NULL)
    {
        s=q;
        q=q->next;
        s->next=C->next;
        C->next=s;
    }
}

void showlinklist(LNode*a)
{
    while(a->next!=NULL){
        cout<<a->data<<endl;
        a=a->next;
    }
}
int main(){
    Sqlist l;
    initList(l);
    insertElem(l,0,5);
    insertElem(l,1,8);
    showElem(l);
    cout<<"win test";
    cout<<"hh";

    return 0;
}
