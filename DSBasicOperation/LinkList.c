#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//����һ����ͷ�ڵ�ĵ�����,�Լ���������
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LNode *LocateElem(LinkList L,int e){//��ֵ����
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){
        p = p->next;
    }
    return p;
}
LNode *GetElem(LinkList L,int i){//��λ���ң����ص�i��Ԫ��
    if (i<0)
        return NULL;
    LNode *p;
    int j = 0;
    while(p!=NULL&&j<i){
        p = p->next;
        j++;
    }
    return p;
}
bool insertNextNode(LNode *p, int val);
bool InitListNoHead(LinkList &L){
    L = NULL;
    return true;
}
bool InitList(LinkList &L){//��ʼ��һ����ͷ�ڵ�ĵ�����
    L = (LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}
bool deleteList(LinkList L,int i,int *e){//��λ��ɾ����ɾ�������е�i��λ�õĽڵ�
    if(i<1)
        return false;
    LNode *p;
    p = L;
    for (int j = 0; j < i - 1 && p != NULL;j++)
    {
        p = p->next;
    }
    if(NULL==p)
        return false;
    LNode *q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}
bool deleteNode(LNode *p){//ɾ��ָ�����p��ʱ�临�Ӷ�ΪO(1)
    if(NULL==p)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}
bool insertList(LinkList L,int i,int val){//��λ�����
    if(i<1)
        return false;
    int j = 0;//��ǰpָ����ǵڼ����ڵ�
    LNode *p;//ָ��pָ��ǰɨ�赽�Ľڵ�
    p = L;//Lָ��ͷ��㣬ͷ����ǵ�0���ڵ㣨�������ݣ�
    while(p!=NULL&&j<i-1){//�ҵ���i-1���ڵ�
        p = p->next;
        j++;
    }
    insertNextNode(p, val);
    return true;
}
bool insertNextNode(LNode *p, int val){//����������p�ڵ�֮�����Ԫ��value
    if(NULL==p){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(NULL==s)
        return false;
    s->data = val;
    s->next = p->next;
    p->next = s;
    return true;
}
bool insertPriorNode(LinkList p, int val){//ǰ���������p�ڵ�֮ǰ����Ԫ��value
    if (NULL==p)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(NULL==s)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = val;
    return true;
}
void printList(LinkList L){//��ӡ����
    LNode *p;
    p = L->next;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
}
bool Empty(LinkList L){//�п�
    return (NULL == L->next);
}
int main()
{
    LinkList L;
    InitList(L);
    int length = 0;
    int e;
    while(scanf("%d",&e)!=EOF){//β�巨
        insertList(L, length + 1, e);
        length++;
    }
    printList(L);
}
