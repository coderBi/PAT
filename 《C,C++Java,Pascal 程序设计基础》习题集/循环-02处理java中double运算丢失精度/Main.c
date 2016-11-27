/*
    *1，这里的C代码也没有通过第二个case，需要检查逻辑问题
    *2,最终，将所用到的所有int 全部修改为double 通过了测试。
    *3，目前猜测导致这样的差异是double高位表示的范围比int要大，而这里如果用int表示分子分母可能
        溢出了
*/
#include <stdio.h>

int main()
{
    double fz = 1, fm = 1;
    double i;
    double threshold, res = 0;

    scanf("%lf", &threshold);

    for(i = 1;; i++)
    {
        double x = fz/fm;
        res += x;
        if(x < threshold){
            break;
        }
        fz *= i;
        fm *= (2*i + 1);
    }
    printf("%.6lf", 2*res);
    return 0;
}
