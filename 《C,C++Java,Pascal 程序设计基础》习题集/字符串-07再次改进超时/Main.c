#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[500010];
    int length, i, j, front;

    gets(arr);
    length = strlen(arr);
    for(front = 0; front < length && arr[front] == ' '; front++) {}
    if(front >= length)
    {
        exit(0);
    }
    for(i = length -1, j = length -1; i >= front; i--)
    {
        if(arr[i] == ' ')
        {
            int k;
            for(k = i + 1; k <= j; k++)
            {
                printf("%c", arr[k]);
            }
            if(i != j)  //中间可能有多个分割的空格
            {
                 printf(" ");
            }
            j = i -1;
            continue;
        }
    }
    for(i = front; i <=j; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}
