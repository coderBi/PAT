#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 64

struct HuffmanNode
{
    char data;
    char code[MAX_LENGTH];
    struct HuffmanNode* left, right;
};

struct InputType
{
    char ch;
    int fre;
};

struct HuffmanNode* CreateHuffmanTree();
void SortInputArr(struct InputType arr[], int length);

int main()
{
    int N, i;

    scanf("%d", &N);
    struct InputType in;
    struct HuffmanNode* head = NULL;
    for(i = 0; i < N; i++)
    {
        getchar();
        scanf("%c, %d", &in.ch, &in.fre);
    }
    SortInputArr(in, N);
    return 0;
}

struct HuffmanNode* CreateHuffmanTree()
{

}

void SortInputArr(struct InputType arr[], int length)
{
    int i, j;
    for(i = 0; i < length; i++)
    {
        struct InputType temp = arr[i];
        for(j = i -1; j >= 0; j--)
        {
            if(arr[j].fre > temp.fre)
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = temp;
    }
    return;

}
