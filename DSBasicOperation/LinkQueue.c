#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct {
    LinkNode *front, *rear;
} LinkQueue;
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
bool DeQueue(LinkQueue &Q,int &x){
    if(Q.front==Q.rear)//空队
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;//修改头节点的next指针
    if(Q.rear==p){//此次是最后一个节点出队
        Q.rear = Q.front;//修改rear指针
    }
    free(p);//释放节点空间
    return true;
}
void EnQueue(LinkQueue &Q,int x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.front->next = s;
    Q.rear = s;
}
bool IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return false;
    else
        return true;
}
int main(){
    LinkQueue Q;
    InitQueue(Q);
}
