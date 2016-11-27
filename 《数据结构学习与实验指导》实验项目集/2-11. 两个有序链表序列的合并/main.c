/*
    1,�������ʵ����������дһ����������
    2,��һ��case���г�ʱ��ͨ���������ӵ�front ��������ҵ���ʼ�㣬�������˳�ʱ�����⡣�Ǹ���ʱ��case
        ���յ�ʱ����200+
*/
#include <stdio.h>
#include <stdlib.h>

struct DataType{
    int num;
    struct DataType* next;
};

struct DataType* Insert(struct DataType* head, struct DataType** front, struct DataType* node);
void PrintLink(struct DataType* head);

int main()
{
    int x;
    struct DataType* head = NULL;
    struct DataType* tail = NULL;
    struct DataType* node = NULL;

    scanf("%d", &x);
    while(x != -1){
        node = (struct DataType*) malloc(sizeof(struct DataType));
        if(head == NULL){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        node->num = x;
        node->next = NULL;
        scanf("%d", &x);
    }

    scanf("%d", &x);
    struct DataType* front = head; //�������һ���������ҵ���ʼ��
    while(x != -1){
        node = (struct DataType*) malloc(sizeof(struct DataType));
        node->num = x;
        node->next = NULL;
        head = Insert(head, &front, node);
        scanf("%d", &x);
    }
    PrintLink(head);
    return 0;
}

struct DataType* Insert(struct DataType* head, struct DataType** front, struct DataType* node){
    struct DataType* p = *front;
    struct DataType* pre = *front;

    if(head == NULL){
        head = node;
        return head;
    }
    for(; p != NULL; p = p->next){
        if(p->num > node->num){
            break;
        }
        pre = p;
    }

    if(p == head){
        node->next = head;
        head = node;
    } else {
        node->next = pre->next;
        pre->next = node;
    }
    *front = node; //��һ�δ���һ�ε�node��ʼ����
    return head;
}

void PrintLink(struct DataType* head){
    if(head == NULL){
        printf("NULL");
        return;
    }

    struct DataType* node = head;
    for(; node != NULL && node->next != NULL; node = node->next){
        printf("%d ", node->num);
    }
    printf("%d", node->num);
    return;
}
