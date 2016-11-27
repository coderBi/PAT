#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct Queue{
    int front;
    int rear;
    int* arr;
    int size;
};

void Dfs(int visit[], int vNum, int edge[][vNum], int pos);
void Bfs(int visit[], int vNum, int edge[][vNum], int pos);
int IsEmpty(struct Queue* qu);
void Add(struct Queue* qu, int num);
int Delete(struct Queue* qu);


int main()
{
    int n, e, i;
    scanf("%d %d", &n, &e);
    int visit[n], edge[n][n];

    int v1, v2;
    memset(edge, 0, n * n * sizeof(int));
    for(i = 0; i < e; i++){
        scanf("%d %d", &v1, &v2);
        edge[v1][v2] = 1;
        edge[v2][v1] = 1;
    }

    memset(visit, 0, n * sizeof(int));
    for(i = 0; i < n; i++){
        if(visit[i] == 0){
            printf("{ ");
            Dfs(visit, n, edge, i);
            printf(" }\n");
        }
    }

    memset(visit, 0, n * sizeof(int));
    for(i = 0; i < n; i++){
        if(visit[i] == 0){
            printf("{ ");
            Bfs(visit, n, edge, i);
            printf(" }\n");
        }
    }
    return 0;
}

void Dfs(int visit[], int vNum, int edge[][vNum], int pos){
    int i;
    visit[pos] = 1;
    printf("%d", pos);

    for(i = 0; i < vNum; i++){
        if(visit[i] == 0 && edge[pos][i] == 1){
            printf(" ");
            Dfs(visit, vNum, edge, i);
            //break;
        }
    }
}

void Bfs(int visit[], int vNum, int edge[][vNum], int pos){
    struct Queue qu;
    int arr[vNum];
    qu.arr = arr;
    qu.size = vNum;
    qu.front = 0;
    qu.rear = -1;

    int scr, i;
    visit[pos] = 2;
    Add(&qu, pos);
    while(IsEmpty(&qu) == 0){
        scr = Delete(&qu);
        if(scr != pos){
            printf(" ");
        }
        printf("%d", scr);
        for(i = 0; i < vNum; i++){
            if(visit[i] == 0 && edge[scr][i] == 1){
                visit[i] = 1;
                Add(&qu, i);
            }
        }
    }
}

int IsEmpty(struct Queue* qu){
    if(qu->rear < qu->front){
        return 1;
    } else {
        return 0;
    }
}

void Add(struct Queue* qu, int num){
    qu->arr[++qu->rear] = num;
}

int Delete(struct Queue* qu){
    return qu->arr[qu->front++];
}
