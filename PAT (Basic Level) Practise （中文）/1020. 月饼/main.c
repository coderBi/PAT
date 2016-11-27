#include <stdio.h>
#include <stdlib.h>

struct MoonCake{
    double weight;
    double price;
};

void SortByPrice(struct MoonCake arr[], int length);
void Heapify(struct MoonCake arr[], int length, int pos);
void Swap(struct MoonCake* m1, struct MoonCake* m2);

int main()
{
    int n, i;
    double price, dweight;
    scanf("%d %lf", &n, &dweight);
    struct MoonCake arr[n];

    for(i = 0; i < n; i++){
        scanf("%lf", &arr[i].weight);
    }
    for(i = 0; i < n; i++){
        scanf("%lf", &price);
        arr[i].price = price/arr[i].weight;
    }
    SortByPrice(arr, n);

    double sumWeight = 0, sumPrice = 0;
    for(i = 0; i < n; i++){
        if(sumWeight + arr[i].weight <= dweight){
            sumWeight += arr[i].weight;
            sumPrice += arr[i].price * arr[i].weight;
        } else {
            sumPrice += arr[i].price * (dweight - sumWeight);
            break;
        }
    }
    printf("%.2lf", sumPrice);
    return 0;
}

void SortByPrice(struct MoonCake arr[], int length){
    int i;

    for(i = length -1; i >= 0; i--){
        Heapify(arr, length, i);
    }
    while(length > 1){
        Swap(&arr[0], &arr[length - 1]);
        length--;
        Heapify(arr, length, 0);
    }
}

void Heapify(struct MoonCake arr[], int length, int pos){
    int child = 2*pos + 1;

    if(child < length){
        if(child + 1 < length && arr[child + 1].price < arr[child].price){
            child++;
        }
        if(arr[pos].price > arr[child].price){
            Swap(&arr[pos], &arr[child]);
            Heapify(arr, length, child);
        }
    }
}

void Swap(struct MoonCake* m1, struct MoonCake* m2){
    if(m1 == m2){
        return;
    }

    struct MoonCake temp = *m1;
    *m1 = *m2;
    *m2 = temp;
    return;
}
