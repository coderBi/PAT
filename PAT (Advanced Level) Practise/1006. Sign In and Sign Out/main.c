#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record{
    char id[16];
    char signIn[11];
    char signOut[11];
};
int main()
{
    int m, i;
    scanf("%d", &m);
    struct Record arr[m];

    for(i = 0; i < m; i++){
        getchar();
        scanf("%s %s %s", arr[i].id, arr[i].signIn, arr[i].signOut);
    }

    int unlock = 0, lock = 0;
    for(i = 1; i < m; i++){
        if(strcmp(arr[i].signIn, arr[unlock].signIn) < 0){
            unlock = i;
        }
        if(strcmp(arr[i].signOut, arr[lock].signOut) > 0){
            lock = i;
        }
    }
    printf("%s %s", arr[unlock].id, arr[lock].id);
    return 0;
}
