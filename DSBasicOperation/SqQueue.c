#include<stdio.h>
#define Maxsize 10
//����һ��ѭ������
typedef struct {
    int data[Maxsize];//��Ŷ���Ԫ��
    int front, rear;//��ͷָ��Ͷ�βָ��
} SqQueue;
void InitQueue(SqQueue &Q){//���г�ʼ��
    Q.rear = Q.front = 0;
}
bool QueueEmpty(SqQueue Q){//�����п�
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q,int x){//��ӣ�������ͷԪ��
    if((Q.rear+1)%Maxsize==Q.front)//�ж϶����������Ĵ��������һ���洢��Ԫ
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%Maxsize;
    return true;
}
SqQueue Queue_Insert(SqQueue &Q){//����һ�����У�������һЩԪ��
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
bool DeQueue(SqQueue &Q, int &x){//���ӣ�ɾ����ͷԪ��
    if(Q.rear==Q.front){//�ж϶ӿ�
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;//ѭ������ͷָ����ƶ�
    return true;
}
bool GetHead(SqQueue Q,int &x){//��ö�ͷԪ��
    if(Q.rear==Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}
bool printQueue(SqQueue Q){//��ӡ��������Ԫ��
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

