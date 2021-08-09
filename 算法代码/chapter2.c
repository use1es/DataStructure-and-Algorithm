//删除线性表中所有值为x的元素
//算法思想：用k记录表中等于x的元素个数，边扫描L边统计k，并将不等于x的元素前移k个位置，最后修改L的长度。

void Delete_x(sqList_p L,int x){
    int k = 0;
    for (int i = 0; i < L->length;i++){
        if(L->list[i]==x){
            k++;
        }
        else
            L->list[i - k] = L->list[i];
    }
    L->length = L->length - k;
}
//删除有序表中重复的元素
//算法思想：设置一个临时变量等于表内的第一个元素，在扫描表的时候让表中元素和临时变量比较是否相同，若不同则添入表中且让临时变量等于新元素。
void delete_rep(sqList_p L){
    int tmp = L->list[0];
    int k = 1;
    for (int i = 0; i < L->length;i++){
        if(L->list[i]!=tmp){
            L->list[k] = L->list[i];
            tmp = L->list[i];
            k++;
        }
    }
    L->length = k;
}
