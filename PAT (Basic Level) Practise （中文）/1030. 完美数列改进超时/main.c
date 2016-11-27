/*
    1�������ö��Ų鿴�Ľ��Ҳ��һ�����Ǹ�case 4 ���ǳ�ʱ�����ǿ��������ϴ��C++ ����Ҳ����ֱ��sort������Ƚ��ɻ�
    ��Ϊ nlogn �ĸ��Ӷȵ������ǲ���
    2, Ϊ����֤��ʱ�Ƿ�������ĸ��ӶȲ�������������󲻴���ֱ�Ӵ�ӡ���ύ�󣬷���֮ǰ��ʱ�����г����� ʱ����19ms
        Ҳ����˵��ʱ����������ɵģ��������ﲻ�ö����򷽷��ڽ��иĽ�
*/
#include <stdio.h>
#include <stdlib.h>

void Heapify(int arr[], int heapTop, int length);
void HeapSort(int arr[], int length);
void Swap(int* a, int* b);

int main()
{
    int n, p, i, count;
    scanf("%d%d", &n, &p);
    int arr[n];

    for(i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    HeapSort(arr, n);

    double divide;

    //����Ĵ����ǵ��³�ʱ��ԭ������������Ӵ���С�ң�����ͨ�����Ǵ�С��������ң���ʵ���� n^2 ���Ӷ�
    /*for(count = n; count > 0; count--){
        for(i = 0; i + count <= n; i++){
            divide = (double) arr[i + count -1]/arr[i];
            if(divide <= p){
                break;
            }
        }
        if(i + count <= n){
            break;
        }
    }*/

    int j;
    for(count = 0, i = 0; i < n; i++){
        //����⣬������ܿ���ȥ��һЩ����������������������ڼ���������� n^2 ���Ӷȣ�
        //��������������Ĵ���
        if(count >= n - i){
            break;
        }

        int max = 0;

        //�����Ȼ��ʱ�������ⲿ�ֻ���Ҫ�Ľ�
        /*for(j = i; j < n; j++){
            divide = (double) arr[j]/ arr[i];
            if(divide <= p){
                max = j - i +1;
            } else {
                break;
            }
        }*/

        //���������ע�͵ĸĶ���for����� j = i + count + 1
        for(j = i + count -1; j < n; j++){
            divide = (double) arr[j]/ arr[i];
            if(divide <= p){
                max = j - i +1;
            } else {
                break;
            }
        }
        if(max > count){
            count = max;
        }
    }
    printf("%d", count);
    return 0;
}

void HeapSort(int arr[], int length)
{
    int i;

    /*build heap*/
    for(i = length - 1; i >= 0; i--)
    {
        Heapify(arr, i, length);
    }

    while(length > 1)
    {
        Swap(&arr[0], &arr[length - 1]);
        Heapify(arr, 0, length - 1);
        length--;
    }
    return;

}

/*adjust heap top*/
void Heapify(int arr[], int heapTop, int length)
{
    int child = heapTop*2 + 1;

    if(child < length)
    {
        if((child + 1) < length && arr[child + 1] > arr[child])
        {
            child++;
        }
        if(arr[heapTop] < arr[child])
        {
            Swap(&arr[heapTop], &arr[child]);
            Heapify(arr, child, length);
        }
    }
    return;
}

void Swap(int* a, int* b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
    return;
}

