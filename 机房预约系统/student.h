#pragma once
#include"identity.h"
#include"computerRoom.h"
#include<fstream>
#include"globlefile.h"
#include"orderfile.h"
class student :public identity{
public:
	student();
	virtual void opermenu();//菜单
	student(int id, string name, string pwd);//构造函数
	void applyOrder();//申请预约
	void showMyOrder();//查看预约
	void showAllOrder();//查看所有预约
	void cancelOrder();//取消预约
	void intitRoom();
	int s_id;//学号
	vector<computerRoom>comv;
};
