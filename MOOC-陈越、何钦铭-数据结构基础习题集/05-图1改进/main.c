#include <stdio.h>
#include <stdlib.h>

struct AdjacentVertices
{
    int* front;
    int sp;
};

void DFS(struct AdjacentVertices arr[], int length, int pos);

int main()
{
    int N, E, i;
    scanf("%d %d", &N, &E);

    struct AdjacentVertices arr[N];
    for(i = 0; i < N; i++)
    {
        int j = 0;
        arr[i].front = (int*)malloc(sizeof(int) * N);
        for(j = 0; j < N; j++)
        {
            *(arr[i].front + j) = 0;
        }
        arr[i].sp = 0;
    }
    for(i = 0; i < E; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        *(arr[v1].front + v2) = 1;
        *(arr[v2].front + v1) = 1;
    }
    return 0;
}

void DFS(struct AdjacentVertices arr[], int length, int pos)
{
    int i = 0, j;
    printf("%d ", pos);

    for(arr[pos].sp = 0; arr[pos].sp < length; arr[pos].sp++)
    {
        if(arr[pos].front[arr[pos].sp] == 1 && arr[arr[pos].sp].sp != length)
        {
            DFS(arr, length, arr[pos].sp);
        }
    }



    for(j = 0; j < length;)
    {
        if(arr[i].front[j] == 0)
            j++;
        else
        {
            printf("%d ", j);

        }
    }
}
