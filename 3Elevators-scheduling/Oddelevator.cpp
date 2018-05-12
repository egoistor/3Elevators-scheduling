#include "Oddelevator.h"
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;


int Oddelevator::goToFloor(int fromfloor, int tofloor, int now_time)
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

int Oddelevator::stop(int nowtime)
{
	nowtime++;
	return nowtime;
}

int Oddelevator::wait(int i, int j)
{
	return 0;
}

void Oddelevator::showFloor(int nowtime, int nowfloor)
{
	ofstream outfile2("./output2.txt", ios::app);
	outfile2 << nowtime << " " << nowfloor << endl;
	outfile2.close();
	//cout<< nowtime <<  nowfloor << endl;
}

Oddelevator::Oddelevator()
{
	currentFloor = 1;
	run_time = 0;
	state = 0;
}


Oddelevator::~Oddelevator()
{
}
