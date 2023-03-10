#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"identity.h"
#include<fstream>
#include"globlefile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<string>
using namespace std;
void initsystem() {
	ofstream ofs(STUDENT_FILE, ios::app);
	ofs.close();
	ofs.open(TEACHER_FILE, ios::app);
	ofs.close();
	ifstream ifs(MANAGER_FILE, ios::in);
	if (!ifs.is_open()) {
		ifs.close();
		ofs.open(MANAGER_FILE, ios::out);
		ofs << "admin 123";
		ofs.close();
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		ofs.open(MANAGER_FILE, ios::out);
		ofs << "admin 123";
		ofs.close();
	}
	else {
		ifs.putback(ch);
		ifs.close();
	}
	ofs.open(ORDER_FILE, ios::app);
	ofs.close();
	ofs.open(COMPUTER_FILE, ios::app);
	ofs.close();
}
void managermenu(identity*person);
void teachermenu(identity *person) {
	teacher* tea = (teacher*)person;
	int select;
	while (true)
	{
		tea->opermenu();
		cin >> select;
		switch (select)
		{case 1://查看所有预约
			tea->showAllOrder();
			break;
		case 2://审核预约
			tea->vaildOrder();
			break;
		case 0:
			cout << "注销成功！欢迎下次使用！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误！请重新输入!"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
void studentmenu(identity*person) {
	
	student* stu = (student*)person;
	int select;
	while (1) {
		person->opermenu();
		cin >> select;
		switch (select)
		{
		case 1://申请预约
			system("cls");
			stu->applyOrder();
			break;
		case 2://查看我的预约
			stu->showMyOrder();
			break;
		case 3://查看所有预约
			stu->showAllOrder();
			break;
		case 4://取消预约
			stu->cancelOrder();
			break;
		case 0://注销登录
			delete stu;
			cout << "您已注销！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入有误！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
void LoginIn(string filename, int type) {
	identity* user = NULL;//父类指针指向子类对象
	ifstream ifs(filename, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		return;
	}
	int id;
	string name;
	string pwd;
	if (type == 1) {//学生身份
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的教职号" << endl;
		cin >> id;
	}
	cout << "请输入你的姓名:" << endl;
	cin >> name;
	cout << "请输入你的密码" << endl;
	cin >> pwd;
	if (type == 1) {
		//学生身份验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && fname == name && fpwd == pwd) {
				cout << "验证通过！" << endl;
				system("pause");
				system("cls");
				user = new student(id, name, pwd);
				studentmenu(user);
				return;
				//
			}
		}
	}
	else if (type == 2) {
		//教师验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && fname == name && fpwd == pwd) {
				cout << "验证通过！" << endl;
				system("pause");
				system("cls");
				user = new teacher(id, name, pwd);
				teachermenu(user);
				return;
				//
			}
		}
	}
	else if (type == 3) {
		//管理员验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && fpwd == pwd) {
				cout << "验证通过！" << endl;
				system("pause");
				system("cls");
				user = new manager(name, pwd);
				managermenu(user);
				return;
			} 
		}
		
	}
	cout << "验证失败！" << endl;
	system("pause");
	system("cls");
}
void managermenu(identity *person) {
	while (1) {
		person->opermenu();
		manager* man =(manager*) person;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://添加账号
			cout << "添加账号" << endl;
			man->addUser();
			break;
		case 2://查看账号
			cout << "查看账号" << endl;
			man->showUser();
			break;
		case 3:
			cout << "查看机房" <<endl;
			man->showComperterRoom();
			break;
		case 4://管理机房
			man->addComputerRoom();
			break;
		case 5://清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
			break;
		case 0://注销登录
			delete man;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		default:
			cout << "输入错误！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}
int main() {
	initsystem();
	cout << endl;
	int select;

	while (1) {
		cout << "   ----------------------欢迎使用机房预约管理系统----------------------\n"
			<< "\t\t\t------------------------\t\t\n"
			<< "\t\t\t|\t          \t|\t\t\n"
			<< "\t\t\t|\t1.学生代表\t|\t\t\n"
			<< "\t\t\t|\t2.老    师\t|\t\t\n"
			<< "\t\t\t|\t3.管 理 员\t|\t\t\n"
			<< "\t\t\t|\t0.退出系统\t|\t\t\n"
			<< "\t\t\t|\t          \t|\t\t\n"
			<< "\t\t\t------------------------\t\t\n";
		cout << "请输入你的选择>>:";
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);

			break;
		case 3:
			LoginIn(MANAGER_FILE, 3);
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误！请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

		return 0;
}