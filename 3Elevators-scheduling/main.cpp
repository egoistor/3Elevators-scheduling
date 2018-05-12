#include"Nomelevator.h"
#include"Oddelevator.h"
#include"Evaelevator.h"
#include"custom.h"
#include<fstream>
#include<cmath>
#include<stdlib.h>
#include <algorithm> 
#include<iostream>
using namespace std;
int Wait(int formtime, int totime)//等待
{
	return totime;
}
int Min(int time1, int time2, int time3)//取小函数
{
	int min = time1;
	min = min < time2 ? min : time2;
	min = min < time3 ? min : time3;
	return min;
}
int main()
{
	Nomelevator norelevator;
	Evaelevator evaelevator;
	Oddelevator oddelevator;
	int nor_now_floor = 1;//普通电梯的所在层数
	int eva_now_floor=1;//偶数电梯所在层数
	int odd_now_floor=1;//奇数电梯的所在层数
	ifstream infile("./input.txt");
	int n;
	infile >> n;
	//cin >> n;
	custom cus[1000];
	int i;
	for (i = 0; i < n; i++)
	{	infile >> cus[i].request_time;
		infile >> cus[i].from_floor;
		infile >> cus[i].to_floor;
		//cin>> cus[i].request_time;
		//cin>> cus[i].from_floor;
		//cin>> cus[i].to_floor;
	}
	infile.close();
	int time = cus[0].request_time;
	//先接送第一位乘客
	if (cus[0].to_floor % 2 == 0)
	{
		eva_now_floor = evaelevator.goToFloor(eva_now_floor, cus[i].from_floor,time);
		eva_now_floor = evaelevator.goToFloor(eva_now_floor, cus[i].to_floor, time);
	}

	else 
	{
		odd_now_floor = oddelevator.goToFloor(odd_now_floor , cus[i].from_floor, time);
		odd_now_floor = oddelevator.goToFloor(odd_now_floor, cus[i].to_floor, time);
	}
		
	for (i = 1; i < n; i++)//开始第二位至n位
	{
		if (time<cus[i].request_time)
		time = Wait(time, cus[i].request_time);
		if (time >= evaelevator.run_time&&cus[i].from_floor % 2 == 0 && cus[i].to_floor % 2 == 0)//如果满足偶数电梯，调用偶数电梯
		{
			eva_now_floor = (evaelevator.goToFloor(eva_now_floor, cus[i].from_floor, time));
			eva_now_floor = (evaelevator.goToFloor(eva_now_floor, cus[i].to_floor, time));
		}
		else if (time >= oddelevator.run_time&&cus[i].from_floor % 2 == 1 && cus[i].to_floor % 2 == 1)//如果满足奇数电梯，调用奇数电梯
		{
			odd_now_floor = (oddelevator.goToFloor(odd_now_floor, cus[i].from_floor, time));
			odd_now_floor = (oddelevator.goToFloor(odd_now_floor, cus[i].to_floor, time));
		}
		else if (time >= norelevator.run_time)//如果满足普通电梯
		{
			nor_now_floor = (norelevator.goToFloor(nor_now_floor, cus[i].from_floor, time));
			nor_now_floor = (norelevator.goToFloor(nor_now_floor, cus[i].to_floor, time));
		}
		else {
			time = Min(evaelevator.run_time, oddelevator.run_time, norelevator.run_time);//如果都不满足，进入等待
			i--;//要保证当前乘客能被接送，计数减一
		}
	}
	return 0;
}
