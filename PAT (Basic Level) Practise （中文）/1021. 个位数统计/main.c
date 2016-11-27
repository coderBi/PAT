#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int res[10] = {0}, i;

    scanf("%c", &ch);
    while(ch >= '0' && ch <= '9'){
        res[ch - '0']++;
        scanf("%c", &ch);
    }
    for(i = 0; i < 10; i++){
        if(res[i] != 0){
            printf("%d:%d\n", i, res[i]);
        }
    }
    return 0;
}
