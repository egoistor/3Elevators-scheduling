#pragma once
class Evaelevator//ż������
{
public:
	int currentFloor; //��ǰλ��
	int run_time;//����ʱ��
	int goToFloor(int fromfloor, int tofloor, int now_time); //ǰ��¥��
	int stop(int nowtime); //ͣ���ڵ�ǰ¥��
	int wait(int i, int j);//�ȴ�
	void showFloor(int nowtime, int nowfloor);//��ʾ��ǰ����¥��λ��
	int state;//����״̬������״̬Ϊ1��������״̬Ϊ0��
	Evaelevator();
	~Evaelevator();
};


