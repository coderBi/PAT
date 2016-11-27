/*
    1，因为这里n可能取到很到，所以要么数组存贮
    2， 如果一项一项的加就要对数组相加进行相应的模拟处理，这里可以发现其实可以一位一位的计算
        然后将进位加进去。
    3，这里计算结果可以近似看做等比数组进行预估，存结果的数组取到arr[100010]肯定够用了
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
