/*
    �٣�����ѧģ�͵ĽǶȿ��Է���֪�� p > 3 ��ʱ�� res = d - (p/2 +1);
    ��������Ϊ���߼���������д��ÿһ���Ĵ����Ǿ���ÿ��ֻ��Ҫ�� ���棨n -2�����˽�����������С�� ���󲿷ֵĽ����++����
    �ڣ���� p = 1�� res = d. ��� p = 2, res = 0. ��� p = 3, ����Ƚ����⣬�������ŵ��Ǹ� 1 ������ΪpΪ2��ʱ����һ�����ò����������һ�� 0 ����res=d-1
    �ۣ�p >= 3 ��ʱ�򣬾ͽ�ǰһ�� p �ķ����������ȡ����ǰ��һ�뽫������ǰ����Ľ�Ҽ�һ�������˲��֣�ʣ�µľ����Լ����ˡ�
*/
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int first, int mid ,int last){ //arr�д�first��mid�ǵ�һ���֣���mid��last�ǵڶ�����
    int *tempArr = (int*)malloc(sizeof(int) * (last - first));
    int i = first, j = mid, k = 0;
    for(; i < mid && j < last; ++k){
        if(arr[i] <= arr[j]){
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
    }
    while(i < mid){
        tempArr[k++] = arr[i++];
    }
    while(j < last){
        tempArr[k++] = arr[j++];
    }

    //�����������ԭ����
    for(k = 0; k < last - first; ++k){
        arr[k + first] = tempArr[k];
    }
}

void sort(int arr[], int length){ //������ù鲢
    int subLength = 1, i;
    for(;subLength < length; subLength *= 2){
        for(i = 0; i < length; i += 2 * subLength){
            if(i + subLength >= length){
                break;
            }
            int last = i + subLength * 2;
            if(last > length)
                last = length;
            merge(arr,i,i+subLength,last);
        }
    }
}

int getMaxGold(int d, int p){
    if(p < 1) //�쳣
        return 0;
    if(p == 1)
        return d;
    if(p == 2)
        return 0;

    // p >= 3�����
    int *goldArr = (int*)malloc(p * sizeof(int)); //�洢ÿһ���˷ֵĵĽ����
    int i;
    goldArr[0] = d;
    goldArr[1] = 0;
    for(i = 2; i < p; ++i){
        sort(goldArr, i); //��ǰ�� i��Ԫ������
        int j = 0, preSum = 0;
        for(j = 0; j <= (i -1)/ 2; ++j){
            goldArr[j]++;
            preSum += goldArr[j];
        }
        for(; j < i; ++j){
            goldArr[j] = 0;
        }
        goldArr[i] = d - preSum;
    }
    int toReturn = goldArr[p-1];
    free(goldArr);
    return toReturn;
}

int main()
{
    int d, p;
    scanf("%d%d", &d, &p);
    printf("%d\n", getMaxGold(d,p));
    return 0;
}
