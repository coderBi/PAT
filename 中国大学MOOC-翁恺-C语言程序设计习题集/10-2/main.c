#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemoveChildStr(char arr[], int i, int j, int* length);

int main()
{
    char arr[80], del[80];
    int len1, len2, i, j;
    gets(arr);
    gets(del);
    //printf("%s %s\n", arr, del);
    //p = strtok(arr, del);  //����֮���Բ�����strtok����Ϊstrtok��ɾ������del������һ���ַ�

    len1 = strlen(arr);
    len2 = strlen(del);
    for(i = 0; i <= len1 - len2;)
    {
        for(j = 0; j < len2/* && i + j < len1*/; j++)  //�����������i <= len1 - len2 ������ ��������ע�͵���i + j < len1
        {
            if(arr[i + j] != del[j])
            {
                i += j;
                break;
            }
        }
        if(j == 0)  //�����һ���Ͳ����Ͼ�i++,����ҪС�Ĺ�����ѭ����i += j��
        {
            i++;
        }
        else if(j == len2)
        {
            RemoveChildStr(arr, i, len2, &len1);
            i -= (j - 1);
            if(i < 0)
                i = 0;
        }
    }
    printf("%s", arr);
    return 0;
}

void RemoveChildStr(char arr[], int i, int j, int* length)
{
    int k;
    for(k = i; k + j < *length; k++)
    {
        arr[k] = arr[k + j];
    }
    *length -= j;
    arr[*length] = '\0';
    return;
}
