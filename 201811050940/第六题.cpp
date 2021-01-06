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
	cout << "�������ࣺ" << name << endl;
	cout << "������������" << wheels << endl;
	cout << "����������" << weight << endl;
}
class Car :private Vehicle
{
protected:
	int passenger_Load;
public:
	Car(int pl, int wh, int we, string nm) :Vehicle(wh, we, nm), passenger_Load(pl) {}
	void SetPassenger_Load(int pl) { passenger_Load = pl; }
	int GetPassenger_Load() const { return passenger_Load; }
	void show() const;
};
void Car::show() const
{
	cout << "�������ࣺ" << name << endl;
	cout << "������������" << wheels << endl;
	cout << "�����������" << passengerLoad << endl;
	cout << "����������" << weight << "kg" << endl;
}
class Truck :private Vehicle
{
protected:
	int passenger_Load;
	int payload;
public:
	Truck(int p, int pd, int wh, int we, string nm) :Vehicle(wh, we, nm), passenger_Load(p), payload(pd) {}
	void SetPassenger(int p) { passenger_Load = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passenger_Load; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const
{
	cout << "�������ࣺ" << name << endl;
	cout << "������������" << wheels << endl;
	cout << "�����������" << passenger_Load << endl;
	cout << "��������" << payload << "��" << endl;
	cout << "����������" << weight << "��" << endl;
}
int main()
{
	Car car1(5, 4, 1500, "С��");
	car1.show();
	Truck truck1(4, 3, 8, 5, "����");
	truck1.show();

	system("PAUSE");
	return 0;
}
