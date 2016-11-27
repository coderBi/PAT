#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void Dfs(int visit[], int vNum, int edge[], int vert);

int main()
{
    int n, m, k, i, j;
    scanf("%d %d %d", &n, &m, &k);
    int visit[n + 1];
    int edge[n +1][n + 1];

    int v1, v2;
    memset(edge, 0, (n +1) * (n +1) * sizeof(int));
    for(i = 0; i < m; i++){
        scanf("%d %d", &v1, &v2);
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }

    int check, res[k], count;
    for(i = 0; i < k; i++){
        scanf("%d", &check);
        memset(visit, 0, (n +1) * sizeof(int));
        visit[check] = 1;
        count = 0;
        for(j = 1; j <= n; j++){
            if(visit[j] == 0){
                count++;
                Dfs(visit, n, edge[0], j);
            }
        }
        res[i] = count -1;
    }
    for(i = 0; i < k; i++){
        printf("%d\n", res[i]);
    }
    return 0;
}

void Dfs(int visit[], int vNum, int edge[], int vert){
    visit[vert] = 1;
    int i;

    for(i = 1; i <= vNum; i++){
        if(visit[i] == 0 && edge[vert * (vNum +1) + i] == 1){
            Dfs(visit, vNum, edge, i);
        }
    }
}
