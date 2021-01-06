#include <iostream>
using namespace std;
int fun(int &a,int &b)
{
	int c,a1,a2,b1,b2;
    {a1=a/10;a2=a%10;b1=b/10;b2=b%10;
	c=a2*1000+b2*100+a1*10+b1;}
	return c;
}
int main()
{   int fun(int &a,int &b);
	int x,y,c;
	cout << "输入两个两位整数：";
	cin>>x>>y;
	c=fun(x,y);
	cout << c;
	return 0;
}
