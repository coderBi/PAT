#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in;
    scanf("%d", &in);
    printf("Speed: %d - ", in);
    if(in > 60)
        printf("Speeding");
    else
        printf("OK");
    return 0;
}
