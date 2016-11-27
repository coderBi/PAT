#include <stdio.h>
#include <stdlib.h>

void InsertSort(long arr[], long length);
void InsertOneNumber(long arr[], long subscript);
void PrintArray(long arr[], long length);
void Swap(long* a, long* b);
void InsertSortInQuik(long arr[], long first, long last);
long Median(long arr[], long first, long last);
void QuickSort(long arr[], long first, long last);

int main()
{
    long N, i;
    scanf("%ld", &N);
    long arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%ld", &arr[i]);
    }
    if(N < 100)
        InsertSort(arr, N);
    else
        QuickSort(arr, 0, N - 1);
    PrintArray(arr, N);
    return 0;
}

void InsertSort(long arr[], long length)
{
    long i;

    for(i = 0; i < length; i++)
    {
        InsertOneNumber(arr, i);
    }
    return;
}

void InsertOneNumber(long arr[], long subscript)
{
    long i;
    long temp = arr[subscript];

    for(i = subscript - 1; i >= 0; i--)
    {
        if(arr[i] > temp)
        {
            arr[i + 1] = arr[i];
        }
        else
        {
            break;
        }
    }
    arr[i + 1] = temp;
    return;
}

void PrintArray(long arr[], long length)
{
    long i;

    if(length <= 0)
        return;
    for(i = 0; i < length - 1; i++)
    {
        printf("%ld ", arr[i]);
    }
    printf("%ld", arr[length - 1]);
    return;
}

void QuickSort(long arr[], long first, long last)
{
    /*length <= 3 use InsertSort*/
    if(last - first < 3)
    {
        InsertSortInQuik(arr, first, last);
    }
    else
    {
        long key = Median(arr, first, last);
        long i, j;

        for(i = first, j = last - 1; i < j; i++, j--)
        {
            while(arr[++i] < key && i < j){}
            while(arr[--j] > key && i < j){}
            if(i < j)
            {
                Swap(&arr[i], &arr[j]);
            }
            else
                break;
        }
        Swap(&arr[i], &arr[last - 1]);
        QuickSort(arr, first, i - 1);
        QuickSort(arr, i + 1, last);
    }
    return;
}

void Swap(long* a, long* b)
{
    long temp = *a;

    *a = *b;
    *b = temp;
    return;
}

void InsertSortInQuik(long arr[], long first, long last)
{
    long i;

    for(i = first + 1;i <= last; i++)
    {
        long temp = arr[i];
        long j = i - 1;

        while(j >= first && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return;
}

long Median(long arr[], long first, long last)
{
    long mid = (first + last)/2;

    if(arr[first] > arr[mid])
    {
        Swap(&arr[first], &arr[mid]);
    }
    if(arr[first] > arr[last])
    {
        Swap(&arr[first], &arr[last]);
    }
    if(arr[mid] > arr[last])
    {
        Swap(&arr[last], &arr[mid]);
    }
    Swap(&arr[mid], &arr[last - 1]);
    return arr[last - 1];
}
