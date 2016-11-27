/************************************************************
注意：这一道题中蕴含一种通用的解决策略，即是所有的排序问题，
可以仿照java中写一个相应的comparable方法，让各个元素之间具有可比较性
然后可以在此基础上运用所有的现有排序方法，而且相应的排序代码内部改动很小
************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Person
{
    int id;
    int virtue;
    int talent;
};

void HeapSort(struct Person arr[], int length, int line);
void Heapify(struct Person arr[], int heapTop, int length, int line);
void PrintArray(struct Person arr[], int length);
void Swap(struct Person* a, struct Person* b);
int Comparable(struct Person* p1, struct Person* p2, int line);
int CompareInSameLevel(struct Person* p1, struct Person* p2);

int main()
{
    int N, low, line, i, length = 0;
    struct Person temp;
    scanf("%d %d %d", &N, &low,  &line);
    struct Person arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talent);
        if(temp.talent >= low && temp.virtue >= low)
            arr[length++] = temp;
    }
    HeapSort(arr, length, line);
    printf("%d\n", length);
    PrintArray(arr, length);
    return 0;
}

void HeapSort(struct Person arr[], int length, int line)
{
    int i;

    /*build heap*/
    for(i = length - 1; i >= 0; i--)
    {
        Heapify(arr, i, length, line);
    }

    while(length > 1)
    {
        Swap(&arr[0], &arr[length - 1]);
        Heapify(arr, 0, length - 1, line);
        length--;
    }
    return;

}

/*adjust heap top*/
void Heapify(struct Person arr[], int heapTop, int length, int line)
{
    int child = heapTop*2 + 1;

    if(child < length)
    {
        if((child + 1) < length && Comparable(&arr[child + 1], &arr[child], line) < 0)
        {
            child++;
        }
        if(Comparable(&arr[heapTop], &arr[child], line) > 0)
        {
            Swap(&arr[heapTop], &arr[child]);
            Heapify(arr, child, length, line);
        }
    }
    return;
}

void PrintArray(struct Person arr[], int length)
{
    int i;
    if(length <= 0)
        return;
    for(i = 0; i < length; i++)
    {
        printf("%d %d %d\n", arr[i].id, arr[i].virtue, arr[i].talent);
    }
    return;
}

void Swap(struct Person* a, struct Person* b)
{
    struct Person temp = *a;

    *a = *b;
    *b = temp;
    return;
}

int Comparable(struct Person* p1, struct Person* p2, int line)
{
    if(p1->virtue >= line && p1->talent >= line)
    {
        if(p2->virtue >= line && p2->talent >= line)
        {
            return CompareInSameLevel(p1, p2);
        }
        else
            return 1;
    }
    else if(p1->virtue >= line)
    {
        if(p2->virtue >= line && p2->talent >= line)
            return -1;
        else if(p2->virtue >= line)
        {
            return CompareInSameLevel(p1, p2);
        }
        else
            return 1;
    }
    else if(p1->virtue >= p1->talent)
    {
        if(p2->virtue >= line)
            return -1;
        else if(p2->virtue >= p2->talent)
        {
            return CompareInSameLevel(p1, p2);
        }
        else
            return 1;
    }
    else
    {
        if(p2->virtue >= line || p2->virtue >= p2->talent)
            return -1;
        else
            return CompareInSameLevel(p1, p2);
    }
}

int CompareInSameLevel(struct Person* p1, struct Person* p2)
{
    if(p1->virtue + p1->talent > p2->virtue + p2->talent)
        return 1;
    else if(p1->virtue + p1->talent < p2->virtue + p2->talent)
        return -1;
    else
    {
        if(p1->virtue > p2->virtue)
            return 1;
        else if(p1->virtue < p2->virtue)
            return -1;
        else
        {
            if(p1->id < p2->id)   //id 越小越大
            return 1;
            else if(p1->id > p2->id)
                return -1;
            else
                return 0;
        }
    }
}
