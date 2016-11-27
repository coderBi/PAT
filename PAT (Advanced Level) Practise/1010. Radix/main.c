/*
    1����һ��case���г�ʱ�����������淴��ȥԤ����һ���ַ�������һ���汾��������һ�Σ�ת����int ���������
    2�� �������һ�£�Ϊʲô��������radix2 ��ѭ�������� radix2 <= num1. ���Է�������ڶ����ַ���ֻ��һ������ô
        radix2������û����˼�ġ����������Ϊ��ô��λ >= 1�� ���radix2 > num1�� ����һ�������num2 > num1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char first[11], second[11];
    int tag, radix, i;
    scanf("%s %s %d %d", first, second, &tag, &radix);
    long long num1, num2;

    if(tag == 2){
        char temp[11];
        strcpy(temp, first);
        strcpy(first, second);
        strcpy(second, temp);
    }

    num1 = 0;
    for(i = 0; i < strlen(first); i++){
        int bit = 0;
        if(first[i] >= '0' && first[i] <= '9'){
            bit = first[i] - '0';
        } else if(first[i] >= 'a' && first[i] <= 'z'){
            bit = first[i] - 'a' + 10;
        }
        num1 *= radix;
        num1 += bit;
    }

    int radix2 = 2;
    for(i = strlen(second) -1; i >= 0; i--){
        int bit = 0;
        if(second[i] >= '0' && second[i] <= '9'){
            bit = second[i] - '0';
        } else if(second[i] >= 'a' && second[i] <= 'z'){
            bit = second[i] - 'a' + 10;
        }
        if(bit >= radix2){
            radix2 = bit + 1;
        }
    }

    do{
        num2 = 0;
        for(i = 0; i < strlen(second); i++){
            int bit = 0;
            if(second[i] >= '0' && second[i] <= '9'){
                bit = second[i] - '0';
            } else if(second[i] >= 'a' && second[i] <= 'z'){
                bit = second[i] - 'a' + 10;
            }
            num2 *= radix2;
            num2 += bit;
        }
        radix2++;
    } while (radix2 <= num1 && num2 < num1);

    if(num2 == num1){
        printf("%d", radix2 -1);
    } else {
        printf("Impossible");
    }

    return 0;
}
