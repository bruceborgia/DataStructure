#include "iostream"
using namespace std;

#define maxSize 100

typedef struct SqQueue
{
    int data[maxSize];
    int front;// front ==rear 时，队空，防止假溢出
    int rear;//(rear+1)%maxSize == front
}SqQueue;


int main()
{
    cout<<"vv";
    return 0;
}