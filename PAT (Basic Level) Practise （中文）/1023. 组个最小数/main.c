#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, arr[10] = {0};

    for(i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    for(i = 1; i < 10; i++){
        if(arr[i] != 0){
            printf("%d", i);
            arr[i]--;
            break;
        }
    }

    if(i == 10){
        printf("0");
        return 0;
    }
    for(i = 0; i < 10; i++){
        while(arr[i] != 0){
            printf("%d", i);
            arr[i]--;
        }
    }
    return 0;
}
