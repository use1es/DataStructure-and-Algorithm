#include<stdio.h>
#define Maxsize 10
//ѭ�����У���size�ж϶����Լ���βָ��ָ����е����һ��Ԫ��
typedef struct {
    int data[Maxsize];//��Ŷ���Ԫ��
    int front, rear;//��ͷָ��Ͷ�βָ��
    int size;//���г���
} SqQueue;
void InitQueue(SqQueue &Q){//��ʼ������
    Q.rear = -1;//�ö�βָ��ָ��-1
    Q.front = 0;
    Q.size = 0;//��ʼʱ����Ϊ0
}
SqQueue Queue_Insert(SqQueue &Q){//����һ�����У�������һЩԪ��
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
bool printQueue(SqQueue Q){//��ӡ��������Ԫ��
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
