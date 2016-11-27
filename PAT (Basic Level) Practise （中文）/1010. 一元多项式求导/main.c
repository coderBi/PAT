#include <stdio.h>
#include <stdlib.h>

struct Multi{
    int factor;
    int index;
    struct Multi* next;
};

int main()
{
    struct Multi* head = NULL;
    struct Multi* tail = NULL;
    struct Multi* node = NULL;
    char ch;

    head = (struct Multi*) malloc(sizeof (struct Multi));
    tail = head;
    head->next = NULL;
    scanf("%d %d%c", &head->factor, &head->index, &ch);
    while(ch != '\n'){
        node = (struct Multi*) malloc(sizeof (struct Multi));
        tail->next = node;
        tail = node;
        node->next = NULL;
        scanf("%d %d%c", &node->factor, &node->index, &ch);
    }

    //这里不在重新开辟一个链表去存结果，直接转存在原链表中
    int i, count = 0;
    for(node = head; node != NULL; node = node->next){
        node->factor = node->factor * node->index;
        node->index--;
        if(node->factor != 0){
            count++;
        }
    }
    for(node = head, i = 0; node != NULL && i < count - 1; node = node->next){
        if(node->factor != 0){
            i++;
            printf("%d %d ", node->factor, node->index);
        }
    }
    for(; node != NULL; node = node->next){
        if(node->factor != 0){
            printf("%d %d", node->factor, node->index);
            break;
        }
    }
    if(count == 0){
        printf("0 0");
    }
    return 0;
}
