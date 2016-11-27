#include <stdio.h>
#include <stdlib.h>

struct Key{
    int num;
    int isCovered;
};

void Sort(int arr[], int length);

int main()
{
    int k, i, length = 0;
    scanf("%d", &k);
    struct Key arr[k];
    int res[k];

    for(i = 0; i < k; i++){
        scanf("%d", &arr[i].num);
        arr[i].isCovered = 0;
    }
    for(i = 0; i < k; i++){
        if(arr[i].isCovered == 0){
            int x = arr[i].num, j;
            while(x != 1){
                if(x%2 == 0){
                    x /= 2;
                } else {
                    x = (3*x + 1)/2;
                }

                for(j = 0; j < k; j++){
                    if(j != i && arr[j].num == x && arr[j].isCovered == 0){
                        arr[j].isCovered = 1;
                        //由于题目保证了输入没有相同的数字，所以这里找到了就可以break了
                        break;
                    }
                }
            }
        }
    }

    for(i = 0; i < k; i++){
        if(arr[i].isCovered == 0){
            res[length++] = arr[i].num;
        }
    }
    Sort(res, length);
    for(i = length -1; i > 0; i--){
        printf("%d ", res[i]);
    }
    printf("%d", res[0]);
    return 0;
}

void Sort(int arr[], int length){
    int i, j;
    for(i = 1; i < length; i++){
        int temp = arr[i];
        for(j = i -1; j >= 0 && arr[j] > temp; j--){
            arr[j +1] = arr[j];
        }
        arr[j + 1] = temp;
    }
    return;
}
