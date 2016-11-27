/********************************************************
1,之所以之前会超时，可能是在于之前没一次交换都要进行一次对应
数值的查询工作。这里存疑，如果是这样，也就是这里要求的时间复杂度
应该比一般的排序的要低
2，这里进行新的改进是根据这一题的特殊性来的。由于角标跟数值都是0-n
这里我们读入数值序列的时候可以将数值当做角标，而把相应的角标当做数值进行存储
这样就可以节省相应数值角标的查询工作了
*********************************************************/

#include <stdio.h>
#include <stdlib.h>

void Swap0(int arr[], int pos0, int pos)
{
    int temp = arr[pos0];
    arr[pos0] = arr[pos];
    arr[pos] = temp;
    return;
}

int GetSwaps(int arr[], int length)
{
    int i = 1, pos, count = 0;
    while(i < length)
    {
        if(arr[0] == 0)
        {
            for(; i < length && arr[i] == i; i++){}
            if(i < length)
            {
                Swap0(arr, 0, i);
                count++;
            }
        }

        while(arr[0] != 0)
        {
            pos = arr[0];
            Swap0(arr, 0, pos);
            count++;
        }
    }
    return count;
}

int main()
{
    int N, i, in;
    scanf("%d", &N);
    int arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d", &in);
        arr[in] = i;   //存角标
    }
    printf("%d", GetSwaps(arr, N));
    return 0;
}
