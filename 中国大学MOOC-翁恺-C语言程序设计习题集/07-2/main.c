/*************************************************************
1,这一题中a b c 范围都在[-2^31, 2^31], 所以a + b 可能会溢出
2，经过测试，其实用有符号int 由于是闭区间[-2^31, 2^31]，所以输入也可能溢出
但是这里既然给了这么个范围，而实际上这里的输入溢出只有一个就是2^31
*************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, i, n;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", i);

        if((a > 0 && b > 0) || (a < 0 && b < 0))  //处理同号情况
        {
            if(a > 0 && c <= 0)
            {
                printf("true");
            }
            else if(a < 0 && c >= 0)
            {
                printf("false");
            }
            else if((c - a) < b)
            {
                printf("true");
            }
            else
            {
                printf("false");
            }
        }

        else if((a + b) > c)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
        printf("\n");
    }
    return 0;
}
