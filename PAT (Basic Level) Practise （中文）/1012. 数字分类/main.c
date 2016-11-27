#include <stdio.h>
#include <stdlib.h>

struct Res{
    int* arr;
    int length;
};

int main()
{
    int i, n, x;
    struct Res res[5] = {{NULL, 0}};
    scanf("%d", &n);
    for(i = 0; i < 5; i++){
        res[i].arr = (int*) malloc(sizeof(int) * n);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        int y = x%5;
        switch(y){
        case 0:
            if(x%2 == 0){
                res[0].arr[res[0].length++] = x;
            }
            break;
        case 1:
            res[1].arr[res[1].length++] = x;
            break;
        case 2:
            res[2].arr[res[2].length++] = x;
            break;
        case 3:
            res[3].arr[res[3].length++] = x;
            break;
        case 4:
            res[4].arr[res[4].length++] = x;
            break;
        default:
            break;
        }
    }

    if(res[0].length == 0){
        printf("N ");
    } else {
        int sum = 0;
        for(i = 0; i < res[0].length; i++){
            sum += res[0].arr[i];
        }
        printf("%d ", sum);
    }

    if(res[1].length == 0){
        printf("N ");
    } else {
        int sum = 0, flag = 1;
        for(i = 0; i < res[1].length; i++){
            sum += flag * res[1].arr[i];
            if(flag == 1){
                flag = -1;
            } else {
                flag = 1;
            }
        }
        printf("%d ", sum);
    }

    if(res[2].length == 0){
        printf("N ");
    } else {
        printf("%d ", res[2].length);
    }

    if(res[3].length == 0){
        printf("N ");
    } else {
        int sum = 0;
        for(i = 0; i < res[3].length; i++){
            sum += res[3].arr[i];
        }
        printf("%.1lf ", (double) sum / res[3].length);
    }

    if(res[4].length == 0){
        printf("N");
    } else {
        int max = res[4].arr[0];
        for(i = 1; i < res[4].length; i++){
            if(max < res[4].arr[i]){
                max = res[4].arr[i];
            }
        }
        printf("%d", max);
    }
    return 0;
}
