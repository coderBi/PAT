/*************************************************************
上一个版本的毛病是没有处理特殊的错误输入，例如输入--应该也是错的
因为这里没有引入（）
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Calculate(int n1, int n2, char c);

int main()
{
    char c, op;
    int n1 = 0, n2 = 0;
    scanf("%c", &c);

    while(c >= '0' && c <= '9')
    {
        n1 *= 10;
        n1 += c - '0';
        scanf("%c", &c);
    }
    op = c;

    while(op != '=')
    {
        int count = 0;
        scanf("%c", &c);
        while(c >= '0' && c <= '9')
        {
            n2 *= 10;
            n2 += c - '0';
            count++;
            scanf("%c", &c);
        }
        if(count == 0)
        {
            printf("ERROR\n");
            exit(0);
        }
        n1 = Calculate(n1, n2, op);
        n2 = 0;
        op = c;
    }
    printf("%d", n1);
    return 0;
}

int Calculate(int n1, int n2, char c)
{
    if(c == '+')
        return n1 + n2;
    else if(c == '-')
        return n1 - n2;
    else if(c == '*')
        return n1*n2;
    else if(c == '/')
    {
        if(n2 == 0)
        {
            printf("ERROR");
            exit(0);
        }
        else
            return n1/n2;
    }
    else
    {
        printf("ERROR\n");
        exit(0);
    }
}
