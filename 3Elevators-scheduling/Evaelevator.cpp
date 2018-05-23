#include "Evaelevator.h"
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

int Evaelevator::goToFloor(int fromfloor, int tofloor, int now_time)
{
	state = 1;
	run_time = now_time;
	currentFloor = fromfloor;
	run_time += abs(tofloor - fromfloor);
	currentFloor = tofloor;
	showFloor(run_time, currentFloor);
	stop(run_time);
	state = 0;
	return currentFloor;
}

int Evaelevator::stop(int nowtime)
{
	nowtime++;
	return nowtime;
}

int Evaelevator::wait(int now_time, int now_floor)
{
	return 0;
}

void Evaelevator::showFloor(int nowtime, int nowfloor)
{
	ofstream outfile3("./output3.txt", ios::app);
	outfile3 << nowtime << " " << nowfloor << endl;
	outfile3.close();
	//cout<< nowtime << nowfloor << endl;
}

Evaelevator::Evaelevator()
{
	currentFloor = 1;
	run_time = 0;
	state = 0;
}


Evaelevator::~Evaelevator()
{
}