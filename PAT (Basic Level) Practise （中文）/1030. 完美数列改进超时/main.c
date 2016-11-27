/*
    1，这里用堆排查看的结果也是一样，那个case 4 还是超时，但是看了下网上大家C++ 代码也就是直接sort，这里比较疑惑
    因为 nlogn 的复杂度的排序还是不够
    2, 为了验证超时是否是排序的复杂度不够，这里排序后不处理直接打印，提交后，发现之前超时的运行出来了 时间是19ms
        也就是说超时不是排序造成的，所以这里不用对排序方法在进行改进
*/
#include <stdio.h>
#include <stdlib.h>

void Heapify(int arr[], int heapTop, int length);
void HeapSort(int arr[], int length);
void Swap(int* a, int* b);

int main()
{
    int n, p, i, count;
    scanf("%d%d", &n, &p);
    int arr[n];

    for(i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    HeapSort(arr, n);

    double divide;

    //下面的处理是导致超时的原因，这里是逆向从大向小找，网上通过的是从小向大正向找，其实都是 n^2 复杂度
    /*for(count = n; count > 0; count--){
        for(i = 0; i + count <= n; i++){
            divide = (double) arr[i + count -1]/arr[i];
            if(divide <= p){
                break;
            }
        }
        if(i + count <= n){
            break;
        }
    }*/

    int j;
    for(count = 0, i = 0; i < n; i++){
        //正向解，这里可能可以去掉一些操作，但是与逆向解两者在极端情况都是 n^2 复杂度，
        //这里再增加下面的处理
        if(count >= n - i){
            break;
        }

        int max = 0;

        //结果仍然超时，下面这部分还需要改进
        /*for(j = i; j < n; j++){
            divide = (double) arr[j]/ arr[i];
            if(divide <= p){
                max = j - i +1;
            } else {
                break;
            }
        }*/

        //下面跟上面注释的改动是for里面的 j = i + count + 1
        for(j = i + count -1; j < n; j++){
            divide = (double) arr[j]/ arr[i];
            if(divide <= p){
                max = j - i +1;
            } else {
                break;
            }
        }
        if(max > count){
            count = max;
        }
    }
    printf("%d", count);
    return 0;
}

void HeapSort(int arr[], int length)
{
    int i;

    /*build heap*/
    for(i = length - 1; i >= 0; i--)
    {
        Heapify(arr, i, length);
    }

    while(length > 1)
    {
        Swap(&arr[0], &arr[length - 1]);
        Heapify(arr, 0, length - 1);
        length--;
    }
    return;

}

/*adjust heap top*/
void Heapify(int arr[], int heapTop, int length)
{
    int child = heapTop*2 + 1;

    if(child < length)
    {
        if((child + 1) < length && arr[child + 1] > arr[child])
        {
            child++;
        }
        if(arr[heapTop] < arr[child])
        {
            Swap(&arr[heapTop], &arr[child]);
            Heapify(arr, child, length);
        }
    }
    return;
}

void Swap(int* a, int* b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
    return;
}

