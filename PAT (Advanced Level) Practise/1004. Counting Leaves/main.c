#include <stdio.h>
#include <stdlib.h>

struct Person{
    int id;
    struct Person* child[100];
    int childLen;
    int deep;
};

int FindByid(struct Person arr[], int length, int id);

int main()
{
    int n, m, i, length = 0;
    scanf("%d %d", &n, &m);
    struct Person arr[n];

    for(i = 0; i < n; i++){
        arr[i].id = 0;
        arr[i].childLen = 0;
        arr[i].deep = 0;
    }

    int father, childLen;
    for(i = 0; i < m; i++){
        scanf("%d %d", &father, &childLen);
        if(FindByid(arr, n, father) == -1){
            arr[length].id = father;
            arr[length].childLen = childLen;
            length++;
        }
        int j, childArr[childLen];
        for(j = 0; j < childLen; j++){
            scanf("%d", &childArr[j]);
            if(FindByid(arr, n, childArr[j]) == -1){
                arr[length++].id = childArr[j];

            }
        }

    }
    return 0;
}

int FindByid(struct Person arr[], int length, int id){
    int i;

    for(i = 0; i < length; i++){
        if(arr[i].id == id){
            return i;
        }
    }
    return -1;
}
