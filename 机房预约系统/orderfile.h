#pragma once
#include<iostream>
#include"globlefile.h"
#include<fstream>
#include<map>
using namespace std;
class orderfile {
public:
	orderfile();
	void updataorderfile();
	int order_size;
	map<int, map<string, string>>orderm; 
};