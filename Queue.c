#include<stdio.h>
#define Maxsize 10
//创建一个循环队列
typedef struct {
    int data[Maxsize];//存放队列元素
    int front, rear;//队头指针和队尾指针
} SqQueue;
void InitQueue(SqQueue &Q){//队列初始化
    Q.rear = Q.front = 0;
}
bool QueueEmpty(SqQueue Q){//队列判空
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q,int x){//入队：新增队头元素
    if((Q.rear+1)%Maxsize==Q.front)//判断队满：这样的处理会牺牲一个存储单元
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%Maxsize;
    return true;
}
SqQueue Queue_Insert(SqQueue &Q){//创建一个队列，并插入一些元素
    InitQueue(Q);
    int e;
    while(scanf("%d",&e)!=EOF){
        if((Q.rear+1)%Maxsize!=Q.front){
        Q.data[Q.rear] = e;
        Q.rear = (Q.rear + 1) % Maxsize;
        }
    }
    return Q;
}
bool DeQueue(SqQueue &Q, int &x){//出队：删除队头元素
    if(Q.rear==Q.front){//判断队空
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;//循环队列头指针的移动
    return true;
}
bool GetHead(SqQueue Q,int &x){//获得队头元素
    if(Q.rear==Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}
bool printQueue(SqQueue Q){//打印队列所有元素
    if(Q.front==Q.rear)
        return false;
    for (int i = 0; i < Maxsize;i++){
        if(i<Q.rear)
        printf("num%d:%d\n",i+1, Q.data[i]);
    }
    return true;
}
int main(){
    SqQueue Q;
    Q = Queue_Insert(Q);
    printQueue(Q);
}
