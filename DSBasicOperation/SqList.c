#include<stdio.h>
#include<stdbool.h>
//定义一个静态分配的线性表
#define Maxsize 10
typedef struct{
    int list[Maxsize];//顺序表的长度
    int length;//顺序表的当前长度
} sqList, *sqList_p;
void InitList(sqList_p L){//初始化一个顺序表
    for (int i = 0; i < Maxsize;i++){
        L->list[i] = 0;
    }
    L->length = 0;
}
bool listInsert(sqList_p L,int i,int e){//往L指定位置中插入新元素
    if (i < 1 || i > L->length+1)//判断i的位置是否有效
        return false;
    if(L->length>=Maxsize)//判断存储空间是否已满
        return false;
    for (int j = L->length; j >= i;j--)//将第i个元素及以后的元素后移
    {
        L->list[j] = L->list[j - 1];
    }
    L->list[i - 1] = e;//在位置i处放e
    L->length++;//线性表长度加1
    return true;
}
bool listDelete(sqList_p L,int i,int *e){//删除指定元素
    if(i<1||i>L->length)//判断i的位置是否有效
        return false;
    *e = L->list[i - 1];//将被删除的元素赋给e
    for (int j = i; j <= L->length;j++){
        L->list[j - 1] = L->list[j];//将i之后的元素前移
    }
    L->length--;
    return true;
}
int GetElem(sqList_p L,int p){//按位查找
    return L->list[p + 1];
}
int LocateELem(sqList_p L,int e){//按值查找
    int i;
    for ( i = 0; i < L->length;i++){
        if(L->list[i]==e)
            return i+1;//下标为i的元素之等于e，返回其位序为i+1
    }
    return 0;
}
bool DeleteNumber(sqList_p L, int *val)//删除顺序表L中的最小的元素并返回其值
{
    *val = L->list[0];
    int pos = 0;
    if(NULL==L->list){
        printf("error");
        return false;
    }
    for (int i = 0; i < L->length-1;i++){//找到最小的元素
        if(L->list[i]<*val){
            *val = L->list[i];
            pos = i;
        }
    }
    L->list[pos] = L->list[L->length-1];
    L->length--; //直接将长度-1就可以把最后一个元素抹除
    return true;
}
void reverseList(sqList_p L){//实现L中所有元素的逆置
    int tmp;
    for (int i = 0; i < L->length / 2;i++){
        tmp=L->list[L->length - 1 - i];
        L->list[L->length - 1 - i] = L->list[i];
        L->list[i] = tmp;
    }
}
int main()
{
    sqList L;//声明一个顺序表
    InitList(&L);
    for (int i = 0; i < Maxsize - 6;i++){
        scanf("%d", &L.list[i]);
        L.length++;
    }
    reverseList(&L);
    int e = -1;
    listInsert(&L, 4, 5);
    listDelete(&L, 5, &e);
    printf("删除的数是 %d\n", e);
    int val = 5;
    printf("查找的数的位次是 %d\n",LocateELem(&L, val));
    int num = 0;
    printf("the delete numble is %d\n", DeleteNumber(&L,&num));
    for (int i = 0; i < L.length;i++){
        printf("list[%d]=%d\n", i, L.list[i]);
    }
}
