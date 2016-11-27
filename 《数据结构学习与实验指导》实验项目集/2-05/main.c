#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i, n;
    scanf("%d", &n);
    int arr[n];
    double avg, res = 0, sum = 0;

    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    avg = sum/n;

    sum = 0;
    for(i = 0; i < n; i++){
        double x = arr[i] - avg;
        sum += x*x;
    }
    sum /= n;
    res = sqrt(sum);
    printf("%.5lf", res);
    return 0;
}
