#include <stdio.h>
#include <stdlib.h>

#define LENGTH 54

struct Cards
{
    char kind;
    int num;
};

void InitCards(struct Cards arr[], int length)
{
    int i = 0;
    int  gap = 13;
    while(i < gap)
    {
        arr[i].kind = 'S';
        arr[i].num = i + 1;
        i++;
    }
    while(i < 2*gap)
    {
        arr[i].kind = 'H';
        arr[i].num = i + 1 - gap;
        i++;
    }
    while(i < 3*gap)
    {
        arr[i].kind = 'C';
        arr[i].num = i + 1 - 2*gap;
        i++;
    }
    while(i < 4*gap)
    {
        arr[i].kind = 'D';
        arr[i].num = i + 1 - 3*gap;
        i++;
    }
    while(i < length)
    {
        arr[i].kind = 'J';
        arr[i].num = i + 1 - 4*gap;
        i++;
    }
    return;
}

void PrintCards(struct Cards arr[], int length)
{
    int i = 0;
    for(i = 0; i < length - 1; i++)
    {
        printf("%c%d ", arr[i].kind, arr[i].num);
    }
    printf("%c%d", arr[length - 1].kind, arr[length - 1].num);
    return;
}

void Shuffling(struct Cards arr[], int length, int sequence[], int times)
{
    int pos, i, j;
    struct Cards fArr[length];
    for(j = 0; j < times; j++)
    {
        for(i = 0; i < length; i++)
        {
            pos = sequence[i];
            fArr[pos - 1] = arr[i];
        }
        for(i = 0; i < length; i++)
        {
            arr[i] = fArr[i];
        }
    }
    return;
}

int main()
{
    struct Cards arr[LENGTH];
    int sequence[LENGTH], times;
    int i = 0;

    scanf("%d", &times);
    while(i < LENGTH)
        scanf("%d", &sequence[i++]);
    InitCards(arr, LENGTH);
    Shuffling(arr, LENGTH, sequence, times);
    PrintCards(arr,LENGTH);
    return 0;
}
