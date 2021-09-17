#include "iostream"
using namespace std;

typedef struct BTNode
{
    char data;
    struct BTNode*lchild;
    struct BTNode*rchild;
}BTNode;

void Visit(BTNode *p)//输出节点的数据
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

int main()
{
    cout<<"hello world"<<endl;
    return 1;
}