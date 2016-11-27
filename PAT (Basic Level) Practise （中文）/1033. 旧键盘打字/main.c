#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100010

int main()
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int m, n, i, j, flag = 0;

    gets(str1);
    gets(str2);
    m = strlen(str1);
    n = strlen(str2);

    for(i = 0; i < m; i++){
        if(str1[i] == '+'){
            flag = 1;
            break;
        }
    }
    for(i = 0; i < n; i++){
        char ch = str2[i];
        for(j = 0; j < m; j++){
            if(ch >= 'a' && ch <= 'z'){
                ch += 'A' - 'a';
            }
            if(str1[j] == ch){
                break;
            }
        }
        if(j < m || (str2[i] >= 'A' && str2[i] <= 'Z' && flag == 1)){
            continue;
        }
        printf("%c", str2[i]);
    }
    return 0;
}
