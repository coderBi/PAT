#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour, min;
    scanf("%d:%d", &hour, &min);

    if(hour >= 12 && hour < 24)
    {
        if(hour == 12)
        {
            printf("12:%d ", min);
        }
        else
            printf("%d:%d ", hour%12, min);

        printf("PM");
    }
    else
    {
        printf("%d:%d ", hour%12, min);
        printf("AM");
    }
    return 0;
}
