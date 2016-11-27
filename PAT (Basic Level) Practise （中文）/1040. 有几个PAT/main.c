/*
    这里的算法复杂度是 n^3 所以会超时，下一个版本将解决超时问题
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100010
#define MODEL 1000000007

int main()
{
    char arr[MAX_SIZE];
    gets(arr);
    int i, j, k, length = strlen(arr), res = 0;

    for(i = 0; i < length; i++){
        if(arr[i] == 'P'){
            for(j = i; j < length; j++){
                if(arr[j] == 'A'){
                    for(k = j; k < length; k++){
                        if(arr[k] == 'T'){
                            res++;
                            res %= MODEL;
                        }
                    }
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
