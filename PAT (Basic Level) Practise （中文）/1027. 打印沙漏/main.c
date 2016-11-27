/*
    这里一开始有格式错误，原因是一行行末的空格不需要打印。
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, sum = 1, n;
    char ch;
    scanf("%d %c", &n, &ch);

    for(sum = 1, i = 3; sum + 2*i <= n; i += 2){
        sum += 2*i;
    }

    i -= 2;
    int space = 0;
    for(j = i; j > 1; j -= 2, space++){
        for(k = 0; k < space; k++){
            printf(" ");
        }
        for(k = 0; k < j; k++){
            printf("%c", ch);
        }
        /*for(k = 0; k < space; k++){
            printf(" ");
        }*/
        printf("\n");
    }
    for(j = 1; j <= i; j += 2, space--){
        for(k = 0; k < space; k++){
            printf(" ");
        }
        for(k = 0; k < j; k++){
            printf("%c", ch);
        }
        /*for(k = 0; k < space; k++){
            printf(" ");
        }*/
        printf("\n");
    }
    printf("%d", n - sum);
    return 0;
}
