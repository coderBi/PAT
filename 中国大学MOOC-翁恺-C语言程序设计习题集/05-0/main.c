#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i;
    double sum = 0;
    double d1 = 2.0;
    double d2 = 1.0;

    scanf("%d", &N);
    sum += d1/d2;
    for(i = 1; i < N; i++)
    {
        d1 += d2;
        d2 = d1 - d2;
        sum += d1/d2;
    }
    printf("%.2lf", sum);
    return 0;
}
