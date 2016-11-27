#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in, i, flag = -1;
    scanf("%d", &in);
    for(i = in; i/10 != 0; i = i/10)
    {
        if(flag == -1 && i%10 == 0)
            continue;
        else
        {
            printf("%d", i%10);
            flag = 1;
        }
    }
    printf("%d", i);
    return 0;
}
