/*
    1�� ������һ��case����������û�жԽ�������е�Ԫ�ؽ���ȥ���ظ�Ԫ�صĲ���
    2,ȥ�ز��������Ǹ�case��ʱ���½�һ�����飬�������з��ӵ�Ԫ���ƶ�
    3,�ٴη�������Ȼ���������������ǿ��ظ��ģ���ô��Ӧ�ý���ȥ�ز���
    4��Ϊ�˸������Աȣ���������һ���汾���
*/
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
        if(i >= n){
            break;
        }
        if(arr1[i] == arr2[j]){
            res[length++] = arr1[i];
            i++;
            j++;
        } else if(arr1[i] > arr2[j]){
            for(; j < n && arr2[j] < arr1[i]; j++){
                res[length++] = arr2[j];
            }
        }
    }
    while(i < n){
        res[length++] = arr1[i++];
    }
    while(j < n){
        res[length++] = arr2[j++];
    }
    int fRes[length], fLenght = 0, preInt;
    for(i = 0; i < length; i++){
        if(i == 0){
            fRes[fLenght++] = res[i];
            preInt = res[i];
            continue;
        }
        while(i < length && res[i] == preInt){
            i++;
        }
        if(i < length){
            fRes[fLenght++] = res[i];
            preInt = res[i];
        }
    }
    //length = RemoveRepeats(res, length);
    printf("%d", fRes[(fLenght -1)/2]);
    return 0;
}

