#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 1, n, i;
    char ch;
    scanf("%d %c", &n, &ch);

    for(i = 3; sum + 2*i <= n; i += 2){
        sum += 2*i;
    }

    int space = 0, j, k;
    for(i -= 2, k = i; k > 1; k -= 2){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        for(j = 0; j < k; j++){
            printf("%c", ch);
        }
        printf("\n");
        space++;
    }
    for(k = 1; k <= i; k += 2){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        for(j = 0; j < k; j++){
            printf("%c", ch);
        }
        printf("\n");
        space--;
    }
    printf("%d", n - sum);
    return 0;
}
