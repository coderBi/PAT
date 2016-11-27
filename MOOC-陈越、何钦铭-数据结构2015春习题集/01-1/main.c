#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max = 0, sum = 0;
    int m, n;
    int i = 0;
    scanf("%d", &m);
    while(i++ < m)
    {
        scanf("%d", &n);
        sum += n;
        if(sum > max)
            max = sum;
        if(sum < 0)
        {
            sum = 0;
        }
    }
    printf("%d", max);
    return 0;
}
