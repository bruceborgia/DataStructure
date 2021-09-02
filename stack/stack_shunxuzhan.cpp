
#include "iostream"
using namespace std;

#define maxSize 100

typedef struct SqStack
{
    int data[maxSize];
    int top;//栈顶指针 top=-1 为栈空
}SqStack;

void initStack(SqStack &st)
{
    st.top=-1;
}

int isEmpty(SqStack &st)
{
    if (st.top==-1)
    {
        return 1;
    }
    return 0;
}

int push(SqStack &st, int x)
{
    if (st.top==maxSize-1)//stack is full,can't push
    {
        return 0;
    }
    ++(st.top);
    st.data[st.top]=x;
    return 1;
}

int pop(SqStack &st, int &x)
{
    if (st.top==-1)//  stack is empty ,can't pop
    {
        return 0;
    }
    x = st.data[st.top];
    --(st.top);
    return 1;
}

void show(SqStack st)
{
    for (int i = 0; i <= st.top; ++i)
    {
        cout<<st.data[i]<<"\t";
    }
    cout<<"\n";
}

int main()
{
    SqStack s1;
    initStack(s1);
    int a[5] = {2,3,5,7,8};
    for (int i = 0; i < 5; ++i)
    {
        push(s1,a[i]);
    }
    show(s1);
    int x;
    pop(s1,x);
    cout<<x<<"\n";
    show(s1);

    return 0;
}