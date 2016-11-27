#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, row, column, i, j;
    char ch;
    scanf("%d %c", &n, &ch);

    column = n;
    row = n/2;
    if(n%2 != 0){
        row++;
    }
    for(i = 0; i < column; i++){
        printf("%c", ch);
    }
    printf("\n");
    for(i = 1; i < row -1; i++){
        printf("%c", ch);
        for(j = 1; j < column -1; j++){
            printf(" ");
        }
        printf("%c\n", ch);
    }
    for(i = 0; i < column; i++){
        printf("%c", ch);
    }
    return 0;
}
