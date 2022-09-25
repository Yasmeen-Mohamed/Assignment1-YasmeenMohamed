#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
	string car_brand;
	string car_type;
	string car_plate;
	int speed;
	int year_model;

public:
	Car()
	{
		car_brand = "";
		car_type = "";
		car_plate = "";
		speed = 0;
		year_model = 0;
	}
	Car(string brand, string type, string plate, int max_speed, int model)
	{
		car_brand = brand;

		while ((type != "bus") && (type != "private") && (type != "motorcycle") && (type != "truck"))
		{
			cout << "Invalid. Choose from bus, private, motorcycle, truck: ";
			cin >> type;
		}
		car_type = type;

		while (plate.length() != 6)
		{
			cout << "Invalid.Enter 6 characters: ";
			cin >> plate;
		}
		car_plate = plate;

		speed = max_speed;
		year_model = model;
	}

	void setCarBrand(string brand);
	void setCarType(string type);
	void setCarPlate(string plate);
	void setSpeed(int max_speed);
	void setYearModel(int model);
	string getCarBrand();
	string getCarType();
	string getCarPlate();
	int getSpeed();
	int getYearModel();
};

void Car::setCarBrand(string brand)
{
	car_brand = brand;
}

void Car::setCarType(string type)
{
	while ((type != "bus") && (type != "private") && (type != "motorcycle") && (type != "truck"))
	{
		cout << "Invalid. Choose from bus, private, motorcycle, truck: ";
		cin >> type;
	}
	car_type = type;
}

void Car::setCarPlate(string plate)
{
	while (plate.length() != 6)
	{
		cout << "Invalid. Enter 6 characters: ";
		cin >> plate;
	}
	car_plate = plate;
}

void Car::setSpeed(int max_speed)
{
	speed = max_speed;
}

void Car::setYearModel(int model)
{
	year_model = model;
}

string Car::getCarBrand()
{
	return car_brand;
}

string Car::getCarType()
{
	return car_type;
}

string Car::getCarPlate()
{
	return car_plate;
}

int Car::getSpeed()
{
	return speed;
}

int Car::getYearModel()
{
	return year_model;
}
