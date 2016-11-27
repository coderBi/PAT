#include <stdio.h>

int main()
{
  int n, i;
  char ch;
  int sum = 0;
  int max;
  scanf("%d %c", &n, &ch);
  max = 1;
  sum += max;
  while((sum + 2*(max + 2)) <= n)
  {
    max += 2;
    sum += 2*max;
  }
  for(i = max; i > 0; i -= 2)
  {
    int k = 0;
    int j = 0;
    int s = (max -i)/2;
    while(++k <= s)
      printf(" ");
    while(j++ < i)
      printf("%c", ch);
    printf("\n");
  }
  for(i += 4; i <= max; i += 2)
  {
    int k = 0;
    int j = 0;
    int s = (max -i)/2;
    while(++k <= s)
      printf(" ");
    while(j++ < i)
      printf("%c", ch);
    printf("\n");
  }
  printf("%d", n - sum);
  return 0;
}
