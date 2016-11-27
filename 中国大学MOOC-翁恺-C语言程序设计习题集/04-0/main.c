/********************************************************
可以知道对每一种输入，一共有A4(3) = 24个结果，对于每一个特定的开始数组
有 A3(2) = 6个输出
**********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in, i, j, k;
    scanf("%d", &in);
    for(i = in; i < in + 4; i++)
    {
        int count = 0;
        for(j = in; j < in + 4; j++)
        {
            if(j == i)
                continue;
            for(k = in; k < in + 4; k++)
            {
                if(k == i || k == j)
                    continue;
                else
                {
                    count++;
                    printf("%d%d%d", i, j, k);
                }
                if(count != 6)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
