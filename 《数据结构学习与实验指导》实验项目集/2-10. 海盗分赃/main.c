/*
    ����ѧģ�͵ĽǶȿ��Է���֪�� p > 3 ��ʱ�� res = d - (p/2 +1);
    ��������Ϊ���߼���������д��ÿһ���Ĵ����Ǿ���ÿ��ֻ��Ҫ�� ���棨n -2�����˽�����������С�� ���󲿷ֵĽ����++����
*/
#include <stdio.h>
#include <stdlib.h>

void Sort(int arr[], int rear);

int main()
{
    int i, d, p, res;
    scanf("%d%d", &d, &p);
    int arr[p], length = 0;
    int scp[p];

    if(p == 1){
        res = d;
    } else if(p == 2) {
        res = 0;
    } else if(p == 3) {
        res = d -1; //ֻ��Ҫ������һ����һ��������
    } else {
        for(i = 4; i <= p; i++){

        }
    }
    return 0;
}

void Sort(int arr[], int rear, int scp[]){
    for()
}
