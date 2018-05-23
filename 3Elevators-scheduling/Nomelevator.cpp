#include "Nomelevator.h"
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;

int Nomelevator::goToFloor(int fromfloor, int tofloor, int now_time)
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
int Nomelevator::stop(int nowtime)
{
	nowtime++;
	return nowtime;
}
int Nomelevator::wait(int i, int j)
{
	return 0;
}
void Nomelevator::showFloor(int nowtime, int nowfloor)
{
	ofstream outfile1("./output1.txt", ios::app);
	outfile1 << nowtime << " " << nowfloor << endl;
	outfile1.close();
	//cout<< nowtime <<  nowfloor << endl;
}
Nomelevator::Nomelevator()
{
	currentFloor = 1;
	run_time = 0;
	state = 0;
}


Nomelevator::~Nomelevator()
{
}

