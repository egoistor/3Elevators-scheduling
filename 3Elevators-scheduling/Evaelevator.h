#pragma once
class Evaelevator//偶数电梯
{
public:
	int currentFloor; //当前位置
	int run_time;//运行时间
	int goToFloor(int fromfloor, int tofloor, int now_time); //前往楼层
	int stop(int nowtime); //停靠在当前楼层
	int wait(int i, int j);//等待
	void showFloor(int nowtime, int nowfloor);//显示当前所处楼层位置
	int state;//电梯状态（运行状态为1，非运行状态为0）
	Evaelevator();
	~Evaelevator();
};


