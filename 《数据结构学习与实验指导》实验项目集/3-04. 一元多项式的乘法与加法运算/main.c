#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 2010

struct Multinomial{
    int modulus;
    int index;
};

void PrintResArr(int arr[], int length);

int main()
{
    int i, j, n, k, res1[MAX_LENGTH] = {0}, res2[MAX_LENGTH] = {0};

    scanf("%d", &n);
    struct Multinomial mulT1[n];
    for(i = 0; i < n; i++){
        scanf("%d %d", &mulT1[i].modulus, &mulT1[i].index);
    }

    scanf("%d", &k);
    struct Multinomial mulT2[k];
    for(i = 0; i < k; i++){
        scanf("%d %d", &mulT2[i].modulus, &mulT2[i].index);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            int index = mulT1[i].index + mulT2[j].index;
            int modulus = mulT1[i].modulus * mulT2[j].modulus;
            res1[index] += modulus;
        }
    }

    for(i = 0, j = 0; i < n && j < k;){
        if(mulT1[i].index == mulT2[j].index){
            res2[mulT1[i].index] += mulT1[i].modulus + mulT2[j].modulus;
            i++;
            j++;
        } else if(mulT1[i].index > mulT2[j].index){
            res2[mulT1[i].index] += mulT1[i].modulus;
            i++;
        } else {
            res2[mulT2[j].index] += mulT2[j].modulus;
            j++;
        }
    }
    while(i < n){
        res2[mulT1[i].index] += mulT1[i].modulus;
        i++;
    }
    while(j < k){
        res2[mulT2[j].index] += mulT2[j].modulus;
        j++;
    }
    PrintResArr(res1, MAX_LENGTH);
    PrintResArr(res2, MAX_LENGTH);
    return 0;
}

void PrintResArr(int arr[], int length){
    int resLen = 0, i;
    struct Multinomial res[MAX_LENGTH] = {{0, 0}};

    for(i = length -1; i >= 0; i--){
        if(arr[i] != 0){
            res[resLen].index = i;
            res[resLen].modulus = arr[i];
            resLen++;
        }
    }
    if(resLen <= 0){
        printf("0 0\n");
        return;
    }

    for(i = 0; i < resLen -1; i++){
        printf("%d %d ", res[i].modulus, res[i].index);
    }
    printf("%d %d\n", res[resLen -1].modulus, res[resLen -1].index);
    return;
}
