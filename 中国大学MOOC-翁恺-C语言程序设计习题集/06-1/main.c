#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char oper;
    scanf("%d%c", &a,&oper);
    while(oper != '=')
    {
        if(oper != '+' && oper != '-' && oper != '*' && oper != '/')
        {
            printf("ERROR");
            break;
        }
        scanf("%d", &b);
        if(oper == '/' && b == 0)
        {
            printf("ERROR");
            break;
        }
        else
        {
            if(oper == '+')
            {
                a += b;
            }
            else if(oper == '-' )
            {
                a -= b;
            }
            else if(oper == '*' )
            {
                a *= b;
            }
            else
            {
                a /= b;
            }
        }
        scanf("%c", &oper);
    }
    printf("%d", a);
    return 0;
}
