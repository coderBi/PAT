#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, arr[40];
    int i = 0;
    scanf("%c", &c);
    while(c != '#')
    {
        if(c >= 'A' && c <= 'Z')
        {
            c += ('a' - 'A');
        }
        else if(c >= 'a' && c <= 'z')
        {
            c += ('A' - 'a');
        }
        arr[i++] = c;
        scanf("%c", &c);
    }
    arr[i] = '\0';
    printf("%s", arr);
    return 0;
}
