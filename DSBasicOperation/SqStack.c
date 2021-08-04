#include<stdio.h>
#include<stdbool.h>
#define Maxsize 10
//˳��ջ����ɾ�Ĳ�
typedef struct {
    int data[Maxsize];//��̬������ջ��Ԫ��
    int top;//ջ��ָ��
} SqStack;
void InitStack(SqStack &S){
    S.top = -1;
}
bool StackEmpty(SqStack S){//�п�
    if(S.top==-1)
        return true;
    else
        return false;
}
bool Pop(SqStack &S,int &x){//ջ����ջ
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack S,int &x){//��ȡջ��Ԫ��
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top];
    return true;
}
bool Push(SqStack &S,int x){//��Ԫ�ؽ�ջ
    if(S.top==Maxsize -1){//ջ������
        return false;
    }
    S.top = S.top + 1;//ָ���һ
    S.data[S.top] = x;
    return true;

}
int main(){
    SqStack S;//����һ��˳��ջ������ռ䣩
    InitStack(S);
    int e;
    while(scanf("%d",&e)!=EOF){//���ݽ�ջ
        Push(S, e);
    }
    int x = 0;
    GetTop(S, x);
    printf("the top element is %d\n", x);
    int i = 0;
    while(S.top!=-1){//ջ��Ԫ�����γ�ջ
        Pop(S, i);
        printf("%d\n", i);
    }
}
