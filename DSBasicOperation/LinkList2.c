#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode, *LinkList;
void InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
}
void printList(LinkList L){//打印链表
    LNode *p;
    p = L->next;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
}
LinkList List_HeadInsert(LinkList &L){//头插法：逆序输出
    InitList(L);
    LNode *s;
    int e;
    while(scanf("%d",&e)!=EOF){
        s = (LNode *)malloc(sizeof(LNode));
        s->next = L->next;
        s->data = e;
        L->next = s;
    }
    return L;
}
LinkList List_RearInsert(LinkList &L){//尾插法：正序输出
    InitList(L);
    LNode *s, *r;//r是始终指向链表尾的指针
    r = L;//r指向头节点
    int e;
    while(scanf("%d",&e)!=EOF){
        s = (LNode *)malloc(sizeof(LNode));
        s->next = r->next;
        s->data = e;
        r->next = s;
        r = s;
    }
    return L;
}
int main(){
    LinkList L;
    L = List_RearInsert(L);
    printList(L);
}
