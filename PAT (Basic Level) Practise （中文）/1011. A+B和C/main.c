/*
    ע����Ŀ�����ķ�Χ�� ��-2^31 2^31�� ��Ȼ����� 2^31 ��ʵ�Ǳ�ʾ���˵ģ� �ڴ��ж����Ļ��� -2^31
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i, a, b, c;
    scanf("%d", &t);

    for(i = 1; i <= t; i++){
        scanf("%d %d %d", &a, &b, &c);

        printf("Case #%d: ", i);
        if(a > 0 && b > 0){
            if(c <= 0){
                printf("true\n");
            } else {
                if(c -a < b) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
            }

        } else if (a < 0 && b < 0) {
            if(c >= 0){
                printf("false\n");
            } else {
                if(c -a < b) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
            }

        }  else {
            if(a + b > c) {
                printf("true\n");
            } else {
                printf("false\n");
            }
        }
    }

    return 0;
}
