/*
    从数学模型的角度可以分析知道 p > 3 的时候 res = d - (p/2 +1);
    但是这里为了逻辑清晰还是写出每一步的处理，那就是每次只需要将 后面（n -2）个人进行排序，让最小的 绝大部分的金币数++就行
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
        res = d -1; //只需要给后面一个人一个就行了
    } else {
        for(i = 4; i <= p; i++){

        }
    }
    return 0;
}

void Sort(int arr[], int rear, int scp[]){
    for()
}
