#include <stdio.h>
int fun(int a,int b)
{   
	int c;
    c=(a/10)*1000+(b%10)*100+(a%10)*10+b/10;
    return c;
}
void main()
{
   int a,b;
   printf("请输入两个两位数:");
   scanf("%d%d",&a,&b);
   printf("%d\n",fun(a,b));
}
//引用参数实现
#include<stdio.h>
main()
{
	int a,b,c,d,e,f,g;
	printf("请输入两个两位数的正整数:");
	scanf("%d%d",&a,&b);
	d=a/10,e=b%10,f=a%10,g=b/10;
	c=1000*d+100*e+10*f+g;
	printf("最终结果:%d\n",c);
}
//指针参数实现
#include "stdio.h"
void main();
  void fun(int a, int b, long *c)     
{ 
    *c=a/10*1000+a%10*10+b/10+b%10*100;

}    
  void main()  
{   int a,b;
  long c;     
  printf("Input a, b:"); 
  scanf("%d%d", &a, &b);  
  fun(a, b, &c);     
  printf("合并结果c是: "%d\n", c);
  main();} 
