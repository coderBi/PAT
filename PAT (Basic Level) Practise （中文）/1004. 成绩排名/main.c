#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[11]; //这里是个注意点，题目说长度不超过10， 这里的数组就至少要11
    char num[11];
    int grade;
};

int main()
{
    int n, i, min = 0, max = 0;
    scanf("%d", &n);
    struct Student arr[n];

    for(i = 0; i < n; i++){
        getchar();
        scanf("%s %s %d", arr[i].name, arr[i].num, &arr[i].grade);
        if(arr[min].grade > arr[i].grade){
            min = i;
        }
        if(arr[max].grade < arr[i].grade) {
            max = i;
        }
    }
    printf("%s %s\n", arr[max].name, arr[max].num);
    printf("%s %s\n", arr[min].name, arr[min].num);
    return 0;
}
