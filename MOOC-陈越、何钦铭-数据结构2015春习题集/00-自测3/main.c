#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void PrintArray(int arr[], int length)
{
    int i = 0;
    while(i < length - 1)
        printf("%d ", arr[i++]);
    printf("%d", arr[length - 1]);
    return;
}

void MoveArray(int arr[], int n, int m)
{
    int i = 0;
    if(n <= 0)
        return;
    int temp = arr[0];
    while(i++ < m)
    {
        int j = 0;
        while(j < n)
        {
            int temp1 = arr[j];
            if(j == 0)
                arr[j] = arr[n -1];
            else
            {
                arr[j] = temp;
            }
            temp = temp1;
            j++;
        }
    }
    return;
}

int main()
{
    int n, m;
    int i = 0;
    int arr[MAX_LENGTH] = {0};
    scanf("%d %d", &n, &m);
    while(i < n)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    MoveArray(arr, n, m);
    PrintArray(arr, n);
    return 0;
}
