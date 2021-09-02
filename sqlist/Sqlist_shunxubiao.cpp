//线性表 顺序表和链表

#include "iostream"
using namespace std;

#define maxSize 100

typedef struct Sqlist//顺序表结构体
{
    int data[maxSize];
    int length;
}Sqlist;

void initList(Sqlist &L){//初始化
    L.length=0;
}

int findElem1(Sqlist L,int x)//返回第一个比x大的元素的位置
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
    p= findElem1(L,x);//找到要插入的位置
    for (int i = L.length-1; i >= p; --i) {//从右往左，逐个将元素右移一个位置
        L.data[i+1]=L.data[i];
    }
    L.data[p]=x;//将x放在插入位置p上
    ++(L.length);//长度+1
}

int findElem2(Sqlist L, int e)//查找第一个值等于e的元素
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

int getElem(Sqlist L,int p,int &e){//用e返回L中P位置上的元素
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

int main(){
    Sqlist l;
    initList(l);
    insertElem(l,0,5);
    insertElem(l,1,8);
    showElem(l);
    cout<<endl;
    cout<<"第一个比4大的数据在顺序表中位置是：";
    cout<<findElem1(l,4)<<endl;
    cout<<"5在顺序表中位置是：";
    cout<<findElem2(l,5)<<endl;
    int e;
    getElem(l,1,e);
    cout<<"顺序表中data[1]=:";
    cout<<e<<endl;


    return 0;
}
