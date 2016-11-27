#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int a, b, d;
    scanf("%u %u %u", &a, &b, &d);
    int res[32], length = 0, i;

    unsigned int sum = a + b;

    while(sum/d != 0){
        res[length++] = sum%d;
        sum /= d;
    }
    res[length++] = sum;
    for(i = length -1; i >= 0; i--){
        printf("%d", res[i]);
    }
    return 0;
}
