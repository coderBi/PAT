/********************************************************
����֪����ÿһ�����룬һ����A4(3) = 24�����������ÿһ���ض��Ŀ�ʼ����
�� A3(2) = 6�����
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
