#include <iostream>
#include <string>
using namespace std;

class Road
{
private:
	char road_type;
	int speed_limit;
	int countA, countB, countC;
public:
	Road()
	{
		road_type = ' ';
		speed_limit = 0;
		countA = 0;
		countB = 0;
		countC = 0;
	}
	Road(char rType, int limit)
	{
		while ((rType != 'A') && (rType != 'B') && (rType != 'C'))
		{
			cout << "Invalid. Choose A or B or C: ";
			cin >> rType;
		}
		road_type = rType;

		speed_limit = limit;
	}
	void setRoadType(char rType);
	void setSpeedLimit(int limit);
	char getRoadType();
	int getSpeedLimit();
	void allow(string type);
	bool radar(int car_speed, char rType);
	int age(int model);
	int getCountA();
	int getCountB();
	int getCountC();
};

void Road::setRoadType(char rType)
{
	while ((rType != 'A') && (rType != 'B') && (rType != 'C'))
	{
		cout << "Invalid. Choose A or B or C: ";
		cin >> rType;
	}
	road_type = rType;
}

void Road::setSpeedLimit(int limit)
{
	speed_limit = limit;
}

char Road::getRoadType()
{
	return road_type;
}

int Road::getSpeedLimit()
{
	return speed_limit;
}

int Road::getCountA()
{
	return countA;
}

int Road::getCountB()
{
	return countB;
}

int Road::getCountC()
{
	return countC;
}

bool Road::radar(int car_speed, char rType)
{
	if (((rType == 'A') && (car_speed > 60)) || ((rType == 'B') && (car_speed > 80)) || ((rType == 'C') && (car_speed > 100)))
		return true;
	else
		return false;
}

void Road::allow(string type)
{

	if (type == "private" || type == "motorcycle")
	{
		cout << endl << "- This vehicle is allowed on road A and B only" << endl;
		countA++;
		countB++;
	}
	else if (type == "truck")
	{
		cout << endl << "- This vehicle is allowed on road B and C only" << endl;
		countB++;
		countC++;
	}
	else
	{
		cout << endl << "- This vehicle is allowed on road B only" << endl;
		countB++;
	}

}

int Road::age(int model)
{
	return (2022 - model);
}

