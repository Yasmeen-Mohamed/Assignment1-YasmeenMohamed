#include <iostream>
#include <string>
#include <queue>
#include "Car.h"
#include "Road.h"
using namespace std;

int main()
{
	Car a("Toyota", "private", "ABC123", 80, 2010);
	Car b("Mercedes", "bus", "ACP487", 60, 2015);
	Car c("BMW", "private", "BGH792", 110, 2018);
	Car d("Ducatti", "motorcycle", "TLR260", 100, 2020);
	Car e("Volvo", "truck", "WAV664", 75, 2019);
	Car f("Hyundai", "private", "JKL996", 55, 2016);
	Car g("Nissan", "private", "ACF704", 85, 2021);
	Car h("Toyota", "truck", "SOL529", 65, 2017);

	Road A('A', 60);
	Road B('B', 80);
	Road C('C', 100);
	Road r;

	queue<Car> carQueue;
	carQueue.push(a);
	carQueue.push(b);
	carQueue.push(c);
	carQueue.push(d);
	carQueue.push(e);
	carQueue.push(f);
	carQueue.push(g);
	carQueue.push(h);

	while (!carQueue.empty())
	{
			Car temp = carQueue.front();
			carQueue.pop();
			int speed = temp.getSpeed();
			string type = temp.getCarType();
			string car_brand = temp.getCarBrand();
			int year_model = temp.getYearModel();
			r.allow(type);
			bool flag = false;
			if (type == "private" || type == "motorcycle")
			{
				flag = A.radar(speed, 'A');
				if (flag == true)
				{
					cout << "Brand: " << car_brand << endl;
					cout << "Car Type: " << type << endl;
					cout << "Car Plate: " << temp.getCarPlate() << endl;
					cout << "Speed: " << speed << endl;
					cout << "Year Model: " << year_model << endl;
					cout << "This vehicle will be fined on road A." << endl;
				}
				flag = B.radar(speed, 'B');
				if (flag == true)
				{
					cout << "This vehicle will be fined on road B." << endl;
				}
			}
			else if (type == "truck")
			{
				flag = B.radar(speed, 'B');
				if (flag == true)
				{
					cout << "Brand: " << car_brand << endl;
					cout << "Car Type: " << type << endl;
					cout << "Car Plate: " << temp.getCarPlate() << endl;
					cout << "Speed: " << speed << endl;
					cout << "Year Model: " << year_model << endl;
				}
				flag = C.radar(speed, 'C');
				if (flag == true)
				{
					cout << "This vehicle will be fined on road C." << endl;
				}
			}
			else
			{
				flag = B.radar(speed, 'B');
				if (flag == true)
				{
					cout << "Brand: " << car_brand << endl;
					cout << "Car Type: " << type << endl;
					cout << "Car Plate: " << temp.getCarPlate() << endl;
					cout << "Speed: " << speed << endl;
					cout << "Year Model: " << year_model << endl;
				}
			}
			cout << "Age: " << r.age(year_model) << endl;
	}


	cout << endl << "Number of cars that passed by road A: " << r.getCountA() << endl;
	cout << "Efficiency: " << ((float(r.getCountA()) / r.getCountB()) * 100) << '%' << endl;
	cout << "Number of cars that passed by road B: " << r.getCountB() << endl;
	cout << "Efficiency: " << ((float(r.getCountB()) / r.getCountB()) * 100) << '%' << endl;
	cout << "Number of cars that passed by road C: " << r.getCountC() << endl;
	cout << "Efficiency: " << ((float(r.getCountC()) / r.getCountB()) * 100) << '%' << endl;

	return 0;
}

