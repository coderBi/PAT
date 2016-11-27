#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max = 0, sum = 0;
    int m, n;
    int i = 0;
    int first, last;
    int mid1, mid2, mid3;
    int flag = 0; //max=0 &&  some input n = 0  -> flag = 1
    scanf("%d", &m);
    while(i < m)
    {
        scanf("%d", &n);
        if(n == 0)
            flag = 1;
        if(i == 0)
            first = n;
        if(i == m - 1)
            last = n;
        if(sum == 0)
            mid3 = n;
        sum += n;
        if(sum > max)
        {
            max = sum;
            mid1 = mid3;
            mid2 = n;
        }
        if(sum < 0)
        {
            sum = 0;
        }
        i++;
    }
    if(max == 0 && flag == 1)
        printf("%d %d %d", max, 0, 0);
    else if(max == 0)
        printf("%d %d %d", max, first, last);
    else
        printf("%d %d %d", max, mid1, mid2);
    return 0;
}
