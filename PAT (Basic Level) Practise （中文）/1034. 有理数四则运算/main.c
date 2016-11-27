/*
    1,一开始用int处理数据，有两个case没有通过，原因是在进行数据运算时结果可能超出了int的范围
        换成long long就搞定了
    2,long long 的输入 在不同的输入环境可能格式不同， 对于gcc编译器 ，在linux下是 lld% Windows下是 I64d%
        所以下面的代码在Windows下运行，会有警告。
*/
#include <stdio.h>
#include <stdlib.h>

struct FShu{
    long long flag;
    long long fz;
    long long fm;
};

void PrintFShu(struct FShu fs);
long long GetMaxGy(long long m, long long n);
void Reduction(struct FShu* fs);

int main()
{
    int i;
    struct FShu arr[2];
    struct FShu res;

    for(i = 0; i < 2; i++){
        scanf("%lld/%lld", &arr[i].fz, &arr[i].fm);
        if(arr[i].fz < 0){
            arr[i].fz *= -1;
            arr[i].flag = -1;
        } else {
            arr[i].flag = 1;
        }
        Reduction(&arr[i]);
    }

    PrintFShu(arr[0]);
    printf(" + ");
    PrintFShu(arr[1]);
    printf(" = ");
    res.fz = arr[0].fz* arr[1].fm * arr[0].flag + arr[1].fz * arr[0].fm * arr[1].flag;
    res.fm = arr[0].fm * arr[1].fm;
    res.flag = 1;
    if(res.fz < 0){
        res.flag = -1;
        res.fz *= -1;
    }
    Reduction(&res);
    PrintFShu(res);
    printf("\n");

    PrintFShu(arr[0]);
    printf(" - ");
    PrintFShu(arr[1]);
    printf(" = ");
    res.fz = arr[0].fz* arr[1].fm * arr[0].flag - arr[1].fz * arr[0].fm * arr[1].flag;
    res.fm = arr[0].fm * arr[1].fm;
    res.flag = 1;
    if(res.fz < 0){
        res.flag = -1;
        res.fz *= -1;
    }
    Reduction(&res);
    PrintFShu(res);
    printf("\n");

    PrintFShu(arr[0]);
    printf(" * ");
    PrintFShu(arr[1]);
    printf(" = ");
    res.fz = arr[0].fz * arr[1].fz;
    res.fm = arr[0].fm * arr[1].fm;
    res.flag = arr[0].flag * arr[1].flag;
    Reduction(&res);
    PrintFShu(res);
    printf("\n");

    PrintFShu(arr[0]);
    printf(" / ");
    PrintFShu(arr[1]);
    printf(" = ");
    res.fz = arr[0].fz * arr[1].fm;
    res.fm = arr[0].fm * arr[1].fz;
    res.flag = arr[0].flag * arr[1].flag;
    Reduction(&res);
    PrintFShu(res);
    printf("\n");
    return 0;
}

long long GetMaxGy(long long m, long long n){
    if(m < n){
        long long temp = m;
        m = n;
        n = temp;
    }
    long long remind = m%n;
    while(remind != 0){
        m = n;
        n = remind;
        remind = m%n;
    }
    return n;
}

void PrintFShu(struct FShu fs){
    if(fs.fm == 0){
        printf("Inf");
        return;
    }
    if(fs.fz == 0){
        printf("0");
        return;
    }
    if(fs.flag < 0){
        printf("(-");
    }
    if(fs.fz/fs.fm != 0){
        printf("%lld", fs.fz/fs.fm);
    }
    if(fs.fz%fs.fm != 0){
        if(fs.fz/fs.fm != 0){
            printf(" ");
        }
        printf("%lld/%lld", fs.fz%fs.fm, fs.fm);
    }

    if(fs.flag < 0){
        printf(")");
    }
}

void Reduction(struct FShu* fs){
    if(fs->fz == 0 || fs->fm == 0){
        return;
    }
    long long gy = GetMaxGy(fs->fm, fs->fz);
    fs->fm /= gy;
    fs->fz /= gy;
}
