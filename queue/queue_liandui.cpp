#include "iostream"
using namespace std;

typedef struct QNode//队节点定义
{
    int data;
    struct QNode*next;
}QNode;

typedef struct//链队类型定义
{
    QNode *front;
    QNode *rear;
}LiQueue;

void initQueue(LiQueue *&lqu)
{
    lqu=(LiQueue*)malloc(sizeof(LiQueue));
    lqu->front = lqu->rear=NULL;
}

int isQueueEmpty(LiQueue *lqu)
{
    if (lqu->rear==NULL||lqu->front==NULL)
        return 1;
    else
        return 0;
}

void enQueue(LiQueue *lqu, int x)
{
    QNode *p;
    p = (QNode*) malloc(sizeof(QNode));
    p->data=x;
    p->next=NULL;
    if (lqu->rear==NULL)//若队列为空，则新节点是队首节点，也是队尾节点
        lqu->front=lqu->rear=p;
    else
    {
        lqu->rear->next=p;//将新节点链接到队尾，rear指向它
        lqu->rear=p;
    }
}

int deQueue(LiQueue *lqu, int &x)
{
    QNode *p;
    if (lqu->rear == NULL)//if queue is empty,can't dequeue
        return 0;
    else
        p=lqu->front;
    if (lqu->front==lqu->rear)//队列中只有一个节点时的出队操作需要特殊处理 when queue only has 1 node,dequeue need special work
        lqu->front = lqu->rear=NULL;
    else
        lqu->front = lqu->front->next;
    x=p->data;
    free(p);
    return 1;
}

void show(LiQueue *lqu)
{
    QNode *p=lqu->front;
    while(p->next != lqu->rear->next)
    {
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<lqu->rear->data<<endl;

}

int main()
{
    LiQueue *lqu;
    initQueue(lqu);
    cout<<isQueueEmpty(lqu)<<endl;
    enQueue(lqu,3);
    enQueue(lqu,5);
    enQueue(lqu,8);
    show(lqu);
    int x;
    deQueue(lqu,x);
    cout<<"x:"<<x<<endl;
    show(lqu);

    return 0;
}
