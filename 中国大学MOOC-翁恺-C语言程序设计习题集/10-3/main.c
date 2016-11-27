#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[80];
    int length, i;
    gets(arr);
    length = strlen(arr);
    for(i = length -1; i >=0; i--)
    {
        printf("%c", arr[i]);
    }
    return 0;
}
