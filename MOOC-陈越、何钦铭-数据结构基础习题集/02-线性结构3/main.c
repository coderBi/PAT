#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_SIZE 30

struct Stack
{
    char* arr[MAX_SIZE];
    int sp;
};

int Push(struct Stack* stack, char* ch)
{
    stack->arr[--stack->sp] = ch;
    return stack->sp;
}

char* Pop(struct Stack* stack)
{
    if(stack->sp >= MAX_SIZE)
        return NULL;
    else
        return stack->arr[stack->sp++];
}

float Operate(char ch, float f1, float f2)
{
    if(ch == '+')
        return f1 + f2;
    else if (ch == '-')
        return f1 - f2;
    else if (ch == '*')
        return f1 * f2;
    else if (ch == '/' && f2 != 0)
    {
        return f1 / f2;
    }
    else
        printf("ERROR");
    exit(0);
}

int main()
{
    char str[MAX_SIZE];
    char* ptr;
    struct Stack stack;
    struct Stack temp_Stack;
    int i = 0;

    stack.sp = MAX_SIZE;
    temp_Stack.sp = MAX_SIZE;
    gets(str);
    while(i < strlen(str))
    {
        if(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '.' && (str[i] > '9' || str[i] < '0') && str[i] != ' ')
        {
            printf("ERROR");
            return 0;
        }
        i++;
    }
    ptr = strtok(str, " ");
    while(ptr != NULL)
    {
        Push(&stack, ptr);
        ptr = strtok(NULL, " ");
    }
    ptr = Pop(&stack);
    while(ptr != NULL)
    {
        if(strlen(ptr) == 1 && (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/'))
        {
            char* f1 = Pop(&temp_Stack);
            char* f2 = Pop(&temp_Stack);
            char* arr = (char*)malloc(sizeof(char) * MAX_SIZE);
            if(f1 == NULL || f2 == NULL)
            {
                printf("ERROR");
                exit(0);
            }
            sprintf(arr, "%f", Operate(*ptr, atof(f1), atof(f2)));
            Push(&temp_Stack, arr);
        }
        else
        {
            Push(&temp_Stack, ptr);
        }
        ptr = Pop(&stack);
    }
    if(temp_Stack.sp != MAX_SIZE - 1)
    {
        printf("ERROR");
        exit(0);
    }
    printf("%.1f", atof(Pop(&temp_Stack)));
    return 0;
}
