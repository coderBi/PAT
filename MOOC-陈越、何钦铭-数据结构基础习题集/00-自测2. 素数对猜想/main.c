#include <stdio.h>
#include <stdlib.h>

int IsPrime(int x);

int main()
{
    int i, n, count = 0;
    scanf("%d", &n);

    for(i = 2; i <= n -2; i++){
        if(IsPrime(i) == 1 && IsPrime(i + 2) == 1){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

int IsPrime(int x){
    if(x < 2){
        return 0;
    }

    int i;
    for(i = 2; i*i <= x; i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}
