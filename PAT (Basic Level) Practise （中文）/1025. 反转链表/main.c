#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

struct Link{
    int address;
    int data;
    int next;
};

void Swap(struct Link* l1, struct Link* l2);

int main()
{
    struct Link arr[MAX_SIZE];
    int i, length = 0, n, k, address;

    scanf("%d%d%d", &address, &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d%d%d", &arr[i].address, &arr[i].data, &arr[i].next);
    }

    for(i = 0; i < n; i++){
        int j = 0;
        for(j = i; j < n; j++){
            if(arr[j].address == address){
                Swap(&arr[i], &arr[j]);
                address = arr[i].next;
                break;
            }
        }
        if(j == n){
            break;
        }
    }
    length = i;
    for(i = 0; i + k <= length; i += k){
        int j;
        for(j = i; j <= i + (k -1)/2; j++){
            Swap(&arr[j], &arr[2*i + k -1 - j]);
        }
    }
    //µ÷Õûnext
    for(i = 0; i < length -1; i++){
        arr[i].next = arr[i+1].address;
    }
    arr[length -1].next = -1;
    for(i = 0; i < length; i++){
        if(arr[i].next == -1){
            printf("%.5d %d -1\n", arr[i].address, arr[i].data);
            break;
        }
        printf("%.5d %d %.5d\n", arr[i].address, arr[i].data, arr[i].next);
    }
    return 0;
}

void Swap(struct Link* l1, struct Link* l2){
    struct Link temp = *l1;
    *l1 = *l2;
    *l2 = temp;
    return;
}
