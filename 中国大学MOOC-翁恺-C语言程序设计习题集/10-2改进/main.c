/****************************************************************
1,上一个程序之所以有两个case通不过，分析得到：如果del = “ccccca”
那么下面的i += j可能就不行了，也就是移动多了，所以这里改进为
只要遇到不符合的就只进行i++
2,但是这里找到的问题却不是上面提出的问题，其实这里的问题是arr一开始的
长度应该定为81或者更大，原因是最后面的'\0'占了一个单位
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RemoveChildStr(char arr[], int i, int len2, int* length);

int main()
{
    char arr[100], del[100];  //成功通过的修改点 80 改为100，其实这里只需要改成81就行了
    int len1, len2, i, j;
    gets(arr);
    gets(del);

    len1 = strlen(arr);
    len2 = strlen(del);
    for(i = 0; i <= len1 - len2;)
    {
        for(j = 0; j < len2/* && i + j < len1*/; j++)  //由于有上面的i <= len1 - len2 的限制 所以这里注释掉了i + j < len1
        {
            if(arr[i + j] != del[j])
            {
                i++;  //这里是改动点
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
