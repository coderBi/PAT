#include <stdio.h>
#include <stdlib.h>

struct Score{
    int problem;
    int gain;
};

struct User{
    int id;
    int total;
    int pass;
    struct Score* head;
};

int main()
{
    int n, k, m, i;
    scanf("%d %d %d", &n, &k, &m);
    struct User arr[n];
    int fullScore[k];

    for(i = 0; i < k; k++){
        scanf("%d", &fullScore[i]);
    }
    for(i = 0; i < n; i++){
        arr[i].id = arr[i].total = 0;
        arr[i].pass = 0;
        arr[i].head = NULL;
    }
    return 0;
}
