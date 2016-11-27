#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

int main()
{
    int in, res[MAX_LENGTH], length = 0, i;
    char* arr[MAX_LENGTH] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    scanf("%d", &in);
    if(in < 0)
    {
        printf("fu ");
        in *= -1;
    }
    while(in/10 != 0)
    {
        res[length++] = in%10;
        in /= 10;
    }
    res[length++] = in;

    for(i = length - 1; i > 0; i--)
    {
        printf("%s ", arr[res[i]]);
    }
    printf("%s", arr[res[0]]);
    return 0;
}
