#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(int num)
{
    int i;
    if(num < 2)
        return 0;
    for(i = 2; i <= sqrt(num); i++)   //��������д��i <= sqrt(num) + 1�������ǵ� 2 ��������˻�������ʵֻҪ��֤��һ�߱�ȡ�ô����
    {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int M, N, i;
    scanf("%d %d", &M, &N);
    while(IsPrime(M) == 0)
    {
        M++;
    }
    int arr[M];
    for(i = 0; i < M; i++)
    {
        arr[i] = 0;
    }
    for(i = 0; i < N; i++)
    {
        int num, j = 0;
        scanf("%d", &num);
        while(j < M && arr[(num + j*j)%M] == 1)
        {
            j++;
        }
        if(j < M)
        {
            printf("%d", (num + j*j)%M);
            arr[(num + j*j)%M] = 1;
        }
        else
            printf("-");
        if(i != N -1)
            printf(" ");
    }
    return 0;
}
