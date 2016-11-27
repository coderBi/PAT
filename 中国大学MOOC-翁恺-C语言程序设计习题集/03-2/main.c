#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b)
    {
        printf("C");
    }
    else if(a == c)
    {
        printf("B");
    }
    else
    {
        printf("A");
    }
    return 0;
}
