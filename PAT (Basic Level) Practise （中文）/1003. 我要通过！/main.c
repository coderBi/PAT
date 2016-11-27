#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101

int main()
{
    int n, i;
    scanf("%d", &n);
    char arr[n][MAX_SIZE];
    int res[n];
    getchar();

    for(i = 0; i < n; i++){
        res[i] = 0;
        gets(arr[i]);
    }

    for(i = 0; i < n; i++){
        int length = strlen(arr[i]);
        int j, a = 0, b = -1, c = 0;

        for(j = 0; j < length && arr[i][j] == 'A'; j++){
            a++;
        }
        if(arr[i][j] != 'P'){
            continue;
        }
        for(++j; j < length && arr[i][j] == 'A'; j++){
            b++;
        }
        if(b < 0){
            continue;
        }
        if(arr[i][j] != 'T'){
            continue;
        }
        for(++j; j < length && arr[i][j] == 'A'; j++){
            c++;
        }
        if(j !=  length || c < (a*b + a)){
            continue;
        }
        res[i] = 1;
    }

    for(i = 0; i < n; i++){
        if(res[i] == 0){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
