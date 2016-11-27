#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char arr[81];
    gets(arr);
    int length = strlen(arr);

    for(i = length -1, j = length -1; i >= 0; i--){
        if(arr[i] == ' '){
            int k;
            for(k = i +1; k <= j; k++){
                printf("%c", arr[k]);
            }
            printf(" ");
            j = i -1;
        }
    }
    for(i = 0; i <= j; i++){
        printf("%c", arr[i]);
    }
    return 0;
}
