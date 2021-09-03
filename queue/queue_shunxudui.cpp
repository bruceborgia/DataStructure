#include "iostream"
using namespace std;

#define maxSize 10

typedef struct SqQueue
{
    int data[maxSize];
    int front;// front ==rear 时，队空，防止假溢出
    int rear;//(rear+1)%maxSize == front
}SqQueue;

void initQueue(SqQueue &qu)
{
    qu.front=qu.rear=0;
    for (int i = 0; i < 10; ++i) {
        qu.data[i]=-1;
    }
}

int isQueueEmpty(SqQueue qu)
{
    if (qu.front==qu.rear)
    {
        return 1;
    }
    return 0;
}

int enQueue(SqQueue &qu, int x)
{
    if ((qu.rear+1)%maxSize==qu.front)// if queue is full,can't enqueue
        return 0;
    qu.rear = (qu.rear+1)%maxSize;//if queue is not full,first move pointer
    qu.data[qu.rear]=x; //then enqueue
    return 1;
}

int deQueue(SqQueue &qu, int &x)
{
    if (qu.front==qu.rear)//if queue is empty,can't dequeue,return 0
        return 0;
    qu.front=(qu.front+1)%maxSize;//if queue is not empty,thrn move pointer
    x=qu.data[qu.front];
    return 1;
}

void show(SqQueue qu)
{
    int p = qu.front+1;
    while(qu.rear!=p)
    {
        cout<<qu.data[p]<<"\t";
        p=(p+1)%maxSize;
    }
    cout<<qu.data[p]<<"\n";

}

int main()
{
    SqQueue qu;
    initQueue(qu);
    cout<<isQueueEmpty(qu)<<endl;
    enQueue(qu,3);
    enQueue(qu,5);
    show(qu);
    int x;
    deQueue(qu,x);
    cout<<"x="<<x<<endl;
    show(qu);


    return 0;
}