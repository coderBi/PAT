#include <stdio.h>
#include <stdlib.h>

#define FACTOR 0.3048

int main()
{
    int in, foot, inch;
    double res;
    scanf("%d", &in);
    res = in/(FACTOR * 100.0);
    foot = (int)res;
    inch = (res - (int)res) * 12;
    printf("%d %d", foot, inch);
    return 0;
}
