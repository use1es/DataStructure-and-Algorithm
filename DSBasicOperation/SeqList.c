#include<stdio.h>
#include<stdlib.h>
//动态分配的顺序表
#define Initsize 10
typedef struct{
    int *data;//指示动态分配数组的指针
    int MaxSize,length;//数组的最大容量和当前个数
} seqList,*seqList_p;
void InitList(seqList_p L){
    L->data = (int *)malloc(Initsize * sizeof(int));
    L->length = 0;
    L->MaxSize = Initsize;
}
void IncreaseSize(seqList_p L,int len){
    int *p = L->data;
    L->data = (int *)malloc(sizeof(int) * (L->length + len));
    for(int i=0;i<L->length;i++){
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + len;
    free(p);
}
int main(){
    seqList L;
    InitList(&L);

    for (int i = 0; i < Initsize - 5;i++){
        scanf("%d", &L.data[i]);
        L.length++;
    }
    IncreaseSize(&L, 5);
    for (int i = 0; i < L.length;i++){
        printf("list[%d]=%d\n", i, L.data[i]);
    }
    printf("%d", L.MaxSize);
}
