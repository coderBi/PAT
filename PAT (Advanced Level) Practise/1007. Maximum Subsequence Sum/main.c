#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, i, j;
    scanf("%d", &k);
    int arr[k];

    for(i = 0; i < k; i++){
        scanf("%d", &arr[i]);
    }

    int max = arr[0], front = 0, rear = 0, sum = 0;
    for(i = 0, j = 0; i < k && j < k; j++){
        sum += arr[j];

        if(sum > max){
            max = sum;
            front = i;
            rear = j;
        }

        if(sum < 0){
            sum = 0;
            i = j + 1;
        }
    }
    if(max < 0){
        printf("0 %d %d", arr[0], arr[k -1]);
    } else {
        printf("%d %d %d", max, arr[front], arr[rear]);
    }

    return 0;
}
