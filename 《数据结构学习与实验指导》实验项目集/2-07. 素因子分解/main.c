/*
    1，这里的结果用链表存较为合适，用数组存如果建一个Factor[n] 可能会由于空间太大而被优化掉
    2，一开始有个case超时，分析知道应该是n 比较大的时候实现的次数太多，下面增加了i <= temp的
       条件约束之后解决问题
*/
#include <stdio.h>
#include <stdlib.h>

struct Factor{
    long int factor;
    long int times;
    struct Factor* next;
};

int IsPrime(long int n);

int main()
{
    long int n, i;
    scanf("%ld", &n);
    struct Factor* head = NULL;
    struct Factor* tail = NULL;
    struct Factor* node = NULL;

    long int temp = n;

    //修改点，这里增加i <= temp, 解决了有个case超时的问题
    for(i = 2; i <= n/2 && i <= temp; i++){
        if(temp%i != 0 || IsPrime(i) == 0){
            continue;
        }
        long int num = 0;
        while(temp%i == 0){
            num++;
            temp /= i;
        }
        if(num != 0){
            node = (struct Factor*)malloc(sizeof(struct Factor));
            if(head == NULL){
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            node->factor = i;
            node->times = num;
            node->next = NULL;
        }
    }
    if(head == NULL){
        printf("%ld=%ld", n, n);
        return 0;
    }
    printf("%ld=", n);
    for(node = head; node != NULL && node->next != NULL; node = node->next){
        printf("%ld", node->factor);
        if(node->times > 1){
            printf("^%ld", node->times);
        }
        printf("*");
    }
    printf("%ld", tail->factor);
    if(tail->times > 1){
        printf("^%ld", tail->times);
    }
    return 0;
}

int IsPrime(long int n){
    if(n < 2){
        return 0;
    }

    long int i;
    for(i = 2; i*i <= n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
