#pragma once
#include"identity.h"
#include"computerRoom.h"
#include<fstream>
#include"globlefile.h"
#include"orderfile.h"
class student :public identity{
public:
	student();
	virtual void opermenu();//�˵�
	student(int id, string name, string pwd);//���캯��
	void applyOrder();//����ԤԼ
	void showMyOrder();//�鿴ԤԼ
	void showAllOrder();//�鿴����ԤԼ
	void cancelOrder();//ȡ��ԤԼ
	void intitRoom();
	int s_id;//ѧ��
	vector<computerRoom>comv;
};
