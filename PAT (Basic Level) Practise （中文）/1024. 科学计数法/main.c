#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int main()
{
    char arr[MAX_SIZE];
    int i, length = 0, pos1 = 0, pos2 = 0, index = 0;

    gets(arr);
    length = strlen(arr);
    for(i = 1; i < length; i++){
        if(arr[i] == '.'){
            pos1 = i;
            break;
        }
    }
    for(++i; i < length; i++){
        if(arr[i] == 'E'){
            pos2 = i;
            break;
        }
    }
    for(i += 2; i < length; i++){
        index *= 10;
        index += arr[i] - '0';
    }

    if(arr[pos2 +1] == '+'){
        pos1 += index;

    } else if(arr[pos2 +1] == '-'){
        pos1 -= index;
    }

    if(arr[0] == '-'){
        printf("-");
    }

    if(pos1 < 1){
        printf("0.");
        for(i = pos1; i < 1; i++){
            printf("0");
        }
        printf("%c", arr[1]);
        for(i = 3; i < pos2; i++){
            printf("%c", arr[i]);
        }
    } else if( pos1 == 1){
        for(i = 1; i < pos2; i++){
            printf("%c", arr[i]);
        }
    } else {
        printf("%c", arr[1]);
        for(i  = 3; i <= pos1 && i < pos2; i++){
            printf("%c", arr[i]);
        }
        if(pos1 >= pos2 -1){
            for(i = pos2; i <= pos1; i++){
                printf("0");
            }
        } else {
            printf(".");
            for(i = pos1 +1; i < pos2; i++){
                printf("%c", arr[i]);
            }
        }
    }
    return 0;
}
