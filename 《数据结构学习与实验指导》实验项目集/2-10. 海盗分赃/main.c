/*
    ①：从数学模型的角度可以分析知道 p > 3 的时候 res = d - (p/2 +1);
    但是这里为了逻辑清晰还是写出每一步的处理，那就是每次只需要将 后面（n -2）个人进行排序，让最小的 绝大部分的金币数++就行
    ②：如果 p = 1， res = d. 如果 p = 2, res = 0. 如果 p = 3, 这个比较特殊，给紧接着的那个 1 个，因为p为2的时候他一个都拿不到，给最后一个 0 个，res=d-1
    ③：p >= 3 的时候，就将前一个 p 的分配进行排序，取出来前面一半将他们以前分配的金币加一，其他人不分，剩下的就是自己的了。
*/
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int first, int mid ,int last){ //arr中从first到mid是第一部分，从mid到last是第二部分
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

    //将结果拷贝回原数组
    for(k = 0; k < last - first; ++k){
        arr[k + first] = tempArr[k];
    }
}

void sort(int arr[], int length){ //这里采用归并
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
    if(p < 1) //异常
        return 0;
    if(p == 1)
        return d;
    if(p == 2)
        return 0;

    // p >= 3的情况
    int *goldArr = (int*)malloc(p * sizeof(int)); //存储每一个人分的的金币数
    int i;
    goldArr[0] = d;
    goldArr[1] = 0;
    for(i = 2; i < p; ++i){
        sort(goldArr, i); //对前面 i个元素排序
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
