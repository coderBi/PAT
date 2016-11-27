/*
 1��֮����Ҫ��д��֮ǰ�������㷨���ӶȲ�����Ҫ��������ܳ���50�ײ㡣��Ȼ�Ż���������㲿��Ҫ�󣬵��Ǹ��ӶȻ���̫��
 2�������д��˼·���������ʱ�򣬶����ݽ��а�Deadline���У����룩�����Ԥ����Ȼ��Ӻ���ǰ�������Ʊ����Ĵ���
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Project
{
    int P;
    int L;
    int D;
    int Is_Used;
};

int GetMax_Profit(struct Project arr[], int length, int pos, int maxD)
{
    if(pos < 0)
        return 0;
    int i = 0;
    int p1 = 0, p2 = 0;
    struct Project copyArr[MAX_SIZE];
    while(i < length)
    {
        copyArr[i] = arr[i];
        i++;
    }
    if(copyArr[pos].D < maxD)
        maxD = copyArr[pos].D;
    copyArr[pos].D = maxD;
    if(copyArr[pos].D < copyArr[pos].L)
        return GetMax_Profit(copyArr, length, pos - 1, maxD);
    p1 = copyArr[pos].P + GetMax_Profit(copyArr, length, pos - 1, maxD - copyArr[pos].L);
    p2 = GetMax_Profit(copyArr, length, pos - 1, maxD);
    if(p2 > p1)
        p1 = p2;
    return p1;
}

void InsertNode(struct Project proArr[], int pos)
{
    int i = pos;
    struct Project temp = proArr[pos];
    while(i >= 1 && temp.D < proArr[i - 1].D)
    {
        proArr[i] = proArr[i - 1];
        i--;
    }
    proArr[i] = temp;
    return;
}

int main()
{
    int n, i = 0;
    struct Project proArr[MAX_SIZE];
    scanf("%d", &n);
    while(i < n)
    {
        scanf("%d %d %d", &proArr[i].P, &proArr[i].L, &proArr[i].D);
        proArr[i].Is_Used = 0;
        InsertNode(proArr, i);
        i++;
    }
    printf("%d", GetMax_Profit(proArr, n, n - 1, proArr[n - 1].D));
    return 0;
}
