/******************************************************
这一题就是10进制到16进制
*********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in;
    scanf("%d", &in);
    if(in/16 != 0)
    {
        printf("%d%d", in/16, in%16);
    }
    else
    {
        printf("%d", in);
    }
    return 0;
}
