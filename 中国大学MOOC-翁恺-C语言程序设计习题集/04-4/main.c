#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, N, count = 0, in;
    scanf("%d %d", &num, &N);
    while(1)
    {
        scanf("%d", &in);
        count++;
        if(count > N || in < 0)
        {
            printf("Game Over\n");
            break;
        }
        if(in == num)
        {
            if(count == 1)
            {
                printf("Bingo!\n");
            }
            else if(count <= 3)
            {
                printf("Lucky You!\n");
            }
            else
            {
                printf("Good Guess!\n");
            }
            break;
        }
        else if(in < num)
        {
            printf("Too small\n");
        }
        else
            printf("Too big\n");
    }
    return 0;
}
