#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2010

struct DataType
{
    int factor;
    int index;
};

struct ResType
{
    long factor;
    int index;
};

void PrintArray(struct ResType arr[], int length)
{
    int i = 0;
    while(i < length - 1)
    {
        printf("%ld %d ", arr[i].factor, arr[i].index);
        i++;
    }
    printf("%ld %d", arr[length - 1].factor, arr[length - 1].index);
    return;
}

int main()
{
    struct DataType arr[MAX_SIZE];
    struct ResType res[MAX_SIZE];
    int length = 0, i = 0, j = 0;
    int res_Length = 0;
    char ch = ' ';
    while(ch != '\n' && i < MAX_SIZE)
    {
        scanf("%d %d%c", &arr[i].factor, &arr[i].index, &ch);
        length++;
        i++;
    }
    for(i = 0; i < length; i++)
    {
        if(arr[i].index != 0)
        {
            long factor = arr[i].factor * arr[i].index;
            res[j].factor = factor;
            res[j].index = arr[i].index - 1;
            j++;
            res_Length++;
        }
    }
    PrintArray(res, res_Length);
    return 0;
}
