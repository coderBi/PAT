#include <stdio.h>

void PrintWS(int num);

int main()
{
    int m, n ,i;
    scanf("%d %d", &m, &n);

    for(i = m; i <= n; i++)
    {
        PrintWS(i);
    }
}

void PrintWS(int num)
{
    int length = 0, i;
    int arr[num], sum = 1;

    for(i = 2; i <= num/2; i++)
    {
        if(num%i == 0)
        {
            arr[length++] = i;
        }
    }

    for(i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    if(sum == num)
    {
        int j;
        if(length == 0)
        {
            printf("1 = 1\n");
            return;
        }

        printf("%d = 1 + ", num);
        for(j = 0; j < length - 1; j++)
        {
            printf("%d + ", arr[j]);
        }
        printf("%d\n", arr[length - 1]);
    }
    return;
}
