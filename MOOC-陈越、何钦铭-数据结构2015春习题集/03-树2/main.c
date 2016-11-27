#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

struct Imitate_Stack   //这一次模拟的是栈底较小，初始时sp = -1
{
    int arr[MAX_SIZE];
    int sp;
};

struct PostArrStore
{
    int* postorder;
    int sp;
};

struct Imitate_Tree
{
    int node;
    struct Imitate_Tree* left;
    struct Imitate_Tree* right;
};

void Push(struct Imitate_Stack* stack, int num)
{
    stack->arr[++stack->sp] = num;
    return;
}

int Pop(struct Imitate_Stack* stack)
{
    return stack->arr[stack->sp--];
}

void Push_Res(struct PostArrStore* stack, int num)
{
    stack->postorder[stack->sp++] = num;
    return;
}

int Pop_Res(struct PostArrStore* stack)
{
    return stack->postorder[--stack->sp];
}

void PrintArray(int arr[], int length)
{
    int i = 0;
    if(length <= 0)
        return;
    while(i < length - 1)
        printf("%d ", arr[i++]);
    printf("%d", arr[length - 1]);
    return;
}


struct Imitate_Tree* BuildTree(int preorder_List[], int inorder_List[], int left, int right, int* front)
{
    struct Imitate_Tree* head = NULL;
    int j;

    for(j = left; j <= right; j++)
    {
        if(preorder_List[*front] == inorder_List[j])
        {
            while(head == NULL)
                head = (struct Imitate_Tree*)malloc(sizeof(struct Imitate_Tree));
            head->node = preorder_List[*front];
            (*front)++;
            head->left = BuildTree(preorder_List, inorder_List, left, j - 1, front);
            head->right = BuildTree(preorder_List, inorder_List, j + 1, right, front);
            break;
        }
    }
    return head;
}

void Get_Postorder_List(struct Imitate_Tree* head, struct PostArrStore* storeRes)
{
    struct Imitate_Tree* vertex = head;

    if(vertex == NULL)
        return;
    Get_Postorder_List(vertex->left, storeRes);
    Get_Postorder_List(vertex->right, storeRes);
    Push_Res(storeRes, vertex->node);
    return;
}

int main()
{
    int N, i = 0, j = 0, k = 0;
    struct Imitate_Stack stack;
    int preorder_List[MAX_SIZE];
    int inorder_List[MAX_SIZE];
    int postorder_List[MAX_SIZE];
    char oper[MAX_SIZE];
    int oper_Num;
    struct PostArrStore storeRes;
    storeRes.postorder = postorder_List;
    storeRes.sp = 0;
    int front = 0;

    scanf("%d", &N);
    stack.sp = -1;
    for(i = 1; i <= 2*N; i++)
    {
        //fflush(stdin);
        scanf("%s", oper);
        if(strcmp(oper, "Push") == 0)
        {
            scanf("%d", &oper_Num);
            Push(&stack, oper_Num);
            preorder_List[k++] =  oper_Num;  //以前一直在这里出错，因为误解了题意是先序一定是1 2 3 ... n
        }
        else if(strcmp(oper, "Pop") == 0)
            inorder_List[j++] = Pop(&stack);
    }
    //PrintArray(inorder_List, N);
    Get_Postorder_List(BuildTree(preorder_List, inorder_List, 0, N - 1 , &front), &storeRes);
    PrintArray(postorder_List, N);
    return 0;
}
