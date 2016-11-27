#include <stdio.h>
#include <stdlib.h>

#define CLK_TCK 100

int main()
{
    int cl1, cl2, hour, minute, second;
    scanf("%d%d", &cl1, &cl2);

    int sub = cl2 - cl1;
    second = sub/CLK_TCK;
    if(sub%CLK_TCK >= CLK_TCK/2){
        second++;
    }
    minute = second/60;
    second %= 60;
    hour = minute/60;
    minute %= 60;
    printf("%.2d:%.2d:%.2d", hour, minute, second);
    return 0;
}
