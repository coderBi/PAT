#include <stdio.h>
#include <stdlib.h>

float Calculate(float arr[], float root)
{
    return arr[0]* root* root* root + arr[1]* root* root + arr[2]* root + arr[3];
}

int main()
{
    float threshold = 0.01;
    float arr[4];
    float left, right;

    scanf("%f %f %f %f", &arr[0], &arr[1], &arr[2], &arr[3]);
    scanf("%f %f", &left, &right);
    while( right - left >= threshold)
    {
        float mid = (left + right)/2;
        if(Calculate(arr, mid) == 0)
        {
             left = right = mid;
             break;
        }
        else if(Calculate(arr, mid) * Calculate(arr, left) > 0)
            left = mid;
        else
            right = mid;
    }
    printf("%.2f", (left + right)/2);
    return 0;
}
