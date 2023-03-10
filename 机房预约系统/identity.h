#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class identity {//身份抽象基类
public:
	virtual void opermenu() = 0;//纯虚函数
	string m_name;
	string m_pwd;
};