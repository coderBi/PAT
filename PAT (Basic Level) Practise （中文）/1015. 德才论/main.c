#include <stdio.h>
#include <stdlib.h>

struct Student{
    int number;
    int moral;
    int intelligence;
};

void Sort(struct Student arr[], int length, int high);
int Compare(struct Student s1, struct Student s2, int high);
int CompareInSameLvl(struct Student s1, struct Student s2);
void Heapify(struct Student arr[], int length, int pos, int high);
void Swap(struct Student* s1, struct Student* s2);

int main()
{
    int n, low, high, i;
    scanf("%d%d%d", &n, &low, &high);
    struct Student arr[n];

    for(i = 0; i < n; i++){
        scanf("%d%d%d", &arr[i].number, &arr[i].moral, &arr[i].intelligence);
    }

    //数据预处理，将不被录取的移到数组尾部
    for(i = 0; i < n;){
        if(arr[i].moral < low || arr[i].intelligence < low){
            Swap(&arr[i], &arr[n -1]);
            n--;
        } else {
            i++;
        }
    }

    Sort(arr, n, high);
    printf("%d\n", n);
    for(i = 0; i < n; i++){
        printf("%d %d %d\n", arr[i].number, arr[i].moral, arr[i].intelligence);
    }
    return 0;
}

//这里考虑到可能的数据范围 10^5， 采用堆排序
void Sort(struct Student arr[], int length, int high){
    int i;

    for(i = length - 1; i >= 0; i--){
        Heapify(arr, length, i, high);
    }
    while(length > 1){
        Swap(&arr[0], &arr[length - 1]);
        length--;
        Heapify(arr, length, 0, high);
    }
    return;
}

void Heapify(struct Student arr[], int length, int pos, int high){
    int child = 2*pos + 1;
    if(child < length){
        if(child + 1 < length && Compare(arr[child], arr[child +1], high) > 0){
            child++;
        }
        if(Compare(arr[pos], arr[child], high) > 0){
            Swap(&arr[pos], &arr[child]);
        }
        Heapify(arr, length, child, high);
    }
    return;
}

int Compare(struct Student s1, struct Student s2, int high){
    if(s1.moral >= high && s1.intelligence >= high){
        if(s2.moral >= high && s2.intelligence >= high){
            return CompareInSameLvl(s1, s2);
        } else {
            return 1;
        }
    } else if (s1.moral >= high) {
        if(s2.moral >= high && s2.intelligence >= high) {
            return -1;
        } else if (s2.moral >= high) {
            return CompareInSameLvl(s1, s2);
        } else {
            return 1;
        }
    } else if (s1.moral >= s1.intelligence) {
        if(s2.moral >= high){
            return -1;
        } else if (s2.moral >= s2.intelligence){
            return CompareInSameLvl(s1, s2);
        } else {
            return 1;
        }
    } else {
        if(s2.moral >= high || s2.moral >= s2.intelligence){
            return -1;
        } else {
            return CompareInSameLvl(s1, s2);
        }
    }
}

int CompareInSameLvl(struct Student s1, struct Student s2){
    if((s1.intelligence + s1.moral) > (s2.intelligence + s2.moral)){
        return 1;
    } else if ((s1.intelligence + s1.moral) < (s2.intelligence + s2.moral)){
        return -1;
    } else {
        if(s1.moral > s2.moral){
            return 1;
        } else if(s1.moral < s2.moral){
            return -1;
        } else {
            if(s1.number <= s2.number){
                return 1;
            } else {
                return -1;
            }
        }
    }
}

void Swap(struct Student* s1, struct Student* s2){
    if(s1->intelligence == s2->intelligence && s1->number == s2->number
        && s1->moral == s2->moral){
        return;
    }
    struct Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    return;
}
