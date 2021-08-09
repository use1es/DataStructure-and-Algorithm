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

