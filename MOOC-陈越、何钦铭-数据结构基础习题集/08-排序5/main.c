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
    /*if(pos0 == 0)
    {
        for(; i < length && arr[i] == i; i++){}
       // if(i < length)
        {
            pos0 = Swap0(arr, pos0, i);
            count++;
        }
    }*/
    while(i < length)
    {

        pos = Find(arr, length, pos0);
        if(pos == 0)
        {
            for(; i < length && (arr[i] == i || arr[i] == 0); i++){}
            if(i < length)
                pos = i;
            else if(pos0 != 0)  //可能存在的最后一次移动
            {
                count++;
                break;
            }
            else             //全部排好了
                break;
        }
        pos0 = Swap0(arr, pos0, pos);
        count++;
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
