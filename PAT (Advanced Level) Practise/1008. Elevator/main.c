#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int x, preFloor = 0, sum = 0;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &x);
        if(x > preFloor){
            sum += 6* (x - preFloor);
        } else {
            sum += 4* (preFloor - x);
        }
        preFloor = x;
        sum += 5;
    }
    printf("%d", sum);
    return 0;
}
