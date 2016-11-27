/*
    一开始有个case没有通过好像是因为，给的第二个序列可能既不是插入也不是归并排序
*/
#include <stdio.h>
#include <stdlib.h>

void MergeSort(int arr[], int length, int step);
void InsertSort(int arr[], int length, int pos);
int Compare(int src[], int des[], int length);
void PrintArr(int arr[], int length);

int main()
{
    int n, i;
    scanf("%d", &n);
    int src[n], des[n], cpy[n];

    for(i = 0; i < n; i++){
        scanf("%d", &src[i]);
        cpy[i] = src[i];
    }
    for(i = 0; i < n; i++){
        scanf("%d", &des[i]);
    }

    int step = 1;
    while(step < n){
        MergeSort(src, n, step);
        if(Compare(src, des, n) == 0){
            printf("Merge Sort\n");
            MergeSort(src, n, 2*step);
            PrintArr(src, n);
            exit(0);
        }
        step *= 2;
    }

    int pos = 1;
    while(pos < n){
        InsertSort(cpy, n, pos);
        if(Compare(cpy, des, n) == 0){
            printf("Insertion Sort\n");
            InsertSort(cpy, n, pos + 1);
            PrintArr(cpy, n);
            break;
        }
        pos++;
    }


    return 0;
}

void MergeSort(int arr[], int length, int step){
    int i, j, k;
    int res[length], resLen = 0;

    for(i = 0; i + step <= length; i += 2*step){
        int rear = i + 2*step;
        if(rear > length){
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

void InsertSort(int arr[], int length, int pos){
    if(pos >= length || pos < 1){
        return;
    }

    int i;
    int temp = arr[pos];
    for(i = pos -1; i >= 0 && arr[i] > temp; i--){
        arr[i +1] = arr[i];
    }
    arr[i +1] = temp;
}

int Compare(int src[], int des[], int length){
    int i;
    for(i = 0; i < length; i++){
        if(src[i] != des[i]){
            return 1;
        }
    }
    return 0;
}

void PrintArr(int arr[], int length){
    if ( length <= 0){
        return;
    }
    int i;
    for(i = 0; i < length -1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[length -1]);
}
