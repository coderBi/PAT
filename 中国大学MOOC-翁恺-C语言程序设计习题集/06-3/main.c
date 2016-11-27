#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100  //我这里假设一个句子的最长长度不超过100

void PrintArr(int arr[], int length);

int main()
{
    char c;
    int length = 0, arr[MAX_LENGTH], count = 0;
    scanf("%c", &c);
    while(1)
    {
        if(c == '.')
        {
            if( count != 0)
            {
                arr[length++] = count;
                count = 0;
            }
            break;
        }
        else if(c == ' ')
        {
            if( count != 0)
            {
                arr[length++] = count;
                count = 0;
            }
        }
        else
        {
            count++;
        }
        scanf("%c", &c);
    }
    PrintArr(arr, length);
    return 0;
}

void PrintArr(int arr[], int length)
{
    int i;
    if(length <= 0)
        return;
    for(i = 0; i < length -1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[length -1]);
}
