#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    scanf("%d", &n);

    if(n == 0){
        printf("0");
        return 0;
    }
    x = n/100;
    n %= 100;
    while(x){
        printf("B");
        x--;
    }
    x = n/10;
    n %= 10;
    while(x){
        printf("S");
        x--;
    }

    for(x = 1; x <= n; x++){
        printf("%d", x);
    }

    return 0;
}
