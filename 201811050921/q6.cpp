#include <iostream>
using namespace std;
class vehicle
{
public:
	vehicle(int a, float b)
	{
		//cout << "已构造" << endl;
		wheels = a;
		weight = b;
	}
	~vehicle()
	{
		cout << "已析构" << endl;
	}
protected:
	int wheels = 0;
	float weight = 0;
};

class car :private vehicle
{
public:
	car(int i, float j, int k) :vehicle(i, j)
	{
		cout << "car已构造" << endl;
		passenger_load = k;
	}
	~car()
	{
		cout << "car已析构" << endl;
	}
	int show_wheels()
	{
		return wheels;
	}
	float show_weight()
	{
		return weight;
	}
	int show_passenger_load()
	{
		return passenger_load;
	}
private:
	int passenger_load;
};

class truck :private vehicle
{
public:
	truck(int i, float j, int k, float l) :vehicle(i, j)
	{
		cout << "truck已构造" << endl;
		passenger_load = k;
		payload = l;
	}
	~truck()
	{
		cout << "truck已析构" << endl;
	}
	int show_wheels()
	{
		return wheels;
	}
	float show_weight()
	{
		return weight;
	}
	int show_passenger_load()
	{
		return passenger_load;
	}
	float show_payload()
	{
		return payload;
	}
private:
	int passenger_load;
	float payload;
};

int main()
{
	car car1(4, 50, 5);
	truck truck1(8, 100, 2, 80);
	cout << "小车信息：" << endl;
	cout << "车轮个数：" << car1.show_wheels() << endl;
	cout << "车重：" << car1.show_weight() << endl;
	cout << "载人数：" << car1.show_passenger_load() << endl;
	cout << endl;
	cout << "卡车信息：" << endl;
	cout << "车轮个数：" << truck1.show_wheels() << endl;
	cout << "车重：" << truck1.show_weight() << endl;
	cout << "载人数：" << truck1.show_passenger_load() << endl;
	cout << "载重量：" << truck1.show_weight() << endl;
	system("pause");
}