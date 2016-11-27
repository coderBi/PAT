#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, n, i, sum = 0, ad = 0;
    scanf("%d %d", &a, &n);
    for(i = 0; i < n; i++)
    {
        ad *= 10;
        ad += a;
        sum += ad;
    }
    printf("%d", sum);
    return 0;
}
