#include <stdio.h>
#include <stdlib.h>

int FindPos(int arr[], int length, int num);

int main()
{
    int N, X, i, pos;
    scanf("%d %d", &N, &X);
    int arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    pos = FindPos(arr, N, X);
    if(pos == -1)
    {
        printf("Not Found");
    }
    else
    {
        printf("%d", pos);
    }
    return 0;
}

int FindPos(int arr[], int length, int num)
{
    int i = 0;
    for(; i < length; i++)
    {
        if(arr[i] == num)
            return i;
    }
    return -1;
}
