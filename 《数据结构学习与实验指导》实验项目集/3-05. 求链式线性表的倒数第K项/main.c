#include <stdio.h>
#include <stdlib.h>

struct Data{
    int num;
    struct Data* previous;
};

int main()
{
    struct Data* tail = NULL;
    struct Data* node = NULL;
    int k, x;
    scanf("%d", &k);
    scanf("%d", &x);

    while(x >= 0){
        node = (struct Data*) malloc(sizeof (struct Data));
        node->previous = tail;
        tail = node;
        node->num = x;
        scanf("%d", &x);
    }

    int count = 1;
    for(node = tail; node != NULL && count < k; node = node->previous, count++){

    }
    if(node == NULL){
        printf("NULL");
    } else {
        printf("%d", node->num);
    }
    return 0;
}
