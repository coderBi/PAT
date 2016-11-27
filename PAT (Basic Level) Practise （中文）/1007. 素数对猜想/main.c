#include <stdio.h>
#include <stdlib.h>

int IsPrime(int n);

int main()
{
    int i, n, count = 0;
    scanf("%d", &n);

    for(i = 2; i <= n -2; i++){
        if(IsPrime(i) && IsPrime(i + 2)) {
            count++;
            i++; //可以证明如果i 跟i + 2 都是素数 那么中间的 i+1必然是偶数，所以这里 把i++ 减少一个处理量
        }
    }
    printf("%d", count);
    return 0;
}

int IsPrime(int n){
    if(n < 2){
        return 0;
    }
    int i;
    for(i = 2; i*i <= n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
