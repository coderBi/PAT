#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPONENT 2001

struct Multi{
    double coefficient;
    int exponent;
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

    double res[MAX_EXPONENT] = {0};
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            res[mul1[i].exponent + mul2[j].exponent] += mul1[i].coefficient * mul2[j].coefficient;
        }
    }

    int count = 0;
    for(i = 0; i < MAX_EXPONENT; i++){
        if(res[i] != 0){
            count++;
        }
    }
    printf("%d", count);
    for(i = MAX_EXPONENT - 1; i >= 0; i--){
        if(res[i] != 0){
            printf(" %d %.1lf", i, res[i]);
        }
    }
    return 0;
}
