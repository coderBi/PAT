#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 30

void PrintArray(int arr[], int length)
{
    int i = length - 1;
    while(i >= 0)
        printf("%d", arr[i--]);
    return;
}

int DoubleArray(int arr[], int dArr[], int n)
{
    int amass, i = 0;
    int length = n;
    if(n <= 0)
        return 0;
    while(i < n)
    {
        amass = 2*arr[i];
        dArr[i] += amass%10;
        dArr[++i] += amass/10;
    }
    if(dArr[length] != 0)
        length++;
    return length;
}

void InvertArray(int arr[], int length)
{
    int i = 0;
    while(i < length/2)
    {
        int temp = arr[i];
        arr[i] = arr[length - 1 - i];
        arr[length - 1 - i] = temp;
        i++;
    }
    return;
}

int Calculate(int arr[], int length, int num)
{
    int count = 0;
    int i = 0;
    while(i < length)
    {
        if(arr[i++] == num)
            count++;
    }
    return count;
}

int IsPermutation(int arr[], int dArr[], int length, int dLength)
{
    int num = 0;
    if(length != dLength)
        return 0;
    while(num <= 9)
    {
        if(Calculate(arr, length, num) != Calculate(dArr, dLength, num))
            return 0;
        else
            num++;
    }
    return 1;
}

int main()
{
    int arr[MAX_LENGTH] = {0};
    int dArr[MAX_LENGTH] = {0};
    int length = 0;
    int dLength = 0;
    int i = 0;
    char ch;

    scanf("%c", &ch);
    while('0' <= ch && ch <= '9')
    {
        arr[i++] = ch - '0';
        scanf("%c", &ch);
        length++;
    }
    InvertArray(arr, length);
    dLength = DoubleArray(arr, dArr, length);
    if(IsPermutation(arr, dArr, length, dLength) == 1)
        printf("Yes\n");
    else
        printf("No\n");
    PrintArray(dArr, dLength);
    return 0;
}
