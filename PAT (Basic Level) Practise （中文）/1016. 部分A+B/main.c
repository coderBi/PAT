/*
    һ��ʼ������caseû��ͨ������Ϊ ����a b �ķ�Χ��0 < A, B < 10^10����int �������Ϊ 2 * 10^9
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int d1, d2, p1 = 0, p2 = 0, i;
    char a[12], b[12];
    scanf("%s %d %s %d", a, &d1, b, &d2);

    /*do{
        if(a%10 == d1){
            p1 *= 10;
            p1 += d1;
        }
        a /= 10;
    } while(a/10 != 0);  //do while ����Ҫ�и� ��*/

    for(i = 0; i < strlen(a); i++){
        if(a[i] == d1 + '0'){
            p1 *= 10;
            p1 += d1;
        }
    }

    for(i = 0; i < strlen(b); i++){
        if(b[i] == d2 + '0'){
            p2 *= 10;
            p2 += d2;
        }
    }
    printf("%d", p1 + p2);
    return 0;
}
