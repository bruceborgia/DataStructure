//线性表 顺序表和链表

#include "iostream"
using namespace std;

#define maxSize 100

typedef struct LNode//单链表节点
{
    int data;
    struct LNode *next;//后继
}LNode;

//单链表操作
void createlist_tail(LNode*&C,int a[],int n)//尾插法 会创建n+1个节点，头结点不存储数据
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

void merge(LNode *A,LNode *B,LNode *&C)//合并两个递增链表，合并后依然递增
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

void merge1(LNode *A,LNode *B, LNode *&C)//合并两个递增链表，合并后递减
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

int findAndDelete(LNode*C,int x)
{
    LNode *p,*q;
    p=C;
    /*查找部分开始*/
    while(p->next!=NULL)
    {
        if (p->next->data==x)
        {
            break;
        }
        p=p->next;
    }
    //超少部分结束
    if (p->next==NULL)
    {
        return 0;
    }
    else
    {
        //删除部分开始
        q=p->next;
        p->next=p->next->next;
        free(q);
        //删除部分结束
        return 1;
    }
}

void showlist(LNode*a)
{
    a=a->next;
    while(a->next!=NULL){//输出尾节点之前的数据,尾节点->next=null
        cout<<a->data<<"\t";
        a=a->next;
    }
    cout<<a->data<<"\t";
    cout<<endl;
}
int main(){
    LNode*l1,*l2,*l3,*l4,*l5,*l6,*l7;
    int a[5]={2,3,4,6,8};
    int b[5]={2,4,5,6,7};
    createlist_head(l1,a,5);
    createlist_tail(l2,a,5);
    createlist_tail(l3,b,5);
    createlist_tail(l4,a,5);
    createlist_tail(l5,b,5);
    showlist(l1);
    showlist(l2);
    showlist(l3);
    showlist(l4);
    showlist(l5);
    merge(l2,l3,l6);
    merge1(l4,l5,l7);
    showlist(l6);
    showlist(l7);

    //验证删除
    findAndDelete(l7,5);
    showlist(l7);




    return 0;
}
