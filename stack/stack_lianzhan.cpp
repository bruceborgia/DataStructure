#include "iostream"
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

void initStack(LNode *&lst)
{
    lst = (LNode*)malloc(sizeof(LNode));
    lst->next = NULL;
}

int isEmpty(LNode *lst)
{
    if (lst->next == NULL)
    {
        return 1;
    }
    return 0;
}

void push(LNode *lst, int x)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));
    p->next = NULL;

    //头插法
    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

int pop(LNode *lst, int &x)
{
    LNode *p;
    if (lst->next == NULL)
    {
        return 0;
    }

    p = lst->next;
    x = p->data;
    lst->next = p->next;
    free(p);
    return 1;

}
void show(LNode *lst)
{
    LNode*p = lst->next;
    while(p->next != NULL)
    {
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<p->data<<endl;
}

int main()
{
    LNode *s1;
    initStack(s1);
    cout<<isEmpty(s1)<<endl;

    push(s1,3);
    push(s1,5);
    cout<<isEmpty(s1)<<endl;
    show(s1);

    int x;
    pop(s1,x);
    show(s1);


    return 0;
}