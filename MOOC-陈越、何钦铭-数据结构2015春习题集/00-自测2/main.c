#include <stdio.h>
#include <math.h>

int IsPrime(int node)
{
    int i = 2;
    int s = sqrt(node) + 1;
    while(i < s)
    {
        if(node%i == 0)
            return 0;
        else
            i++;
    }
    return 1;
}

int FindNextPrime(int node, int max)
{
    int i;
    for(i = node + 1; i <= max; i++)
    {
        if(IsPrime(i))
            return i;
    }
    return 0;
}

int main()
{
    int node = 2;
    int n, count = 0;
    scanf("%d", &n);
    while(FindNextPrime(node, n) != 0)
    {
        int nextNode = FindNextPrime(node, n);
        if((nextNode - node) == 2)
            count++;
        node = nextNode;
    }
    printf("%d", count);
    return 0;
}
