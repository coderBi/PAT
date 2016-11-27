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

void SelectRichest(struct Person src[], int length, struct Query order)
{
    int i = 0;
    for(; i < order.number; i++)
    {
        int j, k = -1;
        struct Person most;
        for(j = i; j < length; j++)
        {
            if(src[j].age > order.rAge || src[j].age < order.lAge)
                continue;
            if(k == -1 || most.worth < src[j].worth || (most.worth == src[j].worth && most.age > src[j].age) ||
               (most.worth == src[j].worth && most.age == src[j].age && strcmp(most.name, src[j].name) > 0))
            {
                most = src[j];
                k = j;
            }
        }
        if(k == -1 && i == 0)
        {
            printf("None");
            break;
        }
        else if(k == -1)
        {
            break;
        }
        else if(i != k)
        {
            struct Person temp = src[i];
            src[i] = src[k];
            src[k] = temp;
        }
        printf("%s %d %d\n", src[i].name, src[i].age, src[i].worth);
    }
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
        getchar();
        scanf("%s %d %d", src[i].name, &src[i].age, &src[i].worth);
    }
    for(i = 0; i < K; i++)
    {
        getchar();
        scanf("%d %d %d", &queries[i].number, &queries[i].lAge, &queries[i].rAge);
    }
    for(i = 0; i < K; i++)
    {
        printf("Case #%d:\n", i + 1);
        SelectRichest(src, N, queries[i]);
    }
    return 0;
}
