#include <stdio.h>
#include <stdlib.h>

void SortInt(int arr[], int length);
void PrintInt(int x);

int main()
{
    int n, m, i, arr[4];
    scanf("%d", &n);

    do{
        int temp = n;
        for(i = 0; i < 4; i++){
            arr[i] = temp%10;
            temp /= 10;
        }
        SortInt(arr, 4);
        for(i = 1; i < 4; i++){
            if(arr[i] != arr[i - 1]){
                break;
            }
        }
        if(i >= 4){
            printf("%d - %d = 0000", n, n);
            break;
        }
        n = arr[0]* 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
        m = arr[3]* 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];

        PrintInt(n);
        printf(" - ");
        PrintInt(m);
        printf(" = ");
        PrintInt(n - m);
        printf("\n");
        //printf("%d\n", n - m);  //有一个case没有通过，应该是这里的问题， n - m 可能出现格式不对 例如1000 - 0001 = 999
        n -= m;
    } while((n != 6174));
    return 0;
}

void PrintInt(int x){
    int divi = 1000;

    while(divi){
        printf("%d", x/divi);
        x %= divi;
        divi /= 10;
    }
}

void SortInt(int arr[], int length){
    int i, j;

    for(i = 1; i < length; i++){
            int temp = arr[i];
        for(j = i - 1; j >= 0; j--){
            if(arr[j] < temp){
                arr[j +1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
    return;
}
