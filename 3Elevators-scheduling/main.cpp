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
int Wait(int formtime, int totime)//�ȴ�
{
	return totime;
}
int Min(int time1, int time2, int time3)//ȡС����
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
	int nor_now_floor = 1;//��ͨ���ݵ����ڲ���
	int eva_now_floor=1;//ż���������ڲ���
	int odd_now_floor=1;//�������ݵ����ڲ���
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
	//�Ƚ��͵�һλ�˿�
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
		
	for (i = 1; i < n; i++)//��ʼ�ڶ�λ��nλ
	{
		if (time<cus[i].request_time)
		time = Wait(time, cus[i].request_time);
		if (time >= evaelevator.run_time&&cus[i].from_floor % 2 == 0 && cus[i].to_floor % 2 == 0)//�������ż�����ݣ�����ż������
		{
			eva_now_floor = (evaelevator.goToFloor(eva_now_floor, cus[i].from_floor, time));
			eva_now_floor = (evaelevator.goToFloor(eva_now_floor, cus[i].to_floor, time));
		}
		else if (time >= oddelevator.run_time&&cus[i].from_floor % 2 == 1 && cus[i].to_floor % 2 == 1)//��������������ݣ�������������
		{
			odd_now_floor = (oddelevator.goToFloor(odd_now_floor, cus[i].from_floor, time));
			odd_now_floor = (oddelevator.goToFloor(odd_now_floor, cus[i].to_floor, time));
		}
		else if (time >= norelevator.run_time)//���������ͨ����
		{
			nor_now_floor = (norelevator.goToFloor(nor_now_floor, cus[i].from_floor, time));
			nor_now_floor = (norelevator.goToFloor(nor_now_floor, cus[i].to_floor, time));
		}
		else {
			time = Min(evaelevator.run_time, oddelevator.run_time, norelevator.run_time);//����������㣬����ȴ�
			i--;//Ҫ��֤��ǰ�˿��ܱ����ͣ�������һ
		}
	}
	return 0;
}
