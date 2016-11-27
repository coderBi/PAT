#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    scanf("%d", &n);
    if(n/100 != 0)
    {
        for(i = 0; i < n/100; i++)
        {
            printf("B");
        }
    }
    n %= 100;
    if(n/10 != 0)
    {
        for(i = 0; i < n/10; i++)
        {
            printf("S");
        }
    }
    n %= 10;
    for(i = 1; i <= n; i++)
    {
        printf("%d", i);
    }
    return 0;
}
