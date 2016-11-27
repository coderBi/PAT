#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f1, f2;
    int a;
    char c;
    scanf("%f %d %c %f", &f1, &a, &c, &f2);
    printf("%c %d %.2f %.2f", c, a, f1, f2);
    return 0;
}
