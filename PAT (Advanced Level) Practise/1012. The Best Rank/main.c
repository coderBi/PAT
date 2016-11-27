/*
    一开始有一个case没通过是因为排名方法写错了对于并列排名应该是类似这样的  1 1 2 2 5
*/
#include <stdio.h>
#include <stdlib.h>

struct Grade{
    int grade;
    int rank;
};

struct Student{
    int id;
    struct Grade programming;
    struct Grade math;
    struct Grade english;
    struct Grade average;
};

struct Result{
    int rank;
    int course;
};

void Sort(struct Student student[], int length);
int Compare1(struct Student st1, struct Student st2);
int Compare2(struct Student st1, struct Student st2);
int Compare3(struct Student st1, struct Student st2);
int Compare4(struct Student st1, struct Student st2);
void Heapify(struct Student student[], int length, int pos, int (*Compare)(struct Student st1, struct Student st2));
void Swap(struct Student* st1, struct Student* st2);
int FindById(struct Student student[], int length, int id);
void SetRes(struct Student arr[], int pos, struct Result res[], int order);

int main()
{
    int m, n, i;
    char arr4Print[4] = {'C', 'M', 'E', 'A'};
    scanf("%d %d", &m, &n);
    struct Student arr[m];
    struct Result res[n];

    for(i = 0; i < m; i++){
        scanf("%d %d %d %d", &arr[i].id, &arr[i].programming.grade, &arr[i].math.grade, &arr[i].english.grade);
        arr[i].average.grade = (arr[i].math.grade + arr[i].programming.grade + arr[i].english.grade) / 3;
    }
    Sort(arr, m);

    int id, pos;
    for(i = 0; i < n; i++){
        scanf("%d", &id);
        pos = FindById(arr, m, id);
        if(pos == -1){
            res[i].rank = -1;
            continue;
        }
        SetRes(arr, pos, res, i);
    }

    for(i = 0; i < n; i++){
        if(res[i].rank == -1){
            printf("N/A\n");
            continue;
        }
        printf("%d %c\n", res[i].rank, arr4Print[res[i].course -1]);
    }
    return 0;
}

void Sort(struct Student student[], int length){
    int i, len;
    int rank = 1, j;

    //排programming
    len = length;
    for(i = len - 1; i >= 0; i--){
        Heapify(student, len, i, &Compare1);
    }
    while(len > 1){
        Swap(&student[0], &student[len - 1]);
        len--;
        Heapify(student, len, 0, &Compare1);
    }
    for(i = 0; i < length;){
        rank = i + 1;
        student[i].programming.rank = rank;
        for(j = i + 1; j < length && student[j].programming.grade == student[i].programming.grade; j++){
            student[j].programming.rank = rank;
        }
        i = j;
    }


    //排math
    len = length;
    for(i = len - 1; i >= 0; i--){
        Heapify(student, len, i, &Compare2);
    }
    while(len > 1){
        Swap(&student[0], &student[len - 1]);
        len--;
        Heapify(student, len, 0, &Compare2);
    }
    for(i = 0; i < length;){
        rank = i + 1;
        student[i].math.rank = rank;
        for(j = i + 1; j < length && student[j].math.grade == student[i].math.grade; j++){
            student[j].math.rank = rank;
        }
        i = j;
    }

    //排English
    len = length;
    for(i = len - 1; i >= 0; i--){
        Heapify(student, len, i, &Compare3);
    }
    while(len > 1){
        Swap(&student[0], &student[len - 1]);
        len--;
        Heapify(student, len, 0, &Compare3);
    }
    for(i = 0; i < length;){
        rank = i + 1;
        student[i].english.rank = rank;
        for(j = i + 1; j < length && student[j].english.grade == student[i].english.grade; j++){
            student[j].english.rank = rank;
        }
        i = j;
    }

    //排average
    len = length;
    for(i = len - 1; i >= 0; i--){
        Heapify(student, len, i, &Compare4);
    }
    while(len > 1){
        Swap(&student[0], &student[len - 1]);
        len--;
        Heapify(student, len, 0, &Compare4);
    }
    for(i = 0; i < length;){
        rank = i + 1;
        student[i].average.rank = rank;
        for(j = i + 1; j < length && student[j].average.grade == student[i].average.grade; j++){
            student[j].average.rank = rank;
        }
        i = j;
    }
}

int Compare1(struct Student st1, struct Student st2){
    if(st1.programming.grade > st2.programming.grade){
        return 1;
    } else if(st1.programming.grade < st2.programming.grade){
        return -1;
    } else {
        return 0;
    }
}

int Compare2(struct Student st1, struct Student st2){
    if(st1.math.grade > st2.math.grade){
        return 1;
    } else if(st1.math.grade < st2.math.grade){
        return -1;
    } else {
        return 0;
    }
}

int Compare3(struct Student st1, struct Student st2){
    if(st1.english.grade > st2.english.grade){
        return 1;
    } else if(st1.english.grade < st2.english.grade){
        return -1;
    } else {
        return 0;
    }
}

int Compare4(struct Student st1, struct Student st2){
    if(st1.average.grade > st2.average.grade){
        return 1;
    } else if(st1.average.grade < st2.average.grade){
        return -1;
    } else {
        return 0;
    }
}
void Heapify(struct Student student[], int length, int pos, int (*Compare)(struct Student st1, struct Student st2)) {
    int child = 2*pos + 1;

    if(child < length){
        if(child +1 < length && (*Compare)(student[child], student[child +1]) > 0){
            child++;
        }
        if((*Compare)(student[pos], student[child]) > 0) {
            Swap(&student[pos], &student[child]);
            Heapify(student, length, child, Compare);
        }
    }
}

void Swap(struct Student* st1, struct Student* st2){
    struct Student temp = *st1;
    *st1 = *st2;
    *st2 = temp;
}

int FindById(struct Student student[], int length, int id){
    int i;

    for(i = 0; i < length; i++){
        if(student[i].id == id){
            return i;
        }
    }
    return -1;
}

void SetRes(struct Student arr[], int pos, struct Result res[], int order){
    res[order].course = 4;
    res[order].rank = arr[pos].average.rank;
    if(arr[pos].programming.rank < res[order].rank){
        res[order].course = 1;
        res[order].rank = arr[pos].programming.rank;
    }
    if(arr[pos].math.rank < res[order].rank){
        res[order].course = 2;
        res[order].rank = arr[pos].math.rank;
    }
    if(arr[pos].english.rank < res[order].rank){
        res[order].course = 3;
        res[order].rank = arr[pos].english.rank;
    }
}
