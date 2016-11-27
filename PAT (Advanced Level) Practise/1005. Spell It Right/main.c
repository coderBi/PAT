#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 105

int main()
{
    char arr[MAX_SIZE];
    gets(arr);
    int length = strlen(arr), i, sum = 0;
    char* str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",  "nine"};
    int res[10 * MAX_SIZE], resLen = 0;

    for(i = 0; i < length; i++){
        sum += arr[i] - '0';
    }

    while(sum/10 != 0){
        res[resLen++] = sum%10;
        sum /= 10;
    }
    res[resLen++] = sum;

    for(i = resLen -1; i > 0; i--){
        printf("%s ", str[res[i]]);
    }
    printf("%s", str[res[0]]);
    return 0;
}
