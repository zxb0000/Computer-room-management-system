#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class identity {//��ݳ������
public:
	virtual void opermenu() = 0;//���麯��
	string m_name;
	string m_pwd;
};