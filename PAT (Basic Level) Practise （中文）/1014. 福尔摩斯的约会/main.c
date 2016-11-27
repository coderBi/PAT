/*
    这道题设计的是我见过pat里最垃圾的， 题意不清， 格式不明，蛋疼
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String{
    char arr[61];
    int length;
};

int main()
{
    struct String arr[4];
    int i, day, hour, min;
    char* week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    for(i = 0; i < 4; i++){
        gets(arr[i].arr);
        arr[i].length = strlen(arr[i].arr);
    }

    for(i = 0; i < arr[0].length && i < arr[1].length; i++){
        if(arr[0].arr[i] >= 'A' && arr[0].arr[i] <= 'G' && arr[0].arr[i] == arr[1].arr[i]){
            day = arr[0].arr[i] - 'A';
            i++;
            break;
        }
    }
    for(; i < arr[0].length && i < arr[1].length; i++){
        if(( (arr[0].arr[i] >= 'A' && arr[0].arr[i] <= 'N') || (arr[0].arr[i] >= '0' && arr[0].arr[i] <= '9') ) && arr[0].arr[i] == arr[1].arr[i]){
            if(arr[0].arr[i] >= 'A' && arr[0].arr[i] <= 'N'){
                hour = arr[0].arr[i] - 'A' + 10;
            } else {
                hour = arr[0].arr[i] - '0';
            }
            break; //有一个case没有通过是这里没有break
        }
    }

    for(i = 0; i < arr[2].length && i < arr[3].length; i++){
        if(( (arr[2].arr[i] >= 'A' && arr[2].arr[i] <= 'Z') || (arr[2].arr[i] >= 'a' && arr[2].arr[i] <= 'z') ) && arr[2].arr[i] == arr[3].arr[i]) {
            min = i;
            break;
        }
    }

    printf("%s ", week[day]);

    if(hour < 10){
        printf("0%d", hour);
    } else {
        printf("%d", hour);
    }
    if(min < 10){
        printf(":0%d", min);
    } else {
        printf(":%d", min);
    }
    return 0;
}
