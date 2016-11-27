/*
    1，改进的结果不如人意，尽管用数组保存了字符串相应的数组，但是还是超时。
    2，初步分析是下面的 do while 里面的条件太宽了
    3， 再次改进，采用二分查找降低复杂度
    4,这里改进超时之后，虽然之前的那个超时的case7 现在正确了，但是出现了7个不正确的case， 分析是这里用二分查找查找到的不是最小的
        符合的radix 例如数字6 在7进制以及 更大的进制都是 6
    5，这里本来以为是上面 4 中的原因导致有几个没有通过，但是通过参考网上其他人的代码发现其实是如果采用二分查找如果num1
       比较大，那么在计算GetValue的过程中可能就已经溢出了
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

    //下面的循环需要改进，
    /*do{
        num2 = 0;
        for(i = 0; i < length; i++){
            num2 *= radix2;
            num2 += iSecond[i];
        }
        radix2++;
    } while (radix2 <= num1 && num2 < num1);*/

    //改进为二分查找，复杂度由原来的 n 变成 logn
    //这里查找到了之后，继续 进行二分查找， 保证最终找到的是最小的符合的radix
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
        //这里增加处理让最后返回的结果最多是num1 +1
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
