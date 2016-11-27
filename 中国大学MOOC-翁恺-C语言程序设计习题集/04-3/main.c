#include <stdio.h>
#include <stdlib.h>

int IsPrime(int num);

int main()
{
    int M, N, sum = 0, i, count = 0;
    scanf("%d %d", &M, &N);
    for(i = M; i <= N; i++)
    {
        if(IsPrime(i) == 1)
        {
            count++;
            sum += i;
        }
    }
    printf("%d %d", count, sum);
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
