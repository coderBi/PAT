#include <stdio.h>
#include <stdlib.h>

void Insert2Heap(int arr[], int pos);
void Swap(int arr[], int index1, int index2);
void ListPath2Root(int arr[], int pos);

int main()
{
    int n, m, i;
    scanf("%d%d", &n, &m);
    int arr[n +1], indexs[m];
    for(i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 1; i <= n; i++){
        Insert2Heap(arr, i);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &indexs[i]);
    }
    for(i = 0; i < m; i++){
        ListPath2Root(arr, indexs[i]);
    }
    return 0;
}


void Insert2Heap(int arr[], int pos){
    if(pos <= 1){
        return;
    }
    int i = pos/2;
    if(arr[i] > arr[pos]){
        Swap(arr, pos, i);
        Insert2Heap(arr, i);
    }
}

void Swap(int arr[], int index1, int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

void ListPath2Root(int arr[], int pos){
    int i = pos;
    while(i > 1){
       printf("%d ", arr[i]);
       i /= 2;
    }
    printf("%d\n", arr[1]);
}
