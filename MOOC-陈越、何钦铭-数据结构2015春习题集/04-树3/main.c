#include <stdio.h>
#include <stdlib.h>

struct AvlTree
{
    int element;
    int height;
    struct AvlTree* left;
    struct AvlTree* right;
};

int Height(struct AvlTree* node)
{
    if(node == NULL)
        return -1;
    return node->height;
}

int Max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

struct AvlTree* SingleRotateWithLeft(struct AvlTree* head)
{
    struct AvlTree* newHead = NULL;
    newHead = head->left;
    head->left = newHead->right;
    newHead->right = head;
    head->height = Max(Height(head->left), Height(head->right)) + 1;
    newHead->height = Max(Height(head), Height(newHead->left)) + 1;
    return newHead;
}

struct AvlTree* SingleRotateWithRight(struct AvlTree* head)
{
    struct AvlTree* newHead = NULL;
    newHead = head->right;
    head->right = newHead->left;
    newHead->left = head;
    head->height = Max(Height(head->left), Height(head->right)) + 1;
    newHead->height = Max(Height(head), Height(newHead->right)) + 1;
    return newHead;
}

// 左右旋，即插在了left的right上
struct AvlTree* DoubleRotateWithLeft(struct AvlTree* head)
{
    head->left = SingleRotateWithRight(head->left);
    return SingleRotateWithLeft(head);
}

// 左右旋，即插在了right的left上
struct AvlTree* DoubleRotateWithRight(struct AvlTree* head)
{
    head->right = SingleRotateWithLeft(head->right);
    return SingleRotateWithRight(head);
}

struct AvlTree* Insert(struct AvlTree* head, struct AvlTree* node)
{
    if(head == NULL)
        return node;
    if(node->element < head->element)
    {
        head->left = Insert(head->left, node);
        if(Height(head->left) - Height(head->right) > 1)
        {
            if(head->left->element > node->element)
                head = SingleRotateWithLeft(head);
            else
                head = DoubleRotateWithLeft(head);
        }
    }
    else if(node->element > head->element)
    {
        head->right = Insert(head->right, node);
        if(Height(head->right) - Height(head->left) > 1)
        {
            if(head->right->element < node->element)
                head = SingleRotateWithRight(head);
            else
                head = DoubleRotateWithRight(head);
        }
    }
    head->height = Max(Height(head->left), Height(head->right)) + 1;
    return head;
}

int main()
{
    int N, i, num;
    struct AvlTree* head = NULL;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &num);
        struct AvlTree* node = (struct AvlTree*)malloc(sizeof(struct AvlTree));
        while(node == NULL)
            node = (struct AvlTree*)malloc(sizeof(struct AvlTree));
        node->element = num;
        node->left = node->right = NULL;
        node->height = 0;
        head = Insert(head, node);
    }
    printf("%d", head->element);
    return 0;
}
