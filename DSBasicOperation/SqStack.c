#include<stdio.h>
#include<stdbool.h>
#define Maxsize 10
//顺序栈的增删改查
typedef struct {
    int data[Maxsize];//静态数组存放栈中元素
    int top;//栈顶指针
} SqStack;
void InitStack(SqStack &S){
    S.top = -1;
}
bool StackEmpty(SqStack S){//判空
    if(S.top==-1)
        return true;
    else
        return false;
}
bool Pop(SqStack &S,int &x){//栈顶出栈
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack S,int &x){//读取栈顶元素
    if(S.top==-1){
        return false;
    }
    x = S.data[S.top];
    return true;
}
bool Push(SqStack &S,int x){//新元素进栈
    if(S.top==Maxsize -1){//栈满报错
        return false;
    }
    S.top = S.top + 1;//指针加一
    S.data[S.top] = x;
    return true;

}
int main(){
    SqStack S;//声明一个顺序栈（分配空间）
    InitStack(S);
    int e;
    while(scanf("%d",&e)!=EOF){//数据进栈
        Push(S, e);
    }
    int x = 0;
    GetTop(S, x);
    printf("the top element is %d\n", x);
    int i = 0;
    while(S.top!=-1){//栈顶元素依次出栈
        Pop(S, i);
        printf("%d\n", i);
    }
}
