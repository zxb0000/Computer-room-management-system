#pragma once
#include"identity.h"
#include"orderfile.h"
class teacher :public identity{
public:
	teacher();
	teacher(int id, string name, string pwd);
	virtual void opermenu();
	void showAllOrder();
	void vaildOrder();
	int t_id;
};
