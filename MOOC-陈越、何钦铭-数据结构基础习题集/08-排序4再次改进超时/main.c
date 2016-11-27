/*****************************************************
1，经过分析，既然nlog(n)的堆排都通过不，应该是一开始思路有问题
应该是多次重复排序啦
2，这里直接先用堆排将所有人排好了以后在一组一组的取出
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[10];
    int age;
    int worth;
};

struct Query
{
    int number;
    int lAge;
    int rAge;
};

void Swap(struct Person* p1, struct Person* p2)
{
    struct Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    return;
}

int Comparable(struct Person p1, struct Person p2)
{
    if(p1.worth > p2.worth)
        return 1;
    else if(p1.worth < p2.worth)
        return -1;
    else
    {
        if(p1.age < p2.age)
            return 1;
        else if(p1.age > p2.age)
            return -1;
        else
        {
            if(strcmp(p1.name, p2.name) > 0)
                return -1;
            else if(strcmp(p1.name, p2.name) < 0)
                return 1;
            else
                return 0;
        }
    }
}

void Heapify(struct Person src[], int length, int pos)  //注意这里跟上一次改进超时不一样，这里需要构建最小堆
{
    int child = 2*pos + 1;
    if(child >= length)
        return;
    else if(child + 1 < length && Comparable(src[child + 1], src[child]) < 0)
        child++;
    if(Comparable(src[child], src[pos]) < 0)
    {
        Swap(&src[pos], &src[child]);
        Heapify(src, length, child);
    }
    return;
}

void HeapSort(struct Person src[], int length)
{
    int i = 0;
    for(i = length -1; i >= 0; i--)
        Heapify(src, length, i);
    for(i = 0; length > 0; i++)
    {
        Swap(&src[0], &src[length - 1]);
        length--;
        Heapify(src, length, 0);
    }
    return;
}

void SelectRichest(struct Person src[], int length, struct Query order)
{
    int i = 0, k = 0;
    for(; i < length && k < order.number; i++)
    {
        if(src[i].age >= order.lAge && src[i].age <= order.rAge)
        {
             printf("%s %d %d\n", src[i].name, src[i].age, src[i].worth);
             k++;
        }
    }
    if(k == 0)
        printf("None\n");
    return;
}

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    struct Person src[N];
    struct Query queries[K];
    for(i = 0; i < N; i++)
    {
        getchar();  //消除前面换行的影响
        scanf("%s %d %d", src[i].name, &src[i].age, &src[i].worth);
    }
    for(i = 0; i < K; i++)
    {
        getchar();
        scanf("%d %d %d", &queries[i].number, &queries[i].lAge, &queries[i].rAge);
    }
    HeapSort(src, N);
    for(i = 0; i < K; i++)
    {
        printf("Case #%d:\n", i + 1);
        SelectRichest(src, N, queries[i]);
    }
    return 0;
}

