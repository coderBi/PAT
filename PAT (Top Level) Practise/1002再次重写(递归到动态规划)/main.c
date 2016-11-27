#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Project
{
    int P;
    int L;
    int D;
};

void InsertNode(struct Project proArr[], int pos)
{
    int i = pos;
    struct Project temp = proArr[pos];
    while(i >= 2 && temp.D < proArr[i - 1].D)
    {
        proArr[i] = proArr[i - 1];
        i--;
    }
    proArr[i] = temp;
    return;
}

int _GetMaxProfit(struct Project arr[], const int length, const int maxD)  //这里只能获取一部分正确结果
{
    int arrMidStore[maxD + 1], i = 0,  j = 0;
    arrMidStore[0] = 0;
    for(i = 1; i <= maxD; i++)
    {
         int max = arrMidStore[i - 1];
         for(j = 0; j < length && arr[j].D <= i; j++)
         {
             if(arr[j].D == i && arr[j].P + arrMidStore[i - arr[j].L] > max)
                max = arr[j].P + arrMidStore[i - arr[j].L];
         }
         arrMidStore[i] = max;
    }
    return arrMidStore[maxD];
}

int GetMaxProfit(struct Project arr[], const int length, const int maxD)  //改用二维数组进行中间状态存贮
{
    int arrMidStore[length + 1][maxD + 1], i = 0,  j = 0;
    for(i = 0; i <= length; i++)
    {
        arrMidStore[i][0] = 0;
    }
    for(j = 0; j <= maxD; j++)
    {
        arrMidStore[0][j] = 0;
    }
    for(i = 1; i <= length; i++)
    {
         for(j = 1; j <= maxD; j++)
         {
            int temp = 0;
            arrMidStore[i][j] = arrMidStore[i - 1][j];
            if(arr[i].L > j)
                continue;
            else if(arr[i].D < j)
            {
                temp = arrMidStore[i - 1][arr[i].D - arr[i].L] + arr[i].P;
            }
            else
            {
                 temp = arrMidStore[i - 1][j - arr[i].L] + arr[i].P;
            }
            if(temp > arrMidStore[i][j])
                arrMidStore[i][j] = temp;
         }
    }
    return arrMidStore[length][maxD];
}

int main()
{
    int n, i = 1;
    struct Project proArr[MAX_SIZE];
    scanf("%d", &n);
    while(i <= n)
    {
        scanf("%d %d %d", &proArr[i].P, &proArr[i].L, &proArr[i].D);
        InsertNode(proArr, i);
        i++;
    }
    const int maxD = proArr[n].D;
    printf("%d", GetMaxProfit(proArr, n, maxD));
    return 0;
}
