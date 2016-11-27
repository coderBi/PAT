#include <stdio.h>
#include <stdlib.h>

void SetTimes(int arr[], int num);

int main()
{
    int N, i, num, count = -1;
    int arr[10] = {0};
    int res[10], resLen = 0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &num);
        SetTimes(arr, num);
    }
    for(i = 0; i < 10; i++)
    {
        if(arr[i] > count)
            count = arr[i];
    }

    printf("%d: ", count);
    for(i = 0; i < 10; i++)
    {
        if(arr[i] == count)
            res[resLen++] = i;
    }
    for(i = 0; i < resLen - 1; i++)
    {
        printf("%d ", res[i]);
    }
    printf("%d", res[resLen - 1]);
    return 0;
}

void SetTimes(int arr[], int num)
{
    int bit;
    if(num < 0)
    {
        num *= -1;
    }

    while(num/10 != 0)
    {
        bit = num%10;
        arr[bit]++;
        num /= 10;
    }
    arr[num]++;
    return;
}
