/****************************************************************
1,��һ������֮����������caseͨ�����������õ������del = ��ccccca��
��ô�����i += j���ܾͲ����ˣ�Ҳ�����ƶ����ˣ���������Ľ�Ϊ
ֻҪ���������ϵľ�ֻ����i++
2,���������ҵ�������ȴ����������������⣬��ʵ�����������arrһ��ʼ��
����Ӧ�ö�Ϊ81���߸���ԭ����������'\0'ռ��һ����λ
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemoveChildStr(char arr[], int i, int len2, int* length);

int main()
{
    char arr[100], del[100];  //�ɹ�ͨ�����޸ĵ� 80 ��Ϊ100����ʵ����ֻ��Ҫ�ĳ�81������
    int len1, len2, i, j;
    gets(arr);
    gets(del);

    len1 = strlen(arr);
    len2 = strlen(del);
    for(i = 0; i <= len1 - len2;)
    {
        for(j = 0; j < len2/* && i + j < len1*/; j++)  //�����������i <= len1 - len2 ������ ��������ע�͵���i + j < len1
        {
            if(arr[i + j] != del[j])
            {
                i++;  //�����ǸĶ���
                break;
            }
        }
        if(j == len2)
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

void RemoveChildStr(char arr[], int i, int len2, int* length)
{
    int k;
    for(k = i; k + len2 < *length; k++)
    {
        arr[k] = arr[k + len2];
    }
    *length -= len2;
    arr[*length] = '\0';
    return;
}
