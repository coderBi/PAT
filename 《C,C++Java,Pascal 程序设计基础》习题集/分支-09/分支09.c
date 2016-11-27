#include <stdio.h>

int main()
{
  double x;
  scanf("%lf", &x);
  
  if(x < 15)
  {
 	printf("%.2f",  4*x/3);
  }
  else
  {
   	 printf("%.2f",  2.5*x-17.5);
  }
  return 0;
}