#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account
{
    int QQ;
    char pwd[20];
};

int IsPrime(int num);
int FindPos(struct Account arr[], int length, int QQ);

int main()
{
    int N, hashSize, i;
    scanf("%d", &N);
    for(hashSize = 2*N; IsPrime(hashSize) < 0 || (hashSize - 3)%4 != 0; hashSize++){}  //从2N开始取为了控制填充因子

    struct Account hashArr[hashSize];
    for(i = 0; i < hashSize; i++)
    {
        hashArr[i].QQ = -1;
        strcpy(hashArr[i].pwd, "\0");
    }

    char order, pwd[20];
    int QQ;
    for(i = 0; i < N; i++)
    {
        getchar();
        scanf("%c %d %s", &order, &QQ, pwd);
        int pos = FindPos(hashArr, hashSize, QQ);
        if(order == 'N')
        {
            if(pos == -1)
            {
                printf("hash array is full!\n");
                exit(1);
            }
            else if(hashArr[pos].QQ != -1)
            {
                printf("ERROR: Exist\n");
            }
            else
            {
                hashArr[pos].QQ = QQ;
                strcpy(hashArr[pos].pwd, pwd);
                printf("New: OK\n");
            }
        }
        else if(order == 'L')
        {
            if(pos == -1 || hashArr[pos].QQ == -1)
            {
                printf("ERROR: Not Exist\n");
            }
            else if(strcmp(hashArr[pos].pwd, pwd) == 0)
            {
                printf("Login: OK\n");
            }
            else
            {
                printf("ERROR: Wrong PW\n");
            }
        }
    }
    return 0;
}

int IsPrime(int num)
{
    int i = 2;
    if(num < 2)
        return -1;
    for(i = 2; i*i <= num; i++)
    {
        if(num%i == 0)
            return -1;
    }
    return 1;
}

int FindPos(struct Account arr[], int length, int QQ)
{
    int sum = 0, remind = QQ, i = 0;
    while(remind > 0)
    {
        sum += remind%10000;
        remind /= 10000;
    }
    for(i = 0; i < length; i++)
    {
        int pos = (sum + i*i)%length;
        if(arr[pos].QQ < 0 || arr[pos].QQ == QQ)
            return pos;
    }
    return -1;  //表满了
}
