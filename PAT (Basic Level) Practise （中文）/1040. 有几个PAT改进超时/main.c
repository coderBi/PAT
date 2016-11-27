#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100010
#define MODEL 1000000007

int main()
{
    char arr[MAX_SIZE];
    gets(arr);
    int i, length = strlen(arr);
    long long np = 0, na = 0, res = 0;

    for(i = 0; i < length; i++){
        if(arr[i] == 'P'){
            np++;
        } else if(arr[i] == 'A'){
            na += np;
            na %= MODEL;
        } else if(arr[i] == 'T'){
            res += na;
            res %= MODEL;
        }
    }
    printf("%lld", res);
    return 0;
}
