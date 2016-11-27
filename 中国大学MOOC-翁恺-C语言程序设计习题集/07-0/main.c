#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

void PrintRes(int res);

int main()
{
    int sum = 0;
    char c;
    scanf("%c", &c);
    while(c != '\n')
    {
        if(c >= '0' && c <= '9')
        {
            sum += c - '0';
        }
        else
            break;
        scanf("%c", &c);
    }
    PrintRes(sum);
    return 0;
}

void PrintRes(int res)
{
    int arr[MAX_LENGTH], length = 0, i;
    char* stor[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    while(res/10 != 0)
    {
        arr[length++] = res%10;
        res /= 10;
    }
    arr[length++] = res;

    for(i = length -1; i > 0; i--)
    {
        printf("%s ", stor[arr[i]]);
    }
    printf("%s", stor[arr[0]]);
    return;
}
