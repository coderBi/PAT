#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, j, n, length = 0;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    int res[2 * n];

    for(i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &arr2[i]);
    }

    for(i = 0, j= 0; i < n && j < n;){
        for(; i < n && arr1[i] < arr2[j]; i++){
            res[length++] = arr1[i];
        }

        for(; i < n && j < n && arr1[i] == arr2[j]; i++, j++){
            res[length++] = arr1[i];
            res[length++] = arr2[j];  //�޸ĵ㣬�����Ƕ�ӵ�һ�У�ֻ��˵���һ��caseͨ����������ġ� ���� " ����ѧ��˵���е㲻һ��
        }

        for(; j < n && i < n && arr2[j] < arr1[i]; j++){
            res[length++] = arr2[j];
        }
    }
    while(i < n){
        res[length++] = arr1[i++];
    }
    while(j < n){
        res[length++] = arr2[j++];
    }
    printf("%d", res[(length -1)/2]);
    return 0;
}

