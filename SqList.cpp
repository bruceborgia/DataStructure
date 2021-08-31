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

int findElem(Sqlist L,int x)//返回第一个比x大的元素的位置
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
    p= findElem(L,x);//找到要插入的位置
    for (int i = L.length-1; i >= p; --i) {//从右往左，逐个将元素右移一个位置
        L.data[i+1]=L.data[i];
    }
    L.data[p]=x;//将x放在插入位置p上
    ++(L.length);//长度+1
}




int main(){
    cout<<"hello world";
    cout<<"jj";
    return 0;
}
