#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 100

int main()
{
    int i, j, n, x, length = 0;
    scanf("%d", &n);
    int arr[n];

    for(i = 0; i < n; i++){
        arr[i] = 0;
    }

    for(i = 0; i < n; i++){
        scanf("%d", &x);
        for(j = 0; j < length; j++){
            if(arr[j] + x <= MAX_WEIGHT){
                arr[j] += x;
                printf("%d %d\n", x, j+1);
                break;
            }
        }
        if(j >= length){
            printf("%d %d\n", x, length +1);
            arr[length++] += x;
        }
    }
    printf("%d", length);
    return 0;
}
