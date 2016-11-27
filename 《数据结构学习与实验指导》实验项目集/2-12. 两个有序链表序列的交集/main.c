/*
    1����һ��caseû��ͨ���������Ƕ���ͬһ��Ԫ�أ�������ܴ��ڶ�δ�ӡ�������
    �������浱front->num == x �������֮���front����
    2���޸�֮��ɹ�ͨ������case
*/
#include <stdio.h>
#include <stdlib.h>

struct DataType{
    int num;
    struct DataType* next;
};

void PrintLink(struct DataType* head);
struct DataType* AddNodeAtTail(struct DataType* head, struct DataType* node);

int main()
{
    int x;
    struct DataType* head = NULL;
    struct DataType* tail = NULL;
    struct DataType* node = NULL;
    struct DataType* resHead = NULL;

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
    struct DataType* front = head;
    while(x != -1){
        for(; front != NULL && front->num < x; front = front->next){

        }
        if(front == NULL){
            break;
        }
        if(front->num == x){
            struct DataType* temp = (struct DataType*) malloc(sizeof(struct DataType));
            temp->num = x;
            temp->next = NULL;
            resHead = AddNodeAtTail(resHead, temp);
            front = front->next;  //�޸ĵ�
        }
        scanf("%d", &x);
    }
    PrintLink(resHead);
    return 0;
}

struct DataType* AddNodeAtTail(struct DataType* head, struct DataType* node){
    if(head == NULL){
        head = node;
        return head;
    }

    struct DataType* tail = head;
    for(; tail != NULL && tail->next != NULL; tail = tail->next){

    }
    tail->next = node;
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
