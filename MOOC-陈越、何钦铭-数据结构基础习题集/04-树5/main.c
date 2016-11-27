#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10002

int GetConnectedGraphs(int arr[], int length);
void AddInput(int arr[], int op1, int op2, int length);

int main()
{
    int length = 0, op1, op2, i, count = 0;
    char oper = ' ';

    scanf("%d", &length);
    int arr[++length];  // 0Ω«±Í±£¡Ù
    for(i = 0; i < length; i++)
    {
        arr[i] = i;
    }
    scanf("%c", &oper);
    while(oper != 'S')
    {
        scanf("%d %d", &op1, &op2);
        if(oper == 'C')
        {
            int root1 = arr[op1];
            int root2 = arr[op2];
            if(root1 == root2)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        else if(oper == 'I')
        {
            AddInput(arr, op1, op2, length);
        }
        scanf("%c", &oper);
    }
    count = GetConnectedGraphs(arr, length);
    if(count > 1)
    {
        printf("There are %d components.\n", count);
    }
    else
    {
        printf("The network is connected.\n");
    }
    return 0;
}

int GetConnectedGraphs(int arr[], int length)
{
    int i = 1, count = 0;
    int res[length];

    for(i = 0; i < length; i++)
    {
        res[i] = 0;
    }
    for(i = 1; i < length; i++)
    {
        res[arr[i]] = 1;
    }
    for(i = 0; i < length; i++)
    {
        if(res[i] != 0)
        {
            count++;
        }
    }
    return count;
}

void AddInput(int arr[], int op1, int op2, int length)
{
    int root1 = arr[op1];
    int root2 = arr[op2];

    if(root1 == root2)
    {
        return;
    }
    else
    {
        int i = 0;
        for(; i < length; i++)
        {
            if(arr[i] == root2)
                arr[i] = root1;
        }
    }
    return;
}
