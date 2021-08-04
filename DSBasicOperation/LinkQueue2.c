#include<stdio.h>
#include<stdlib.h>
//����ͷ������ʽ�洢�Ķ���
typedef struct LinkNode{//���Ӷ��н��
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct {//���Ӷ���
    LinkNode *front, *rear;//���еĶ�ͷ��βָ��
} LinkQueue;
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = NULL;//�����ʼ��
}
bool DeQueue(LinkQueue &Q,int &x){
    if(Q.rear==NULL)//�п�
        return false;
    x = Q.front->data;
    Q.front = Q.front->next;//����ָ��ָ����һ���ڵ�
    return true;
}
LinkQueue Queue_insert(LinkQueue &Q){//����һ�����У�������һЩԪ��
    InitQueue(Q);//��ʼ��
    int val;
    if(Q.rear==NULL){//�пգ�����ӿյĻ�����Ҫ�Ȳ����һ���ڵ㲢�ҰѶ��׶�βָ�붼ָ����
        Q.rear=Q.front = (LinkNode *)malloc(sizeof(LinkNode));
        scanf("%d", &val);
        Q.front->data = val;
        Q.front->next = NULL;
    }
    while(scanf("%d",&val)!=EOF){//�ڵ�һ���ڵ�֮������½ڵ�
        LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = val;
        Q.rear->next = s;
        Q.rear = s;//��βָ��ָ���½ڵ�
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
