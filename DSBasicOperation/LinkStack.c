#include<stdio.h>
#include<stdlib.h>
//��ջ�Ļ�������
typedef struct LStack {
    int data;
    struct LStack *next;
} LStack, *pLStack;
void InitStack(pLStack &S){
    S = NULL;
}
bool GetTop(pLStack &S,int &x){//��ȡջ��Ԫ��
    if(S==NULL){
        return false;
    }
    x = S->data;
    return true;
}
bool Pop(pLStack &S,int &x){//��ջ
    if(NULL==S){
        return false;
    }
    LStack *p;
    p = S;
    x = S->data;
    S = S->next;
    free(p);
    p = NULL;
    return true;
}
bool Push(pLStack &S,int val){//Ԫ�ؽ�ջ
    LStack *p;
    p = (LStack *)malloc(sizeof(LStack));
    p->data = val;
    p->next = S;
    S = p;
    return true;
}
int main(){
    pLStack S;
    InitStack(S);
    int e;
    while(scanf("%d",&e)!=EOF){
        Push(S, e);
    }
    int x;
    GetTop(S, x);
    printf("%d\n", x);
    int v;
    Pop(S, v);
    printf("%d\n", v);
}
