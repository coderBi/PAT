#include <stdio.h>
#include <stdlib.h>

struct Vector{
    int num;
    int isInserted;
};

void Sort(struct Vector arr[], int length);
void Heapify(struct Vector arr[], int length, int pos);
void Swap(struct Vector* v1, struct Vector* v2);
int FindPos(struct Vector arr[], int length, int num);

int main()
{
    int n, i;
    scanf("%d", &n);
    struct Vector vt[n];
    struct Vector arr[n];
    int vLen = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i].num);
        arr[i].isInserted = 0;
        if(arr[i].num >= 0){
            vt[vLen].num = arr[i].num;
            vt[vLen].isInserted = 0;
            vLen++;
        }

    }
    Sort(vt, vLen);
    int res[vLen], resLen = 0;
    while(resLen < vLen){
        int j;
        int pos = vt[i].num%n;
        for(j = 0; j < vLen; j++){
            if(arr[pos].isInserted == 0 && arr[pos].num != vt[j].num){
                int find = FindPos(vt, vLen,  arr[pos].num);
                if(vt[find].isInserted == 0){
                    continue;
                } else {
                    pos++;
                }
            }
        }
    }
    return 0;
}

void Sort(struct Vector arr[], int length){
    int i;
    for(i = length -1; i >= 0; i--){
        Heapify(arr, length, i);
    }

    while(length > 1){
        Swap(&arr[0], &arr[length -1]);
        length--;
        Heapify(arr, length, 0);
    }
}

void Heapify(struct Vector arr[], int length, int pos){
    int child = 2*pos +1;

    if(child < length){
        if(child +1 < length && arr[child +1].num > arr[child].num){
            child++;
        }
        if(arr[pos].num < arr[child].num){
            Swap(&arr[pos], &arr[child]);
            Heapify(arr, length, child);
        }
    }
}

void Swap(struct Vector* v1, struct Vector* v2){
    struct Vector temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int FindPos(struct Vector arr[], int length, int num){
    int i = 0;
    for(; i < length; i++){
        if(arr[i].num == num){
            return i;
        }
    }
    return -1;
}
