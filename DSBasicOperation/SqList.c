#include<stdio.h>
#include<stdbool.h>
//����һ����̬��������Ա�
#define Maxsize 10
typedef struct{
    int list[Maxsize];//˳���ĳ���
    int length;//˳���ĵ�ǰ����
} sqList, *sqList_p;
void InitList(sqList_p L){//��ʼ��һ��˳���
    for (int i = 0; i < Maxsize;i++){
        L->list[i] = 0;
    }
    L->length = 0;
}
bool listInsert(sqList_p L,int i,int e){//��Lָ��λ���в�����Ԫ��
    if (i < 1 || i > L->length+1)//�ж�i��λ���Ƿ���Ч
        return false;
    if(L->length>=Maxsize)//�жϴ洢�ռ��Ƿ�����
        return false;
    for (int j = L->length; j >= i;j--)//����i��Ԫ�ؼ��Ժ��Ԫ�غ���
    {
        L->list[j] = L->list[j - 1];
    }
    L->list[i - 1] = e;//��λ��i����e
    L->length++;//���Ա��ȼ�1
    return true;
}
bool listDelete(sqList_p L,int i,int *e){//ɾ��ָ��Ԫ��
    if(i<1||i>L->length)//�ж�i��λ���Ƿ���Ч
        return false;
    *e = L->list[i - 1];//����ɾ����Ԫ�ظ���e
    for (int j = i; j <= L->length;j++){
        L->list[j - 1] = L->list[j];//��i֮���Ԫ��ǰ��
    }
    L->length--;
    return true;
}
int GetElem(sqList_p L,int p){//��λ����
    return L->list[p + 1];
}
int LocateELem(sqList_p L,int e){//��ֵ����
    int i;
    for ( i = 0; i < L->length;i++){
        if(L->list[i]==e)
            return i+1;//�±�Ϊi��Ԫ��֮����e��������λ��Ϊi+1
    }
    return 0;
}
bool DeleteNumber(sqList_p L, int *val)//ɾ��˳���L�е���С��Ԫ�ز�������ֵ
{
    *val = L->list[0];
    int pos = 0;
    if(NULL==L->list){
        printf("error");
        return false;
    }
    for (int i = 0; i < L->length-1;i++){//�ҵ���С��Ԫ��
        if(L->list[i]<*val){
            *val = L->list[i];
            pos = i;
        }
    }
    L->list[pos] = L->list[L->length-1];
    L->length--; //ֱ�ӽ�����-1�Ϳ��԰����һ��Ԫ��Ĩ��
    return true;
}
void reverseList(sqList_p L){//ʵ��L������Ԫ�ص�����
    int tmp;
    for (int i = 0; i < L->length / 2;i++){
        tmp=L->list[L->length - 1 - i];
        L->list[L->length - 1 - i] = L->list[i];
        L->list[i] = tmp;
    }
}
int main()
{
    sqList L;//����һ��˳���
    InitList(&L);
    for (int i = 0; i < Maxsize - 6;i++){
        scanf("%d", &L.list[i]);
        L.length++;
    }
    reverseList(&L);
    int e = -1;
    listInsert(&L, 4, 5);
    listDelete(&L, 5, &e);
    printf("ɾ�������� %d\n", e);
    int val = 5;
    printf("���ҵ�����λ���� %d\n",LocateELem(&L, val));
    int num = 0;
    printf("the delete numble is %d\n", DeleteNumber(&L,&num));
    for (int i = 0; i < L.length;i++){
        printf("list[%d]=%d\n", i, L.list[i]);
    }
}
