#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n], i;

    m %= n;
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(i = n -m; i < n; i++){
        printf("%d ", arr[i]);
    }
    for(i = 0; i < n - m - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - m -1]);
    return 0;
}
