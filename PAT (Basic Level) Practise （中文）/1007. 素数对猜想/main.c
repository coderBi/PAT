#include <stdio.h>
#include <stdlib.h>

int IsPrime(int n);

int main()
{
    int i, n, count = 0;
    scanf("%d", &n);

    for(i = 2; i <= n -2; i++){
        if(IsPrime(i) && IsPrime(i + 2)) {
            count++;
            i++; //����֤�����i ��i + 2 �������� ��ô�м�� i+1��Ȼ��ż������������ ��i++ ����һ��������
        }
    }
    printf("%d", count);
    return 0;
}

int IsPrime(int n){
    if(n < 2){
        return 0;
    }
    int i;
    for(i = 2; i*i <= n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
