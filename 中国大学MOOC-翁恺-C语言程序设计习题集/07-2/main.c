/*************************************************************
1,��һ����a b c ��Χ����[-2^31, 2^31], ����a + b ���ܻ����
2���������ԣ���ʵ���з���int �����Ǳ�����[-2^31, 2^31]����������Ҳ�������
���������Ȼ������ô����Χ����ʵ����������������ֻ��һ������2^31
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

        if((a > 0 && b > 0) || (a < 0 && b < 0))  //����ͬ�����
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
