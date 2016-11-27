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
    //p = strtok(arr, del);  //这里之所以不能用strtok是因为strtok是删除包含del里任意一个字符

    len1 = strlen(arr);
    len2 = strlen(del);
    for(i = 0; i <= len1 - len2;)
    {
        for(j = 0; j < len2/* && i + j < len1*/; j++)  //由于有上面的i <= len1 - len2 的限制 所以这里注释掉了i + j < len1
        {
            if(arr[i + j] != del[j])
            {
                i += j;
                break;
            }
        }
        if(j == 0)  //如果第一个就不符合就i++,这里要小心构成死循环（i += j）
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
