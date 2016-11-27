/*
    1���Ľ��Ľ���������⣬���������鱣�����ַ�����Ӧ�����飬���ǻ��ǳ�ʱ��
    2����������������� do while ���������̫����
    3�� �ٴθĽ������ö��ֲ��ҽ��͸��Ӷ�
    4,����Ľ���ʱ֮����Ȼ֮ǰ���Ǹ���ʱ��case7 ������ȷ�ˣ����ǳ�����7������ȷ��case�� �����������ö��ֲ��Ҳ��ҵ��Ĳ�����С��
        ���ϵ�radix ��������6 ��7�����Լ� ����Ľ��ƶ��� 6
    5�����ﱾ����Ϊ������ 4 �е�ԭ�����м���û��ͨ��������ͨ���ο����������˵Ĵ��뷢����ʵ��������ö��ֲ������num1
       �Ƚϴ���ô�ڼ���GetValue�Ĺ����п��ܾ��Ѿ������
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long GetValue(int arr[], int length, long long radix, long long num1);
long long GetRadix(int arr[], int length, long long low, long long high, long long num1);

int main()
{
    char first[11], second[11];
    int tag, radix, i;
    scanf("%s %s %d %d", first, second, &tag, &radix);
    long long num1;

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

    int length = strlen(second);
    long long radix2 = 0; /*2*/
    int iSecond[length];
    for(i = 0; i < length; i++){
        if(second[i] >= '0' && second[i] <= '9'){
            iSecond[i] = second[i] - '0';
        } else if(second[i] >= 'a' && second[i] <= 'z'){
            iSecond[i] = second[i] - 'a' + 10;
        }
        if(iSecond[i] >= radix2){
            radix2 = iSecond[i] + 1;
        }
    }

    //�����ѭ����Ҫ�Ľ���
    /*do{
        num2 = 0;
        for(i = 0; i < length; i++){
            num2 *= radix2;
            num2 += iSecond[i];
        }
        radix2++;
    } while (radix2 <= num1 && num2 < num1);*/

    //�Ľ�Ϊ���ֲ��ң����Ӷ���ԭ���� n ��� logn
    //������ҵ���֮�󣬼��� ���ж��ֲ��ң� ��֤�����ҵ�������С�ķ��ϵ�radix
    long long low = radix2, high = num1 +1, res;

    radix2 = -1;
    res = GetRadix(iSecond, length, low, high, num1);
    while(res != -1){
        radix2 = res;
        high = res -1;
        if(low > high){
            break;
        }
        res = GetRadix(iSecond, length, low, high, num1);
    }


    if(radix2 != -1){
        printf("%lld", radix2);
    } else {
        printf("Impossible");
    }

    return 0;
}

long long GetValue(int arr[], int length, long long radix, long long num1){
    long long res = 0;
    int i;
    for(i = 0; i < length; i++){
        res *= radix;
        res += arr[i];
        //�������Ӵ�������󷵻صĽ�������num1 +1
        if(res > num1){
            return num1 +1;
        }
    }
    return res;
}

long long GetRadix(int arr[], int length, long long low, long long high, long long num1){
    long long mid;
    while(low <= high){
        mid = (low + high)/2;
        long long temp = GetValue(arr, length, mid, num1);
        if(temp < num1){
            low = mid +1;
        } else if(temp > num1){
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
