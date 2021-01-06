#include<iostream>
using namespace std;
int fun(int a, int b)
{
	return( b % 10 * 100 + b / 10 + a / 10 * 10 + a % 10 * 1000);
	

}
int main()
{
    
    int a, b, c;
    cout << "ÊäÈëa¡¢b:" << endl;
    cin >> a >> b;
   c = fun(a, b);
    cout << " c=" << c<< endl;
    return 0;
}
