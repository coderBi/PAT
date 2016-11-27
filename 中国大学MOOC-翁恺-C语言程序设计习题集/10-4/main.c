#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[100];
    int N, i, length;

    gets(arr);
    scanf("%d", &N);
    length = strlen(arr);

    N %= length;
    for(i = N; i < length; i++)
    {
        printf("%c", arr[i]);
    }
    for(i = 0; i < N; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}
