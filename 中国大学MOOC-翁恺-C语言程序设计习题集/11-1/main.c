#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[15];
    char age[15];
    char sex;
    char phone[20];
    char tel[20];
};

int main()
{
    int N, i, k, id;
    scanf("%d", &N);
    struct Person arr[N];
    for(i = 0; i < N; i++)
    {
        getchar(); //读空格
        scanf("%s", arr[i].name);
        getchar();
        scanf("%s", arr[i].age);
        getchar();
        scanf("%c", &arr[i].sex);
        getchar(); // 读进后面的空格
        scanf("%s", arr[i].phone);
        getchar();
        scanf("%s", arr[i].tel);
    }
    scanf("%d", &k);
    for(i = 0; i < k; i++)
    {
        scanf("%d", &id);
        if(id >= 0 && id < N)
        {
            printf("%s %s %s %c %s\n", arr[id].name, arr[id].phone, arr[id].tel, arr[id].sex, arr[id].age);
        }
        else
        {
            printf("Not Found\n");
        }
    }
    return 0;
}
