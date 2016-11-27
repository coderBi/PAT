/***********************************************
1，之所以很多人最后一个用例通不过，因为测试用例用可能出现给的输入链表中
存在垃圾数据，这时要考虑将链表的新尾巴的nextnode置为null
2，这里没有处理垃圾节点的释放问题
************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct DataType
{
    int address;
    int data;
    int next;
    struct DataType* nextNode;
};

void FreeList(struct DataType* head)
{
    struct DataType* node = head;
    while(node != NULL)
    {
        struct DataType* nextNode = node->nextNode;
        free(node);
        node = nextNode;
    }
    return;
}

struct DataType* FindNode(struct DataType* head, int addrress)
{
    struct DataType* node =head;
    while(node != NULL)
    {
        if(node->address == addrress)
            return node;
        else
            node = node->nextNode;
    }
    return NULL;
}

struct DataType* FindNodeByNum(struct DataType* head, int num)
{
    struct DataType* node = head;
    int i = 0;
    while(node != NULL && i < num)
    {
        node = node->nextNode;
        i++;
    }
    return node;
}

void swapData(struct DataType* fNode, struct DataType* sNode)
{
    int address, next;
    int data;

    assert(fNode != NULL && sNode != NULL);

    address = fNode->address;
    next = fNode->next;
    data = fNode->data;
    fNode->address = sNode->address;
    fNode->data = sNode->data;
    fNode->next = sNode->next;
    sNode->address = address;
    sNode->data = data;
    sNode->next = next;
    return;
}

struct DataType* AdjustList(struct DataType* head, int address)
{
    struct DataType* node = head;
    struct DataType* foundNode = NULL;

    foundNode = FindNode(node, address);
    while(node != NULL && foundNode != NULL)
    {
        if(node != foundNode)
            swapData(node, foundNode);
        address = node->next;
        node = node->nextNode;
        foundNode = FindNode(node, address);
    }
    if(node != NULL) //虽然没有遍历完整个链表，但是已经出现找不到下一个节点的情况，这时把node也就是新链表尾巴至空
    {
        if(node == head)
            return NULL;
        else
        {
            struct DataType* preNode = NULL;
            for(preNode = head; preNode->nextNode != node; preNode = preNode->nextNode){}
            preNode->nextNode = NULL;
        }
    }

    return head;
}

void PrintZero(int data)
{
    if(data == -1)
        return;
    int num = 10000;
    int quotient =data / num;
    int remainder = data % num;
    while(quotient == 0 && num > 1)
    {
        printf("0");
        num /= 10;
        quotient =remainder / num;
        remainder = remainder % num;
    }
    return;
}

void PrintList(struct DataType* head)
{
    struct DataType* node = head;
    while(node != NULL)
    {
        PrintZero(node->address);
        printf("%d %d ", node->address, node->data);
        PrintZero(node->next);
        if(node->nextNode != NULL)
            printf("%d\n",node->next);
        else
            printf("%d",node->next);
        node = node->nextNode;
    }
    return;
}

void AdjustNext(struct DataType* head, int length)
{
    int i = 0;
    struct DataType* node = head;
    while(node != NULL && i++ < length)
    {
        if(node->nextNode == NULL)
            node->next = -1;
        else
            node->next = node->nextNode->address;
        node = node->nextNode;
    }
    return;
}

void RevertList(struct DataType* head, int n, int length)
{
    struct DataType* node = head;
    int count = length;
    int i;
    while(count <= n)
    {
        for(i = 0; i < length / 2; i++)
            swapData(FindNodeByNum(node, i), FindNodeByNum(node, length - 1 - i));
        count += length;
        node = FindNodeByNum(node, length);
    }

    return;
}

int CountNodes(struct DataType* head)
{
    struct DataType* node = head;
    int count = 0;
    while(node != NULL)
    {
        count++;
        node = node->nextNode;
    }
    return count;
}

int main()
{
    int i = 0;
    int fAddr;
    int n, length;

    struct DataType* head = NULL;
    struct DataType* tail = NULL;
    struct DataType* node = NULL;

    scanf("%d %d %d", &fAddr, &n, &length);
    while(i++ < n)
    {
        node = (struct DataType*)malloc(sizeof(struct DataType));
        while(node == NULL)
            node = (struct DataType*)malloc(sizeof(struct DataType));
        if(head == NULL)
            head = tail = node;
        else
        {
            tail->nextNode = node;
            tail = node;
        }
        scanf("%d %d %d", &node->address, &node->data, &node->next);
        node->nextNode = NULL;
    }
    head = AdjustList(head, fAddr);
    n = CountNodes(head);
    RevertList(head, n, length);
    AdjustNext(head, n);
    PrintList(head);
    return 0;
}
