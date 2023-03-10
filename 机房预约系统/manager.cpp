#include "manager.h"
#include"globlefile.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<fstream>
#include<algorithm>
manager::manager(string name, string pwd)
{
	//初始化管理员
	this->m_name = name;
	this->m_pwd = pwd;
	initVector();
	initcomv();

}

void manager::opermenu()
{
	cout << endl;
	cout << "           -------->>>>>>>欢迎管理员：" << this->m_name << "<<<<<<<------\n"
		<< "\t\t\t------------------------\t\t\n"
		<< "\t\t\t|\t          \t|\t\t\n"
		<< "\t\t\t|\t1.添加账号\t|\t\t\n"
		<< "\t\t\t|\t2.查看账号\t|\t\t\n"
		<< "\t\t\t|\t3.查看机房\t|\t\t\n"
		<< "\t\t\t|\t4.添加机房\t|\t\t\n"
		<< "\t\t\t|\t5.清空预约\t|\t\t\n"
		<< "\t\t\t|\t0.注销登录\t|\t\t\n"
		<< "\t\t\t|\t          \t|\t\t\n"
		<< "\t\t\t------------------------\t\t\n";
	cout << "请输入你的选择>>:";
}

void manager::addUser()
{
	cout << "请输入添加的账号类型" << endl;
	cout << "1.学生账号" << endl;
	cout << "2.老师账号" << endl;
	int select = 0;
	int id;
	string filename;
	string name;
	string pwd;
	string errortip;
	cout << ">>>:";
	cin >> select;
	if (select == 1) {
		cout << "请输入您的学号：";
		errortip = "您输入的学号重复！请重新输入：";
		filename = STUDENT_FILE;
	}
	else if(select==2){
		cout << "请输入您的教职号：";
		errortip = "您输入的教职号重复！请重新输入：";
		filename = TEACHER_FILE;
	}
	while (1) {
		cin >> id;
		if (checkRepeat(id, select)) {
			cout << errortip ;
		}
		else {
			break;
		}
	}
	cout << "请输入您的用户名：";
	cin >> name;
	cout << "请输入您的密码：";
	cin >> pwd;

	ofstream ofs(filename, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();
	initVector();
	cout << "添加成功！\n";
	system("pause");
	system("cls");
	return;
}
void printstudent(student &p) {
	cout << "学号：" << p.s_id << "  姓名：" << p.m_name << "  密码：" << p.m_pwd << endl;
}
void printteacher(teacher& p) {
	cout << "职工号：" << p.t_id << "  姓名：" << p.m_name << "  密码：" << p.m_pwd << endl;
}
void manager::showUser()
{
	cout << "请输入你要查看的账号类型" << endl;
	cout << "1.学生账号" << endl;
	cout << "2.老师账号" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		cout << "---------所有的学生账号信息如下---------" << endl;
		for_each(stuv.begin(), stuv.end(), printstudent);
		system("pause");
		system("cls");
	}
	else {
		cout << "---------所有的教师账号信息如下---------" << endl;

		for_each(teav.begin(), teav.end(), printteacher);
		system("pause");
		system("cls");
	}
}
void printcom(computerRoom &com) {
	cout << "机房编号: " << com.c_id << "  机位：" << com.c_cap <<endl;
}
void manager::showComperterRoom()
{
	cout << ">>机房信息如下>>" << endl;
	for_each(comv.begin(), comv.end(), printcom);
	system("pause");
	system("cls");
}

void manager::addComputerRoom()
{
	int id;
	int cap;
	cout << "请输入要添加的机房号:";
	cin >> id;
	cout << "请输入机房容量：";
	cin >> cap;
	ofstream ofs(COMPUTER_FILE, ios::app);
	ofs << id << " " << cap;
	ofs.close();
	
	cout << "添加完成！" << endl;
	initcomv();
	system("pause");
	system("cls");
	return;
}

void manager::cleanFile()
{
	cout << "确认要清空所有预约？" << endl;
	cout << "     1.确认" << endl;
	cout << "     0.取消" << endl;
	cout << "请输入选择>>:";
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "	清空完成！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		system("cls");
		return;
	}
}

void manager::initVector()
	{
		this->stuv.clear();
		this->teav.clear();
		student stu;
		teacher tea;
		ifstream ifs;//初始化学生容器
		ifs.open(STUDENT_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "初始化打开失败！" << endl;
			return;
		}
		while (ifs >> stu.s_id && ifs >> stu.m_name && ifs >> stu.m_pwd) {
			stuv.push_back(stu);
		}
		ifs.close();
		ifs.open(TEACHER_FILE, ios::in);
		while (ifs >> tea.t_id && ifs >> tea.m_name && ifs >> tea.m_pwd) {
			teav.push_back(tea);
		}
		ifs.close();
		cout << "学生账号数量：" << stuv.size() << endl;
		cout << "教师账号数量：" << teav.size() << endl;;

	}

void manager::initcomv()
{
	comv.clear();
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败！" << endl;
		ifs.close();
		return;
	}
	computerRoom com;
	while (ifs >> com.c_id && ifs >> com.c_cap) {
		comv.push_back(com);
	}
	cout << "目前可用机房：" << comv.size()<<"间" << endl;
}

bool manager::checkRepeat(int id,int type)
{
	if (type == 1) {
		for (vector<student>::iterator it = stuv.begin(); it != stuv.end(); it++) {
			if (it->s_id == id) {
				return true;
			}
		}
	}
	else if(type==2){
		for (vector<teacher>::iterator it = teav.begin(); it != teav.end(); it++) {
			if (it->t_id == id) {
				return true;
			}
		}
	}
	return false;
}



