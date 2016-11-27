#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1010

int main()
{
    int i, j, m, n;
    char src[MAX_LENGTH], des[MAX_LENGTH];
    gets(src);
    gets(des);

    m = strlen(src);
    n = strlen(des);
    int flag[n];
    for(i = 0; i < n; i++){
        flag[i] = 0;
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(des[j] == src[i] && flag[j] == 0){
                flag[j] = 1;
                break;
            }
        }
    }

    int count = 0;
    for(i = 0; i < n; i++){
        if(flag[i] == 0){
            count++;
        }
    }
    if(count == 0){
        printf("Yes %d", m - n);
    } else {
        printf("No %d", count);
    }
    return 0;
}
