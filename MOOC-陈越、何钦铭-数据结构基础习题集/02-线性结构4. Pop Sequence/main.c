#include <stdio.h>
#include <stdlib.h>

struct stack{
    int* arr;
    int size;
    int sp;
};

int IsFull(struct stack* s);
int IsEmpty(struct stack* s);
void Push(struct stack* s, int x);
int Pop(struct stack* s);

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int arr[m], res[k], i;
    struct stack s;
    s.size = m;
    s.arr = arr;

    for(i = 0; i < k; i++){
        int j, num = 1, test[n];
        s.sp = 0;

        for(j = 0; j < n; j++){
            scanf("%d", &test[j]);

        }
        for(j = 0; j < n; j++){

            while(IsEmpty(&s) == 1 || (s.arr[s.sp -1] != test[j] && IsFull(&s) == 0)) {
                Push(&s, num++);
            }
            if(s.arr[s.sp -1] != test[j]){
                break;
            } else {
                Pop(&s);
            }
        }
        if(IsEmpty(&s) == 1){
            res[i] = 1;
        } else {
            res[i] = 0;
        }
    }

    for(i = 0; i < k; i++){
        if(res[i] == 0){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}

int IsFull(struct stack* s){
    if(s->sp == s->size){
        return 1;
    } else {
        return 0;
    }
}

int IsEmpty(struct stack* s){
    if(s->sp == 0){
        return 1;
    } else {
        return 0;
    }
}

void Push(struct stack* s, int x){
    s->arr[s->sp++] = x;
}

int Pop(struct stack* s){
    return s->arr[--s->sp];
}
