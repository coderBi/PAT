#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person{
    char name[6];
    char birthday[11];
};

void Swap(struct Person* p1, struct Person* p2);

int main()
{
    int n, i, length = 0, max, min;
    char minBirth[11] = "1814/09/06", now[11] = "2014/09/06";
    scanf("%d", &n);
    struct Person arr[n];

    length = n;
    for(i = 0; i < n; i++){
        getchar();
        scanf("%s %s", arr[i].name, arr[i].birthday);
    }
    for(i  = 0; i < length;){
        if(strcmp(arr[i].birthday, now) > 0 || strcmp(arr[i].birthday, minBirth) < 0){
            Swap(&arr[i], &arr[length -1]);
            length--;
        } else {
            i++;
        }
    }

    for(min = 0, max = 0, i = 1; i < length; i++){
        if(strcmp(arr[max].birthday, arr[i].birthday) > 0){
            max = i;
        }
        if(strcmp(arr[min].birthday, arr[i].birthday) < 0){
            min = i;
        }
    }
    if(length > 0){
        printf("%d %s %s", length, arr[max].name, arr[min].name);
    } else {
        printf("0"); //一开始有一个case没有通过是这里没有处理length = 0 的情况
    }
    return 0;
}

void Swap(struct Person* p1, struct Person* p2){
    struct Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
