#include "Communication.h"
#include "TestStand.h"
#include <iostream>

using namespace std;

int consoleCommunication::ReadTemperature()
{
	double ambientTemperature;
	cout << "Please, enter ambient temperature" << endl;
	cin >> ambientTemperature;
	return ambientTemperature;
}

void consoleCommunication::WriteTime(const int time)
{
	if (time == MAX_TIME)
		cout << endl << "At this ambient temperature, the engine does not overheat." << endl;
	else 
		cout << endl << "Time of engine overheating: " << time << " sec" << endl;
}
