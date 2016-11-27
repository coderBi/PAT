#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, sum = 0, s = 1;
    scanf("%d", &N);

    for(i = 1; i < N; i++)
    {
        s *= 10;
    }
    for(i = s; i < s*10; i++)
    {
        sum = 0;
        int divi = s, rem = i, oper;
        while(divi >= 1)
        {
            int j, ad = 1;

            oper = rem/divi;
            for(j = 0; j < N; j++)
            {
                ad *= oper;
            }
            sum += ad;
            rem = rem%divi;
            divi /= 10;
        }
        if(sum == i)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
