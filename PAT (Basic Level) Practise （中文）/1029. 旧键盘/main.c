/*
    1��һ��ʼ���һ��caseû��ͨ������Ϊ����Ŀ��˵��Ҫ�ǻ��� ��_�� Ҫ��ӡ �� �� �������֮�����һ������
        ˵����Ŀ�в���Ҫȥ�����ӡ�ո������
    2�������ҵ����������ڣ�������DeleteRepeats(char arr[], int length) �����˽������������ܻ�Ӱ�������˳��
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 85

int DeleteRepeats(char arr[], int length);

int main()
{
    char src[MAX_SIZE], des[MAX_SIZE], res[MAX_SIZE];
    gets(src);
    gets(des);
    int m = strlen(src), n = strlen(des), length = 0;
    int i, j;

    for(i = 0, j = 0; i < m && j < n;){
        for(; i < m && j < n && src[i] == des[j]; i++, j++){
        }
        for(; i < m && j < n && src[i] != des[j]; i++){
            res[length++] = src[i];
        }
    }
    while(i < m){
        res[length++] = src[i];
        i++;
    }
    length = DeleteRepeats(res, length);
    //printf("length = %d\n", length);
    for(i = 0; i < length; i++){
        /*if(res[i] == '_'){
            printf(" ");
        } else {
            printf("%c", res[i]);
        }*/
        printf("%c", res[i]);
    }
    return 0;
}

int DeleteRepeats(char arr[], int length){
    if(length <= 0){
        return 0;
    }

    int i, j;
    for(i = 0; i < length; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            arr[i] += 'A' - 'a';
        }
    }

    char res[length];
    int resLen = 0;
    for(i = 0; i < length; i++){
        for(j = 0; j < resLen; j++){
            if(arr[i] == res[j]){

                //����Ľ���������
                /*char temp = arr[i];
                arr[i] = arr[length -1];
                arr[length -1] = temp;
                length--;
                break;*/
                break;
            }
        }
        if(j == resLen){
            res[resLen++] = arr[i];
        }
    }
    for(i = 0; i < resLen; i++){
        arr[i] = res[i];
    }
    return resLen;
}
