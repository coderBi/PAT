/************************************************************
这一题其实就是求解分子分母的最大公因子
************************************************************/
#include <stdio.h>
#include <stdlib.h>

int FindMaxGY(int a, int b);

int main()
{
    int a, b, gy;
    scanf("%d/%d", &a, &b);
    gy = FindMaxGY(a,b);
    printf("%d/%d", a/gy, b/gy);
    return 0;
}

int FindMaxGY(int a, int b)
{
    int temp;
    if(a < b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    while(a%b != 0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return b;
}
