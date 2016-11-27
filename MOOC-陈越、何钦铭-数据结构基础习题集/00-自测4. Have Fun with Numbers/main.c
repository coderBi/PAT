#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21

int main()
{
    char arr[MAX_LENGTH];
    gets(arr);
    int i, length = strlen(arr);
    int num[length], res[length +2], resLen = 0;
    int src[10] = {0}, des[10] = {0};

    for(i = 0; i < length + 2; i++){
        res[i] = 0;
    }
    for(i = length -1; i >= 0; i--){
        num[i] = arr[i] - '0';
        src[num[i]]++;
        res[resLen] += (num[i] * 2) % 10;
        res[resLen + 1] += (num[i] * 2) / 10;
        resLen++;
    }

    if(res[resLen] != 0){
        resLen++;
        if(res[resLen -1] >= 10){
            res[resLen] = res[resLen -1]/10;
            res[resLen - 1] %= 10;
            resLen++;
        }
    }
    for(i = 0; i < resLen; i++){
        des[res[i]]++;
    }
    for(i = 0; i < 10; i++){
        if(src[i] != des[i]){
            break;
        }
    }
    if(i < 10){
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    for(i = resLen - 1; i >= 0; i--){
        printf("%d", res[i]);
    }
    return 0;
}
