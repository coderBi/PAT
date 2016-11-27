#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in;
    scanf("%d", &in);
    if(in%5 > 0 && in%5 <= 3)
    {
        printf("Fishing ");
    }
    else
    {
        printf("Drying ");
    }
    printf("in day %d", in);
    return 0;
}
