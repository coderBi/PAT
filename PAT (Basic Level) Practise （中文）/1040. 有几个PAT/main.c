/*
    ������㷨���Ӷ��� n^3 ���Իᳬʱ����һ���汾�������ʱ����
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
