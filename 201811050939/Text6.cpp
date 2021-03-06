#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
private:

protected:
	string name;
	int wheels;
	int weight;
public:
	Vehicle(int wh, int we, string nm) :wheels(wh), weight(we) { name = nm; }
	void SetWheels(int wh) { wheels = wh; }
	void SetWeight(int we) { weight = we; }
	void SetName(char nm[]) { name = nm; }
	int GetWheels() const { return wheels; }
	int GetWeight() const { return weight; }
	string GetName() const { return name; }
	void show() const;
};
void Vehicle::show() const
{
	cout << "汽车类别：" << name << endl;
	cout << "汽车车轮个数：" << wheels << endl;
	cout << "汽车重量：" << weight << endl;
}
class Car :private Vehicle
{
protected:
	int passengerLoad;
public:
	Car(int pl, int wh, int we, string nm) :Vehicle(wh, we, nm), passengerLoad(pl) {}
	void SetPassengerLoad(int pl) { passengerLoad = pl; }
	int GetPassengerLoad() const { return passengerLoad; }
	void show() const;
};
void Car::show() const
{
	cout << "汽车类别：" << name << endl;
	cout << "汽车车轮个数：" << wheels << endl;
	cout << "载人数：" << passengerLoad << endl;
	cout << "汽车重量：" << weight << "kg" << endl;
}
class Truck :private Vehicle
{
protected:
	int passengerLoad;
	int payload;
public:
	Truck(int p, int pd, int wh, int we, string nm) :Vehicle(wh, we, nm), passengerLoad(p), payload(pd) {}
	void SetPassenger(int p) { passengerLoad = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passengerLoad; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const
{
	cout << "汽车类别：" << name << endl;
	cout << "汽车车轮个数：" << wheels << endl;
	cout << "载人数：" << passengerLoad << endl;
	cout << "载重量：" << payload << "吨" << endl;
	cout << "汽车重量：" << weight << "吨" << endl;
}
int main()
{
	Car car1(4, 4, 1500, "小汽车");
	car1.show();
	Truck truck1(4, 2, 8, 4, "大卡车");
	truck1.show();

	system("PAUSE");
	return 0;
}
