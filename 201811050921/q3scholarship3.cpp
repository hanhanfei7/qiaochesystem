#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
	int chinese;
	int math;
	int english;
	int num;
	int sum;
}
s[301];
int cmp(student p1,student p2)
{
	if(p1.sum == p2.sum && p1.chinese!=p2.chinese)
	{
		return p1.chinese > p2.chinese;
	}
	if(p1.sum == p2.sum && p1.chinese==p2.chinese)
	{
		return p1.num<p2.num;
	}
	else
	{
		return p1.sum>p2.sum;
	}
}
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		s[i].num=i;
		cin>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].sum=s[i].chinese+s[i].math+s[i].english;
	}
	sort(1+s,1+n+s,cmp);
	for(i=1;i<=5;i++)
	{
		cout<<s[i].num<<" "<<s[i].sum<<endl;
	}
	return 0;
}
