#include <stdio.h>
#include <stdlib.h>

int main()
{
    int res[101] = {0}, i, n, k, score;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &score);
        res[score]++;
    }
    scanf("%d", &k);
    int getRes[k];
    for(i = 0; i < k; i++){
        scanf("%d", &score);
        getRes[i] = res[score];
    }

    for(i = 0; i < k -1; i++){
        printf("%d ", getRes[i]);
    }
    printf("%d", getRes[k - 1]);
    return 0;
}
