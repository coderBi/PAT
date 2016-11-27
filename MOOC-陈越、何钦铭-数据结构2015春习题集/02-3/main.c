#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Stack
{
    int arr[MAX_SIZE];
    int sp;
};

int Push(struct Stack* stack, int num)
{
    stack->arr[--stack->sp] = num;
    return stack->sp;
}

int Pop(struct Stack* stack)
{
    return stack->arr[stack->sp++];
}

int Is_Possible_Pop(int M, int N, struct Stack* stack, int arr_Sequence[])
{
    int j = 0;
    int i = 1;
    while(j < N)
    {
        if(stack->sp == M)
        {
            Push(stack, i++);
            continue;
        }
        if(arr_Sequence[j] == stack->arr[stack->sp])
        {
            Pop(stack);
            j++;
        }
        else if(stack->sp == 0 || i > N)
            return 0;
        else
            Push(stack, i++);
    }
    return 1;
}

int main()
{
    struct Stack stack;
    int arr[MAX_SIZE];
    int res[MAX_SIZE];
    int M, N, K;
    int i = 0;

    scanf("%d %d %d", &M, &N, &K);
    while(i < K)
    {
        int j = 0;
        stack.sp = M;
        while(j < N)
            scanf("%d", &arr[j++]);
        res[i++] = Is_Possible_Pop(M, N, &stack, arr);
    }
    for(i = 0; i < K; i++)
    {
        if(res[i] == 0)
            printf("NO");
        else
            printf("YES");
        if(i != K - 1)
            printf("\n");
    }
    return 0;
}
