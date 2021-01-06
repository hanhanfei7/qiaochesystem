#include <stdio.h>
int fun(int a,int b);
int fun(int a,int b)
{ int c4, c3, c2,c1,c;
   c4=a%10*1000;
   c3=b%10*100;
   c2=(a/10)*10;
   c1=b/10;
   c=c4+c3+c2+c1;
  return c;
}
int main()
{
  int a,b,c;
  int d=&c;
  printf("please inter two integer number:");
  scanf("%d,%d",&a,&b);
  //printf("please inter one integer number:");
  //scanf("%d",&b);
  c=fun(a,b);
  printf("answer is:%d\n",c);
  return 0;
}
