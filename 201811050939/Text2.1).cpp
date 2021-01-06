#include <iostream>
using namespace std;
int main()
{
int m,n,number,count=1;
int monkey[999];
int t;
int i;
cout<<"请输入猴子个数m和报数n:"<<endl;
cin>>m>>n;
number=m;
for(i=0;i<m;i++)
monkey[i]=i+1;
t=0;
while(number>1)
{
if(monkey[t]>0)
{
if(count!=n)
{
count++;
t=(t+1)%m;
}
else
{
monkey[t]=0;
count=1;number--;
t=(t+1)%m;
}
}
else
{t=(t+1)%m;
}
}
for(i=0;i<m;i++)
{
if(monkey[i]>0)
cout<<"猴子大王:"<<monkey[i]<<endl;
}
return 0;
}
