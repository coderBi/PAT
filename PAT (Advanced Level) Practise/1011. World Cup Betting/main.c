/*
    1��������Ȼͨ�������е�case�����Ǳ�©��double  float ���ڴ��ж����Ʊ�ʾ����ȫ������
    2��Ŀǰֻ���뵽BigDecimal�Ľ������
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char res[3] = {'W', 'T', 'L'};
    float sum = 1.0f, arr[3][3];
    int i, j, sp[3];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%f", &arr[i][j]);
        }
    }
    for(i = 0; i < 3; i++){
        sp[i] = 0;
        for(j = 1; j < 3; j++){
            if(arr[i][sp[i]] < arr[i][j]){
                sp[i] = j;
            }
        }
    }
    for(i = 0; i < 3; i++){
        printf("%c ", res[sp[i]]);
        sum *= arr[i][sp[i]];
    }
    sum = (sum * 0.65 -1)*2.0;

    //���﷢�ֱ߽�������硣0975000��������������Ľ���������ڴ��ж����Ʊ�ʾ���ܵ��³��ִ�ӡ�쳣
    //������������Ŀǰֻ���뵽��java�е�BigDecimal ���������ַ���������
    printf("%.2f", sum);
    return 0;
}
