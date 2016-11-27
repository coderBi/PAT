#include <stdio.h>
#include <stdlib.h>

struct Hash{
    int school;
    int score;
};

int IsPrime(int x);
int FindInHash(struct Hash arr[], int length, struct Hash has);

int main()
{
    int n, i;
    struct Hash input;
    scanf("%d", &n);
    int length = 2 * n;
    for(; (length - 3)%4 != 0 || IsPrime(length) == 0; length++){

    }
    struct Hash arr[length];
    for(i = 0; i < length; i++){
        arr[i].school = arr[i].score = 0;
    }

    int pos, max = 0;
    for(i = 0; i < n; i++){
        scanf("%d%d", &input.school, &input.score);
        pos = FindInHash(arr, length, input);
        if(pos == -1){
            printf("hash insert failed\n");
            exit(0);
        }
        arr[pos].score += input.score;
        arr[pos].school = input.school;
    }
    for(i = 1; i < length; i++){
        if(arr[max].score < arr[i].score){
            max = i;
        }
    }
    printf("%d %d", arr[max].school, arr[max].score);
    return 0;
}

int IsPrime(int x){
    if(x < 2){
        return 0;
    }

    int i;
    for(i = 2; i*i <= x; i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}

int FindInHash(struct Hash arr[], int length, struct Hash has){
    int pos = has.school%length, i;

    for(i = 0; i < length; i++){
        if(arr[(pos + i*i)%length].school == 0 || arr[(pos + i*i)%length].school == has.school){
            return pos + i*i;
        }
    }
    return -1;

}
