/*
    *1�������C����Ҳû��ͨ���ڶ���case����Ҫ����߼�����
    *2,���գ������õ�������int ȫ���޸�Ϊdouble ͨ���˲��ԡ�
    *3��Ŀǰ�²⵼�������Ĳ�����double��λ��ʾ�ķ�Χ��intҪ�󣬶����������int��ʾ���ӷ�ĸ����
        �����
*/
#include <stdio.h>

int main()
{
    double fz = 1, fm = 1;
    double i;
    double threshold, res = 0;

    scanf("%lf", &threshold);

    for(i = 1;; i++)
    {
        double x = fz/fm;
        res += x;
        if(x < threshold){
            break;
        }
        fz *= i;
        fm *= (2*i + 1);
    }
    printf("%.6lf", 2*res);
    return 0;
}
