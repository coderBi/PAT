#include <stdio.h>
#include <stdlib.h>

void InsertOneNumber(int* arr, int subscript);
void PrintArray(int arr[], int length);
int MatchArr(int arr1[], int arr2[], int length);
void Merge(int arr[], int low, int mid, int high);
void MergeOneStep(int arr[], int step, int length);

int main()
{
    int N, i = 0, step = 1;
    scanf("%d", &N);
    int arr1[N], arr2[N], des[N];
    while(i < N)
    {
      scanf("%d", &arr1[i]);
      arr2[i] = arr1[i];
      i++;
    }
    for(i = 0; i < N; i++)
    {
        scanf("%d", &des[i]);
    }
    for(i = 1; i < N; i++)
    {
        InsertOneNumber(arr1, i);
        if(MatchArr(arr1, des, N) == 1)
        {
            printf("Insertion Sort\n");
            InsertOneNumber(arr1, i + 1);
            PrintArray(arr1, N);
            exit(0);
        }
    }
    for(step = 1; step < N; step *= 2)
    {
        MergeOneStep(arr2, step, N);
        if(MatchArr(arr2, des, N) == 1)
        {
            printf("Merge Sort\n");
            MergeOneStep(arr2, 2*step, N);
            PrintArray(arr2, N);
            exit(0);
        }
    }
    return 0;
}

void InsertOneNumber(int* arr, int subscript)
{
    int i;
    int temp = arr[subscript];

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

void PrintArray(int arr[], int length)
{
    int i;

    for(i = 0; i < length - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[length - 1]);
    return;
}

int MatchArr(int arr1[], int arr2[], int length)
{
    int i = 0;
    while(i < length)
    {
        if(arr1[i] != arr2[i])
            return 0;
        i++;
    }
    return 1;
}

void MergeOneStep(int arr[], int step, int length)
{
    int i = 0;
    while(i + step - 1 < length)
    {
        if(i + 2*step - 1 < length)
            Merge(arr, i, i + step, i + 2*step - 1);
        else
            Merge(arr, i, i + step, length - 1);
        i += 2*step;
    }
    return;
}

void Merge(int arr[], int low, int mid, int high)
{
    if(mid > high)
        return;
    int i = low, j = mid, k = 0;
    int arr1[high - low + 1];
    while(i < mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            arr1[k++] = arr[i];
            i++;
        }
        else
        {
            arr1[k++] = arr[j];
            j++;
        }
    }
    if(i == mid)
    {
        while(j <= high)
            arr1[k++] = arr[j++];
    }
    else
    {
        while(i < mid)
            arr1[k++] = arr[i++];
    }
    for(i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = arr1[k];
    }
    return;
}

