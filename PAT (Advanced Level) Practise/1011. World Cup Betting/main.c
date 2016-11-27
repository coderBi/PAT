/*
    1，这里虽然通过了所有的case，但是暴漏了double  float 在内存中二进制表示不完全的问题
    2，目前只能想到BigDecimal的解决方法
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char res[3] = {'W', 'T', 'L'};
    float sum = 1.0f, arr[3][3];
    int i, j, sp[3];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%f", &arr[i][j]);
        }
    }
    for(i = 0; i < 3; i++){
        sp[i] = 0;
        for(j = 1; j < 3; j++){
            if(arr[i][sp[i]] < arr[i][j]){
                sp[i] = j;
            }
        }
    }
    for(i = 0; i < 3; i++){
        printf("%c ", res[sp[i]]);
        sum *= arr[i][sp[i]];
    }
    sum = (sum * 0.65 -1)*2.0;

    //这里发现边界情况例如。0975000这样（计算出来的结果）的在内存中二进制表示可能导致出现打印异常
    //针对这种情况，目前只能想到像java中的BigDecimal 那样当初字符串来处理
    printf("%.2f", sum);
    return 0;
}
