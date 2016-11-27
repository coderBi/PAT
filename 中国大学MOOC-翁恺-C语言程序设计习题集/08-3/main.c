#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10], i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 1; i < 10 && arr[i] == 0; i++){}
    if(i == 10)
    {
        printf("%d", 0);
        exit(0);
    }
    printf("%d", i);
    arr[i]--;

    for(i = 0; i < 10; i++)
    {
        while(arr[i] != 0)
        {
            printf("%d", i);
            arr[i]--;
        }
    }
    return 0;
}
