#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int* arr;
    int size;
    int sp;
};

int IsFull(struct Stack* S);
int IsEmpty (struct Stack* S);
void Push(struct Stack* S, int item);
int Pop(struct Stack* S);
void AddQ(int item, struct Stack* s1, struct Stack* s2, int* sFlag, int* oFlag);
int DeleteQ(struct Stack* s1, struct Stack* s2, int* flag);

int main()
{
    int n1, n2, adN, sFlag = 1;   //sFlag = 1 表示当前插入到s1 sFlag = 2 表示到s2
    int oFlag = 1; //oFlag = 1表示当前s1 是deleteQ先pop的stack ， oFlag= 2 表示是s2
    char op;
    scanf("%d%d", &n1, &n2);
    /*if(n1 < n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }*/
    struct Stack s1, s2;
    s1.arr = (int*) malloc(sizeof (int) * n1);
    s1.size = n1;
    s1.sp = 0;
    s2.arr = (int*) malloc(sizeof (int) * n2);
    s2.size = n2;
    s2.sp = 0;

    scanf("%c", &op);
    while(op != 'T'){
        if(op == 'A'){
            scanf("%d", &adN);
            AddQ(adN, &s1, &s2, &flag);
        } else if (op == 'D'){
            if(IsEmpty(&s1) == 1 && IsEmpty(&s2) == 1){
                printf("ERROR:Empty\n");
            } else {
                printf("%d\n", DeleteQ(&s1, &s2, &flag));
            }
        }
        scanf("%c", &op);
    }
    return 0;
}

int IsFull(struct Stack* S){
    if(S->sp >= S->size){
        return 1;
    } else {
        return 0;
    }
}

int IsEmpty (struct Stack* S){
    if (S->sp == 0){
        return 1;
    } else {
        return 0;
    }
}

void Push(struct Stack* S, int item){
    S->arr[S->sp++] = item;
}

int Pop(struct Stack* S){
    return S->arr[--S->sp];
}

void AddQ(int item, struct Stack* s1, struct Stack* s2, int* sFlag, int* oFlag){
    if(*sflag == 2){
        struct Stack* temp = s1;
        s1 = s2;
        s2 = temp;
    }
    if(IsEmpty(s1) == 1){
        Push(s1, item);
        if(IsEmpty(s2) == 0){
            if(*flag == 1){
                flag = 2;
            } else {
                flag = 1;
            }
        }
    } else {
        int count = 0;
        while(IsFull(s2) != 1 && IsEmpty(s1) != 1){
            Push(s2, Pop(s1));
            count++;
        }
        if(IsEmpty(s1) == 1){
            push
        }
    }
}

int DeleteQ(struct Stack* s1, struct Stack* s2, int* flag){
    if(*flag == 2){
        struct Stack* temp = s1;
        s1 = s2;
        s2 = temp;
    }

    if(IsEmpty(s1) == 0){
        return Pop(s1);
    }
    return Pop(s2);

}
