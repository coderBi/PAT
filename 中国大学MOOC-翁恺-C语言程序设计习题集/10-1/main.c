#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindPos(char arr[], int length, char c);

int main()
{
    char arr[80], c;
    int length, pos, i;

    gets(arr);
    //getchar(); //�����س�Ӱ��  //��������ˣ�gets����������ʵ�Ѿ����˽�β�س������Բ��ܼ������getchar
    scanf("%c", &c);
    length = strlen(arr);
    pos = FindPos(arr, length, c);

    if(pos == -1)
    {
        printf("Not found");
        exit(0);
    }
    for(i = pos; i < length; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}

int FindPos(char arr[], int length, char c)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if(arr[i] == c)
            return i;
    }
    return -1;
}
