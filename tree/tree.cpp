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

void preorderNoRecursion(BTNode *bt)//先序非递归遍历
{
    if (bt != NULL)
    {
        BTNode *Stack[maxSIZE]; //定义一个栈
        int top = -1;           //初始化栈
        BTNode *p;
        Stack[++top] = bt;      //根节点入栈
        while(top!=-1)          //栈空循环退出，遍历结束
        {
            p=Stack[top--];     //出栈并输出栈顶节点
            Visit(p);           //访问并输出p节点
            if (p->rchild != NULL)//栈顶元素的右孩子存在，则右孩子入栈
            {
                Stack[++top] = p->rchild;
            }
            if (p->lchild != NULL)//栈顶元素左孩子存在，则左孩子入栈
            {
                Stack[++top] = p->lchild;
            }
        }
    }
}

void inorderNoRecursion(BTNode *bt)//中序遍历
{
    if (bt != NULL) {
        BTNode *Stack[maxSIZE];
        int top = -1;
        BTNode *p;
        p = bt;

        while (top != -1 || p != NULL)//在访问根节点的rchild时，会出现栈空的情况，但此时p为根节点，非空
        {
            while (p != NULL)//左孩子存在，左孩子入栈
            {
                Stack[++top] = p;
                p = p -> lchild;
            }
            if (top != -1)//栈不空情况下出栈并输出栈节点
            {
                p = Stack[top--];
                Visit(p);
                p = p->rchild;
            }

        }
    }
}

//经过观察，逆后序遍历 是 先序遍历过程中对左右子树遍历顺序交换所得到的结果
//因此需两个栈，一个栈用来辅助做逆后序遍历 并将遍历结果序列压入另一个栈stack2,将stack2全部出栈
void postorderNoRecursion(BTNode *bt)
{
    if (bt != NULL)
    {
        //定义两个栈
        BTNode *Stack1[maxSIZE];
        int top1 = -1;
        BTNode *Stack2[maxSIZE];
        int top2 = -1;
        BTNode *p = NULL;
        Stack1[++top1] = bt;
        while(top1 != -1)
        {
            p = Stack1[top1--];
            Stack2[++top2] = p;
            //以下入栈顺序与先序遍历相反
            if (p->lchild != NULL)
            {
                Stack1[++top1] = p->lchild;
            }
            if (p->rchild != NULL)
            {
                Stack1[++top1] = p->rchild;
            }
        }
        while (top2 != -1)
        {
            p = Stack2[top2--];
            Visit(p);
        }
    }

}



int main()
{
    cout<<"hello world"<<endl;

    BTNode *t1;
    BTNode *q;

    CreateBiTree(t1);//创建树
    cout<<"先序递归遍历：";
    preorder(t1);//先序递归遍历
    cout<<"\n";

    cout<<"中序递归遍历：";
    inorder(t1);//中序递归遍历
    cout<<"\n";

    cout<<"后序递归遍历：";
    postorder(t1);//后序递归遍历
    cout<<"\n";

    int depth = getDepth(t1);//求树的深度
    cout<<"depth is "<<depth<<"\n";

    search(t1,q,7);//查询树中有无 7
    cout<<"search key:"<<q->data<<"\n";

    cout<<"广度优先搜索：";
    BFSSearch(t1);//广度优先搜索
    cout<<"\n";

    cout<<"广度优先搜索：";
    bfssearch(t1);//广度优先搜索
    cout<<"\n";

    cout<<"先序非递归遍历：";
    preorderNoRecursion(t1);
    cout<<"\n";

    cout<<"中序非递归遍历：";
    inorderNoRecursion(t1);
    cout<<"\n";

    cout<<"后序非递归遍历：";
    postorderNoRecursion(t1);
    cout<<"\n";



    return 1;
}