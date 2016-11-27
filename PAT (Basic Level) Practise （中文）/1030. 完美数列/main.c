/*
    1，这里采用自己写的归并排序，有一个case超时了
    2，下一个版本直接导入之前写的堆排看看结果
*/
#include <stdio.h>
#include <stdlib.h>

void Sort(int arr[], int length);
void Merge(int arr[], int length, int step);

int main()
{
    int n, p, i, count;
    scanf("%d%d", &n, &p);
    int arr[n];

    for(i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    Sort(arr, n);

    double divide;
    for(count = n; count > 0; count--){
        for(i = 0; i + count <= n; i++){
            divide = (double) arr[i + count -1]/arr[i];
            if(divide <= p){
                break;
            }
        }
        if(i + count <= n){
            break;
        }
    }
    printf("%d", count);
    return 0;
}

void Sort(int arr[], int length){
    int i;

    for(i = 1; i <= length; i *= 2){
        Merge(arr, length, i);
    }
}

void Merge(int arr[], int length, int step){
    int i;
    int res[length], resLen = 0;
    for(i = 0; i + step <= length; i += 2*step){
        int j, k, rear = i + 2*step;

        if(i + 2*step > length){
            rear = length;
        }
        for(j = i, k = i + step; j < i + step && k < rear;){
            if(arr[j] <= arr[k]){
                res[resLen++] = arr[j++];
            } else {
                res[resLen++] = arr[k++];
            }
        }
        while(j < i + step){
            res[resLen++] = arr[j++];
        }
        while(k < rear){
            res[resLen++] = arr[k++];
        }
    }
    for(i = 0; i < resLen; i++){
        arr[i] = res[i];
    }
}
