#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, sum;
    scanf("%d %d", &a, &b);
    sum = a + b;

    int arr[4], flag = 1, length = 0;

    if(sum < 0){
        flag = -1;
        sum *= -1;
    }
    while(sum/1000 != 0){
        arr[length++] = sum%1000;
        sum /= 1000;
    }
    arr[length++] = sum;

    if(flag == -1){
        printf("-");
    }

    int i;
    for(i = length -1; i > 0; i--){
        if(i == length -1){
            printf("%d,", arr[i]);
        } else {
            printf("%.3d,", arr[i]);
        }
    }
    if(0 == length -1){
        printf("%d", arr[0]);
    } else {
        printf("%.3d", arr[0]);
    }
    return 0;
}
