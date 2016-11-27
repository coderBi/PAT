#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int n, i, j, sum = 0, flag = 0;
    int mul[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    scanf("%d", &n);
    getchar();
    char identify[n][19];
    for(i = 0; i < n; i++){
        gets(identify[i]);
    }

    for(i = 0; i < n; i++){
        sum = 0;
        for(j = 0; j < 17; j++){
            sum += mul[j] * (identify[i][j] - '0');
            sum %= 11;
        }
        if(arr[sum] != identify[i][17]){
            printf("%s\n", identify[i]);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("All passed");
    }
    return 0;
}
