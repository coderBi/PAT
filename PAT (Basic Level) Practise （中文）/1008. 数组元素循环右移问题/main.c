#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    int arr[n];

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    m %= n;
    for(i = n -m; i <= n -1; i++){
        printf("%d ", arr[i]);
    }
    for(i = 0; i < n -m - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - m -1]);
    return 0;
}
