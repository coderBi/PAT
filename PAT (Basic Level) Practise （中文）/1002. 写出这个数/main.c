#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int sum = 0;
    char* res[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int stor[12], length = 0;
    scanf("%c", &ch);

    while(ch >= '0' && ch <= '9'){
        sum += ch - '0';
        scanf("%c", &ch);
    }

    while(sum/10 != 0){
        stor[length++] = sum%10;
        sum /= 10;
    }
    stor[length++] = sum;

    for(; length > 1; length--){
        printf("%s ", res[stor[length -1]]);
    }
    printf("%s", res[stor[length -1]]);
    return 0;
}
