/*
    1����Ϊ����n����ȡ���ܵ�������Ҫô�������
    2�� ���һ��һ��ļӾ�Ҫ��������ӽ�����Ӧ��ģ�⴦��������Է�����ʵ����һλһλ�ļ���
        Ȼ�󽫽�λ�ӽ�ȥ��
    3��������������Խ��ƿ����ȱ��������Ԥ��������������ȡ��arr[100010]�϶�������
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, n, i;
    int arr[100010] = {0}, length = 0, ad = 0;
    scanf("%d%d", &a, &n);


    for(i = n; i > 0; i--){
        arr[length] += ad + (i * a);
        ad = arr[length]/10;
        arr[length] %= 10;
        length++;
    }

    if(ad != 0){
        while(ad/10 != 0){
            arr[length++] = ad%10;
            ad /= 10;
        }
        arr[length++] = ad;
    }
    if(length <= 0){
        printf("0");
    } else {
        for(i = length -1; i >= 0; i--){
            printf("%d", arr[i]);
        }
    }
    return 0;
}
