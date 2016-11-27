/*****************************************************
1��֮ǰ��ʱ��ԭ����ѡ����ֱ��ѡ��������д������Ӷ�̫��
������ͼ���ö����������һ����
2����������н����֮ǰ��������ʱ�Ĳ�������������һ��û��ͨ��
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

void Heapify(struct Person src[], int length, int pos)
{
    int child = 2*pos + 1;
    if(child >= length)
        return;
    else if(child + 1 < length && Comparable(src[child + 1], src[child]) > 0)
        child++;
    if(Comparable(src[child], src[pos]) > 0)
    {
        Swap(&src[pos], &src[child]);
        Heapify(src, length, child);
    }
    return;
}

void SelectRichest(struct Person src[], int length, struct Query order)  //��ҪҪ�޸���������򷽷�
{
    int i = 0, j, newLength = 0;
    for(i = 0, j = length -1; j >= i;)  //��age������Ҫ��ĺ��Ƶ�ĩβ
    {
        while(j >= i && (src[j].age > order.rAge || src[j].age < order.lAge)){j--;}
        while(j >= i && src[i].age <= order.rAge && src[i].age >= order.lAge){i++;}
        if(j > i)
        {
            Swap(&src[i], &src[j]);
            j--;
            i++;
            continue;
        }
        else
        {
            break;
        }
    }
    if(src[i].age > order.rAge || src[i].age < order.lAge)
    {
        i--;
    }
    newLength = i +1;

    if(newLength <= 0)
    {
        printf("None\n");
        return;
    }

    for(i = newLength -1; i >= 0; i--)
        Heapify(src, newLength, i);
    for(i = 0; i < order.number && newLength > 0; i++)
    {
        printf("%s %d %d\n", src[0].name, src[0].age, src[0].worth);
        Swap(&src[0], &src[newLength - 1]);
        newLength--;
        Heapify(src, newLength, 0);
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
        getchar();  //����ǰ�滻�е�Ӱ��
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

