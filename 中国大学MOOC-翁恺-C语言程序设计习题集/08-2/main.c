#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M, N, i, j, count = 0;

    scanf("%d %d", &M, &N);
    int arr[M][N];
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(i = 1; i < M -1; i++)
    {
        for(j = 1; j < N -1; j++)
        {
            if(arr[i][j] > arr[i-1][j] && arr[i][j] > arr[i+1][j] && arr[i][j] > arr[i][j-1] && arr[i][j] > arr[i][j+1])
            {
                printf("%d %d %d\n", arr[i][j], i + 1, j + 1);
                count++;
            }
        }
    }
    if(count == 0)
    {
        printf("None %d %d", M, N);
    }
    return 0;
}
