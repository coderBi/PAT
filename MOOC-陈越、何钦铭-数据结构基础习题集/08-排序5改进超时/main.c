#include <stdio.h>
#include <stdlib.h>

int Find(int arr[], int length, int num)
{
    int pos = 0;
    while(pos < length)
    {
        if(arr[pos] == num)
            return pos;
        pos++;
    }
    return -1;
}

int Swap0(int arr[], int pos0, int pos)
{
    int temp = arr[pos0];
    arr[pos0] = arr[pos];
    arr[pos] = temp;
    return pos;
}

int GetSwaps(int arr[], int length)
{
    int i = 1, pos, count = 0;
    int pos0 = Find(arr, length, 0);
    while(i < length)
    {
        if(pos0 == 0)
        {
            for(; i < length && arr[i] == i; i++){}
            if(i < length)
            {
                pos0 = Swap0(arr, pos0, i);
                count++;
            }
        }

        /*
        while(pos0 != 0)   //每一次完成一个循环小回路
        {
            pos = arr[0]; //这里借鉴了网上别人的代码，不在进行之前的查找。可以知道pos由于在0的位置，所以是需要交换的
            pos0 = Swap0(arr, pos0, pos);
            count++;
        }
        */  //这一段借鉴：http://blog.csdn.net/tiantangrenjian/article/details/13749067。尽管通过测试，但是感觉交换方法不符合题意

        while(pos0 != 0)
        {
            pos = Find(arr, length, pos0);
            pos0 = Swap0(arr, pos0, pos);
            count++;
        }
    }
    return count;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    int arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", GetSwaps(arr, N));
    return 0;
}
