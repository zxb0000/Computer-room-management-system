#pragma once
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
class manager :public identity{
public:
	manager();
	manager(string name, string pwd);
	virtual void opermenu();
	void addUser();
	void showUser();
	void showComperterRoom();
	void addComputerRoom();
	void cleanFile();
	void initVector();
	void initcomv();
	bool checkRepeat(int id,int type);
	vector<student>stuv;
	vector<teacher>teav;
	vector<computerRoom>comv;
};
