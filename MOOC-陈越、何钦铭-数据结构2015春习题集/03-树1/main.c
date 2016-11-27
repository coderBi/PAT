#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Imitate_Queue
{
    struct Vertex* arr[MAX_SIZE];
    int front;
    int rear;
};

struct Vertex
{
    int node;
    int left;
    int right;
    int is_Root;
};

void Add(struct Imitate_Queue* qu, struct Vertex* node)
{
    qu->arr[qu->rear++] = node;
}

struct Vertex* Delete(struct Imitate_Queue* qu)
{
    return qu->arr[qu->front++];
}

int Char2Int(char ch)  //这里的节点中不存在负数的情况
{
    if(ch >= '0' && ch <= '9')
        return ch - '0';
    return -1;
}

void List_leaves(int root, struct Vertex arr[])
{
    int res[MAX_SIZE];
    int res_Length = 0;
    struct Imitate_Queue qu;
    int i = 0;
    qu.front = 0;
    qu.rear = 0;
    Add(&qu, &arr[root]);
    while(qu.front < qu.rear)
    {
        struct Vertex* temp = Delete(&qu);
        if(temp->left == -1 && temp->right == -1)
        {
            res[res_Length++] = temp->node;
            continue;
        }
        if(temp->left != -1)
        {
            Add(&qu, &arr[temp->left]);
        }
        if(temp->right != -1)
        {
            Add(&qu, &arr[temp->right]);
        }
    }
    for(i = 0; i < res_Length - 1; i++)
    {
        printf("%d ", res[i]);
    }
    printf("%d", res[res_Length - 1]);
    return;
}

int main()
{
    struct Vertex arr[MAX_SIZE];
    int root;
    int n, i = 0;
    char left, right;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        arr[i].is_Root = 1;
    for(i = 0; i < n; i++)
    {
        arr[i].node = i;
        char ch;
        scanf("%c", &ch);
        while(ch == ' ' || ch == '\n')
            scanf("%c", &ch);
        left = ch;
        scanf("%c", &ch);
        while(ch == ' ' || ch == '\n')
            scanf("%c", &ch);
        right = ch;
        arr[i].left = Char2Int(left);
        arr[i].right = Char2Int(right);
        if(arr[i].left != -1)
            arr[arr[i].left].is_Root = 0;
        if(arr[i].right != -1)
            arr[arr[i].right].is_Root = 0;
    }
    for(i = 0; i < n; i++)
    {
        if(arr[i].is_Root == 1)
        {
            root = arr[i].node;
            break;
        }
    }
    List_leaves(root, arr);
    return 0;
}
