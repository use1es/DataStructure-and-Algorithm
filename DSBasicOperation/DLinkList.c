#include<stdio.h>
#include<stdlib.h>
//双链表的基本操作
typedef struct DNode{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
void InitList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));
    L->next = NULL;
    L->prior = NULL;
}
DLinkList DLink_HeadInsert(DLinkList &L){//头插法
    InitList(L);
    DNode *p;
    int e;
    if(L->next==NULL){//当双链表为空时，需要先插入一个元素
        scanf("%d", &e);
        p = (DNode *)malloc(sizeof(DNode));
        p->data = e;
        p->next = L->next;
        p->prior = L;
        L->next = p;

    }
    while(scanf("%d",&e)!=EOF){//在头结点和第1个元素之间插入
        p = (DNode *)malloc(sizeof(DNode));
        p->data = e;
        p->next = L->next;
        L->next->prior = p;
        p->prior = L;
        L->next = p;
    }
    return L;
}
bool PrintList(DLinkList L){
    if(NULL==L->next){
        return false;
    }
    DNode *p;
    int i = 1;
    p = L->next;
    while(p){
        printf("number%d :%d\n",i, p->data);
        p = p->next;
        i++;
    }
    return true;
}
bool DeleteLNode(DLinkList &L,int e,int &val){
    if(NULL==L->next){
        return false;
    }
    DNode *p;
    p = L->next;
    for (int i = 0; i < e-1&&p!=NULL;i++){
        p = p->next;
    }
    val = p->data;
    if(p==NULL){
        return false;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}
int main(){
    DLinkList L;
    L = DLink_HeadInsert(L);
    PrintList(L);
    int v;
    DeleteLNode(L, 3, v);
    printf("the number to delete is %d\n", v);
    PrintList(L);
}
