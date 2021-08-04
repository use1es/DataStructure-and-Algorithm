#include<stdio.h>
#include<stdlib.h>
//不带头结点的链式存储的队列
typedef struct LinkNode{//链队队列结点
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct {//链队队列
    LinkNode *front, *rear;//队列的队头队尾指针
} LinkQueue;
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = NULL;//链表初始化
}
bool DeQueue(LinkQueue &Q,int &x){//出队
    if(Q.rear==NULL)//判空
        return false;
    x = Q.front->data;
    Q.front = Q.front->next;//队首指针指向下一个节点
    return true;
}
LinkQueue Queue_insert(LinkQueue &Q){//创建一个队列，并插入一些元素
    InitQueue(Q);//初始化
    int val;
    if(Q.rear==NULL){//判空，如果队空的话，需要先插入第一个节点并且把队首队尾指针都指向它
        Q.rear=Q.front = (LinkNode *)malloc(sizeof(LinkNode));
        scanf("%d", &val);
        Q.front->data = val;
        Q.front->next = NULL;
    }
    while(scanf("%d",&val)!=EOF){//在第一个节点之后插入新节点
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = val;
        Q.rear->next = s;
        Q.rear = s;//队尾指针指向新节点
        s->next = NULL;
    }
    return Q;
}
int main(){
    LinkQueue Q;
    Q = Queue_insert(Q);
    int x;
    printf("%d",DeQueue(Q, x));
}
