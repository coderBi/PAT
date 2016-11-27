#include <stdio.h>
#include <stdlib.h>

struct Person{
    int chui;
    int jian;
    int bu;
};

int main()
{
    int i, n, ping = 0;
    struct Person arr[2] = {{0, 0, 0}};
    char ch1, ch2;
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        getchar();
        scanf("%c %c", &ch1, &ch2);

        if(ch1 == ch2){
            ping++;
        } else if (ch1 == 'C'){
            if(ch2 == 'J'){
                arr[0].chui++;
            } else {
                arr[1].bu++;
            }
        } else if (ch1 == 'J') {
            if(ch2 == 'C'){
                arr[1].chui++;
            } else {
                arr[0].jian++;
            }
        } else {
            if(ch2 == 'C'){
                arr[0].bu++;
            } else {
                arr[1].jian++;
            }
        }
    }

    int maxCh1 = arr[0].bu, maxCh2 = arr[1].bu;
    char res1 = 'B', res2 = 'B';
    if(arr[0].chui > maxCh1){
        maxCh1 = arr[0].chui;
        res1 = 'C';
    }
    if(arr[0].jian > maxCh1){
        maxCh1 = arr[0].jian;
        res1 = 'J';
    }

    if(arr[1].chui > maxCh2){
        maxCh2 = arr[1].chui;
        res2 = 'C';
    }
    if(arr[1].jian > maxCh2){
        maxCh2 = arr[1].jian;
        res2 = 'J';
    }

    int win = arr[0].bu + arr[0].chui +arr[0].jian;
    int lose = arr[1].bu + arr[1].chui +arr[1].jian;
    printf("%d %d %d\n", win, ping, lose);
    printf("%d %d %d\n", lose, ping, win);
    printf("%c %c", res1, res2);

    return 0;
}
