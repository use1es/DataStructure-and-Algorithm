#include<stdio.h>
#define Maxsize 10
//循环队列：用size判断队满以及队尾指针指向队列的最后一个元素
typedef struct {
    int data[Maxsize];//存放队列元素
    int front, rear;//队头指针和队尾指针
    int size;//队列长度
} SqQueue;
void InitQueue(SqQueue &Q){//初始化队列
    Q.rear = -1;//让队尾指针指向-1
    Q.front = 0;
    Q.size = 0;//初始时长度为0
}
SqQueue Queue_Insert(SqQueue &Q){//创建一个队列，并插入一些元素
    InitQueue(Q);
    int e;
    while(scanf("%d",&e)!=EOF){
        if(Q.size<Maxsize){
        Q.data[Q.rear+1] = e;
        Q.rear = (Q.rear+1) % Maxsize;
        Q.size = Q.size + 1;
        }
    }
    return Q;
}
bool DeQueue(SqQueue &Q,int &x){
    if(Q.size==0)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    return true;
}
bool EnQueue(SqQueue &Q,int x){
    if(Q.size==Maxsize)
        return false;
    x = Q.data[Q.rear + 1];
    Q.rear = (Q.rear + 1) % Maxsize;
    Q.size = Q.size + 1;
    return true;
}
bool printQueue(SqQueue Q){//打印队列所有元素
    if(Q.size==0)
        return false;
    for (int i = 0; i < Maxsize;i++){
        if(i<=Q.rear)
        printf("num%d:%d\n",i+1, Q.data[i]);
    }
    return true;
}
int main(){
    SqQueue Q;
    Q = Queue_Insert(Q);
    printQueue(Q);
}
