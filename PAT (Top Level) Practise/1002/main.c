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

int Sum_L(struct Project arr[], int length)
{
    int i = 0, sum = 0;
    for(i = 0; i < length; i++)
        sum += arr[i].L;
    return sum;
}

void Make_Equal(struct Project* des, struct Project* src)
{
    des->D = src->D;
    des->L = src->L;
    des->P = src->P;
    des->Is_Used = src->Is_Used;
    return;
}

int GetMax_Profit(struct Project arr[], int length, int start_time, int node_Num)
{
    struct Project sub_Arr[MAX_SIZE];
    int sub_Length = 0;
    int i, max_Profit = 0, add_Profit = 0;
    if(node_Num != -1)
        arr[node_Num].Is_Used = 1;
    for(i = 0; i < length; i++)
    {
        if(arr[i].Is_Used != 1 && (arr[i].L + start_time) <= arr[i].D)
            Make_Equal(&sub_Arr[sub_Length++], &arr[i]);
    }
    int sum = Sum_L(sub_Arr, sub_Length);
    for(i = 0; i < sub_Length; i++)
    {
        if(sub_Arr[i].D >= sum + start_time)
        {
            add_Profit += sub_Arr[i].P;
            max_Profit = add_Profit;
            sub_Arr[i].Is_Used = 1;
        }
    }
    for(i = 0; i < sub_Length; i++)
    {
        if(sub_Arr[i].Is_Used == 1)
            continue;
        int temp_Profit = 0;
        temp_Profit = add_Profit + sub_Arr[i].P + GetMax_Profit(sub_Arr, sub_Length, start_time + sub_Arr[i].L, i);
        if(temp_Profit > max_Profit)
            max_Profit = temp_Profit;
    }
    if(node_Num != -1)
        arr[node_Num].Is_Used = 0;
    return max_Profit;
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
        i++;
    }
    printf("%d", GetMax_Profit(proArr, n, 0, -1));
    return 0;
}
