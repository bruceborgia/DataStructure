#include "iostream"
#include "queue"
using namespace std;
#define OVERFLOW -1
#define maxSIZE 10

typedef struct BTNode
{
    int data;
    struct BTNode*lchild;
    struct BTNode*rchild;
}BTNode;

void CreateBiTree(BTNode *&T)
{
    int ch;
    cin>>ch;
    if (ch==-1)
    {
        T=NULL;
    }
    else
    {
        T = (BTNode*) malloc(sizeof(BTNode));
        if (!T)
        {
            exit(OVERFLOW);
        }
        T->data = ch;
        CreateBiTree(*(&T->lchild));
        CreateBiTree(*(&T->rchild));
    }
}
void Visit(BTNode *p)//输出节点数据
{
    if (p!=NULL)
    {
        cout<<p->data<<"\t";
    }

}

//先序遍历
void preorder(BTNode *p)
{
    if (p!=NULL)
    {
        Visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

//中序遍历
void inorder(BTNode *p)
{
    if (p!=NULL)
    {
        inorder(p->lchild);
        Visit(p);
        inorder(p->rchild);
    }
}

//后序遍历
void postorder(BTNode *p)
{
    if (p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        Visit(p);
    }
}

//求树深度
int getDepth(BTNode *p)
{
    int ld,rd;
    if (p==NULL)
    {
        return 0;
    }
    else
    {
        ld = getDepth(p->lchild);//求左子树深度
        rd = getDepth(p->rchild);//求右子树深度
        return (ld>rd?ld:rd)+1;
    }
}

void search(BTNode *p, BTNode *&q, int key)//将参数q定义为引用型指针，因为q要改变
{
    if (p!=NULL)
    {
        if (p->data ==key)//如果树为空树，则什么都不做，q保持NULL值
        {
            q=p;
        }
        else
        {
            search(p->lchild,q,key);//到左子树中查找
            if (q==NULL)//如果左子树中没找到，则到右子树中查找
            {
                search(p->rchild,q,key);//到右子树中查找
            }

        }
    }
}

void BFSSearch(BTNode *p)//广度优先搜索
{
    int front,rear;
    BTNode *que[maxSIZE];
    front = rear = 0;
    BTNode *q;
    if (p != NULL)
    {
        rear = (rear + 1) % maxSIZE;
        que[rear] = p;
        while(front != rear)
        {
            front = (front + 1) % maxSIZE;
            q = que[front];
            Visit(q);
            if (q->lchild != NULL)//如果左子树不空，则左子树的根节点入队
            {
                rear = (rear + 1) % maxSIZE;
                que[rear] = q->lchild;
            }
            if (q->rchild != NULL)
            {
                rear = (rear + 1)%maxSIZE;
                que[rear] = q->rchild;
            }
        }
    }
}

void bfssearch(BTNode * p)
{
    queue<BTNode*> que;
    BTNode *q;

    if (p!=NULL)
    {
        que.push(p);
        while(! que.empty())
        {
            q = que.front();
            Visit(q);
            que.pop();
            if (q->lchild != NULL)
            {
                que.push(q->lchild);
            }
            if (q->rchild != NULL)
            {
                que.push(q->rchild);
            }
        }

    }
}





int main()
{
    cout<<"hello world"<<endl;

    BTNode *t1;
    BTNode *q;

    CreateBiTree(t1);
    preorder(t1);
    cout<<"\n";

    inorder(t1);
    cout<<"\n";

    postorder(t1);
    cout<<"\n";

    int depth = getDepth(t1);
    cout<<"depth is "<<depth<<"\n";

    search(t1,q,7);
    cout<<"search key:"<<q->data<<"\n";

    BFSSearch(t1);
    cout<<"\n";

    bfssearch(t1);
    cout<<"\n";



    return 1;
}