#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

int main()
{
    char ch;
    int b, arr[MAX_LENGTH], i, length = 0;
    int res[MAX_LENGTH], resLen = 0;

    scanf("%c", &ch);
    while(ch >= '0' && ch <= '9'){
        arr[length++] = ch - '0';
        scanf("%c", &ch);
    }

    scanf("%d", &b);

    int rem = 0, dividend;
    for(i = 0; i < length; i++){
        dividend = rem * 10 + arr[i];
        if(dividend >= b){
            res[resLen++] = dividend/b;
            rem = dividend%b;
        } else {
            rem = dividend;
            if(resLen != 0){
                res[resLen++] = 0;
            }
        }
    }

    //只有一位数并且 < b
    if(resLen == 0){
        printf("0 %d", arr[0]);
        return 0;
    }

    for(i = 0; i < resLen; i++){
        printf("%d", res[i]);
    }
    printf(" %d", rem);
    return 0;
}
