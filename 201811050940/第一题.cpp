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
   printf("������������λ��:");
   scanf("%d%d",&a,&b);
   printf("%d\n",fun(a,b));
}
//���ò���ʵ��
#include<stdio.h>
main()
{
	int a,b,c,d,e,f,g;
	printf("������������λ����������:");
	scanf("%d%d",&a,&b);
	d=a/10,e=b%10,f=a%10,g=b/10;
	c=1000*d+100*e+10*f+g;
	printf("���ս��:%d\n",c);
}
//ָ�����ʵ��
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
  printf("�ϲ����c��: "%d\n", c);
  main();} 
