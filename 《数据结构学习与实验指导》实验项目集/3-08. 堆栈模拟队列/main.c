/*
    1，最后一个case没有通过，分析可能是两个stack空间使用不够充分，例如 对于n1 = 100 n2= 10
    当第一个填充了11个元素时， 这时第二个是可能装满10个的
    2， 问题将再下一个版本重写时解决
*/
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
void AddQ(int item, struct Stack* s1, struct Stack* s2, int* flag);
int DeleteQ(struct Stack* s1, struct Stack* s2, int* flag);

int main()
{
    int n1, n2, adN, flag = 1; //flag = 1表示当前s1 是deleteQ先pop的stack ， flag= 2 表示是s2
    char op;
    scanf("%d%d", &n1, &n2);
    if(n1 < n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
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

void AddQ(int item, struct Stack* s1, struct Stack* s2, int* flag){
    if(*flag == 2){
        struct Stack* temp = s1;
        s1 = s2;
        s2 = temp;
    }
    if(IsEmpty(s1) == 0){
        if(IsEmpty(s2) == 0){
            if(IsFull(s2) == 0){
                Push(s2, Pop(s1));
                if(IsEmpty(s1) == 1){
                    if(*flag == 1){
                        *flag = 2;
                    } else {
                        *flag = 1;
                    }
                    Push(s1, item);
                } else {
                    Push(s1, Pop(s2));
                    printf("ERROR:Full\n");
                }
            }
            return;
        }
        while(IsFull(s2) == 0 && IsEmpty(s1) == 0){
            Push(s2, Pop(s1));
        }
        if(IsEmpty(s1) == 0){
            while(IsEmpty(s2) == 0){
                Push(s1, Pop(s2));
            }
            Push(s2, item);
        } else {
            Push(s1, item);
            while(IsEmpty(s2) == 0){
                Push(s1, Pop(s2));
            }
        }
    } else {
        Push(s1, item);
        if(IsEmpty(s2) == 0){
            Push(s1, Pop(s2));
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
