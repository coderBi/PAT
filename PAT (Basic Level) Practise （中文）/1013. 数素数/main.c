#include <stdio.h>
#include <stdlib.h>

int IsPrime(int x);

int main()
{
    int i, m, n, count = 0;
    scanf("%d%d", &m, &n);

    for(i = 2;; i++){
        if(IsPrime(i)){
            count++;
        } else {
            continue;
        }
        if(count >= m && count < n){
            if((count - m +1)%10 != 0){
                printf("%d ", i);
            } else {
                printf("%d\n", i);
            }
        } else if (count == n){
            printf("%d", i);
        } else if (count > n){
            break;
        }
    }
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
