#include <stdio.h>
#include <stdlib.h>

struct Multi{
    int exponent;
    double coefficient;
};
int main()
{
    int m, n, i, j;
    scanf("%d", &m);
    struct Multi mul1[m];

    for(i = 0; i < m; i++){
        scanf("%d %lf", &mul1[i].exponent, &mul1[i].coefficient);
    }
    scanf("%d", &n);
    struct Multi mul2[n];
    for(i = 0; i < n; i++){
        scanf("%d %lf", &mul2[i].exponent, &mul2[i].coefficient);
    }

    struct Multi res[m + n];
    int resLen = 0;
    for(i = 0, j = 0; i < m && j < n;){
        if(mul1[i].exponent > mul2[j].exponent){
            res[resLen++] = mul1[i];
            i++;
        } else if (mul1[i].exponent < mul2[j].exponent){
            res[resLen++] = mul2[j];
            j++;
        } else {
            res[resLen].exponent = mul1[i].exponent;
            res[resLen].coefficient = mul1[i].coefficient + mul2[j].coefficient;
            i++;
            j++;
            if(res[resLen].coefficient != 0){
                resLen++;
            }
        }
    }
    while(i < m){
        res[resLen++] = mul1[i++];
    }
    while(j < n){
        res[resLen++] = mul2[j++];
    }

    if(resLen == 0){
        printf("0");
        return 0;
    }
    printf("%d ", resLen);
    for(i = 0; i < resLen -1; i++){
        printf("%d %.1lf ", res[i].exponent, res[i].coefficient);
    }
    printf("%d %.1lf", res[resLen -1].exponent, res[resLen -1].coefficient);
    return 0;
}

