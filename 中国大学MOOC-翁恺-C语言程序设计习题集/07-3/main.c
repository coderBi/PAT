#include <stdio.h>
#include <stdlib.h>

int IsPrime(int num);
void PrintRes(int arr[], int length);

int main()
{
    int M, N, i, count = 0;
    scanf("%d %d", &M, &N);
    int arr[N - M + 1];
    for(i = 2;;i++)
    {
        if(IsPrime(i) == 1)
        {
            count++;
            if(count > N)
                break;
            if(count >= M)
            {
                arr[count - M] = i;
            }
        }
    }
    PrintRes(arr, N - M +1);
    return 0;
}

int IsPrime(int num)
{
    int i;
    if(num < 2)
        return 0;
    for(i = 2; i*i <= num; i++)
    {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

void PrintRes(int arr[], int length)
{
    int i, count = 0;
    if(length <= 0)
        return;
    for(i = 0; i < length -1; i++)
    {
        printf("%d", arr[i]);
        count++;
        if(count%10 == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
    printf("%d", arr[length -1]);
    return;
}
