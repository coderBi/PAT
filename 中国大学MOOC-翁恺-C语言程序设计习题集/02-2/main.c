#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in, ad, min, hour;
    scanf("%d %d", &in, &ad);

    min  = in%100 + ad;
    hour = in/100 + min/60;
    min %= 60;
    if(min < 0)
    {
        min += 60;
        hour--;
    }
    if(min >= 10)
    {
        printf("%d%d", hour, min);
    }
    else
    {
        printf("%d0%d", hour, min);
    }
    return 0;
}
