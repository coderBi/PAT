/*************************************************************
1，乍一看题目很简单，但是题目中给出了提示：可能出现输出-0.0的可能
这是因为只去了小数点后一位导致的
*************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x1, y1, x2, y2, resx, resy;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    resx = x1 + x2;
    resy = y1 +y2;

    if(resx > -0.05 && resx < 0.05)
    {
        resx = 0.0;
    }
    if(resy > -0.05 && resy < 0.05)
    {
        resy = 0.0;
    }
    printf("(%.1lf, %.1lf)", resx, resy);
    return 0;
}
