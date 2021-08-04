#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//定义一个带头节点的单链表,以及基本操作
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LNode *LocateElem(LinkList L,int e){//按值查找
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){
        p = p->next;
    }
    return p;
}
LNode *GetElem(LinkList L,int i){//按位查找，返回第i个元素
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
bool InitList(LinkList &L){//初始化一个带头节点的单链表
    L = (LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}
bool deleteList(LinkList L,int i,int *e){//按位序删除：删除链表中第i个位置的节点
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
bool deleteNode(LNode *p){//删除指定结点p：时间复杂度为O(1)
    if(NULL==p)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}
bool insertList(LinkList L,int i,int val){//按位序插入
    if(i<1)
        return false;
    int j = 0;//当前p指向的是第几个节点
    LNode *p;//指针p指向当前扫描到的节点
    p = L;//L指向头结点，头结点是第0个节点（不存数据）
    while(p!=NULL&&j<i-1){//找到第i-1个节点
        p = p->next;
        j++;
    }
    insertNextNode(p, val);
    return true;
}
bool insertNextNode(LNode *p, int val){//后插操作：在p节点之后插入元素value
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
bool insertPriorNode(LinkList p, int val){//前插操作：在p节点之前插入元素value
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
void printList(LinkList L){//打印链表
    LNode *p;
    p = L->next;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
}
bool Empty(LinkList L){//判空
    return (NULL == L->next);
}
int main()
{
    LinkList L;
    InitList(L);
    int length = 0;
    int e;
    while(scanf("%d",&e)!=EOF){//尾插法
        insertList(L, length + 1, e);
        length++;
    }
    printList(L);
}
