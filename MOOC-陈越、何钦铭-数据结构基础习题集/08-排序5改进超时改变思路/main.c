/********************************************************
1,֮����֮ǰ�ᳬʱ������������֮ǰûһ�ν�����Ҫ����һ�ζ�Ӧ
��ֵ�Ĳ�ѯ������������ɣ������������Ҳ��������Ҫ���ʱ�临�Ӷ�
Ӧ�ñ�һ��������Ҫ��
2����������µĸĽ��Ǹ�����һ������������ġ����ڽǱ����ֵ����0-n
�������Ƕ�����ֵ���е�ʱ����Խ���ֵ�����Ǳ꣬������Ӧ�ĽǱ굱����ֵ���д洢
�����Ϳ��Խ�ʡ��Ӧ��ֵ�Ǳ�Ĳ�ѯ������
*********************************************************/

#include <stdio.h>
#include <stdlib.h>

void Swap0(int arr[], int pos0, int pos)
{
    int temp = arr[pos0];
    arr[pos0] = arr[pos];
    arr[pos] = temp;
    return;
}

int GetSwaps(int arr[], int length)
{
    int i = 1, pos, count = 0;
    while(i < length)
    {
        if(arr[0] == 0)
        {
            for(; i < length && arr[i] == i; i++){}
            if(i < length)
            {
                Swap0(arr, 0, i);
                count++;
            }
        }

        while(arr[0] != 0)
        {
            pos = arr[0];
            Swap0(arr, 0, pos);
            count++;
        }
    }
    return count;
}

int main()
{
    int N, i, in;
    scanf("%d", &N);
    int arr[N];
    for(i = 0; i < N; i++)
    {
        scanf("%d", &in);
        arr[in] = i;   //��Ǳ�
    }
    printf("%d", GetSwaps(arr, N));
    return 0;
}
