#include <stdio.h>
#include <stdlib.h>

struct BTree{
    int num;
    struct BTree* left, *right; //这里注意写法， * 跟后面的结合更近，所以是 *right
};

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    int res[n];

    for(i = 0; i < n; i++){
        struct BTree arr[m];
        int j = 0;
        for(j = 0; j < m; j++){
            scanf("%d", &arr[j].num);
            arr[j].left = arr[j].right = NULL;
            if(j > 0){
                if(arr[j -1].num < arr[j].num){
                    arr[j -1].right = &arr[j];
                } else {
                    arr[j -1].left = &arr[j];
                }
            }
        }
        for(j = 0; j + 2 < m; j++){
            if(arr[j].left != NULL){
                int k;
                for(k = j +2; k < m; k++){
                    if(arr[k].num >= arr[j].num){
                        break;
                    }
                }
                if(k < m){
                    break;
                }
            } else {
                int k;
                for(k = j +2; k < m; k++){
                    if(arr[k].num <= arr[j].num){
                        break;
                    }
                }
                if(k < m){
                    break;
                }
            }
        }
        if(j +2 < m){
            res[i] = 0;
        } else {
            res[i] = 1;
        }
    }

    for(i = 0; i < n; i++){
        if(res[i] == 0){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
