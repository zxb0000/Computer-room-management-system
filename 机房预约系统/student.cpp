#include "student.h"
student::student()
{
	//intitRoom();
}

void student::opermenu()
{
	cout << endl;
	cout << "		-------->>>>>>>欢迎学生代表：" << this->m_name << "<<<<<<<------\n"
		<< "\t\t\t------------------------\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t|\t1.申请预约    \t|\t\t\n"
		<< "\t\t\t|\t2.查看我的预约\t|\t\t\n"
		<< "\t\t\t|\t3.查看所有预约\t|\t\t\n"
		<< "\t\t\t|\t4.取消预约    \t|\t\t\n"
		<< "\t\t\t|\t0.注销登录    \t|\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t------------------------\t\t\n";
	cout << "请输入你的选择>>:";
}

student::student(int id, string name, string pwd)
{
	this->s_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
	intitRoom();

}

void student::applyOrder()
{
	cout << "请注意！机房每周一至周五开放！	" << endl;
	cout << "请选择预约的时间" << endl;
	cout << "	1.周一" << endl;
	cout << "	2.周二" << endl;
	cout << "	3.周三" << endl;
	cout << "	4.周四" << endl;
	cout << "	5.周五" << endl;
	int day;
	while (1) {
		cout << "请输入编号：";
		cin >> day;
		if (day >= 1 && day <= 5) {
			break;
		}
		cout << "您的输入有误！" << endl;
	}
	int time;
	cout << "请选择预约的时间段" << endl;
	cout << "	1.上午" << endl;
	cout << "	2.下午" << endl;
	while (1) {
		cout << "请输入编号：";
		cin >> time;
		if (time >= 1 && time <= 2) {
			break;
		}
		cout << "您的输入有误！" << endl;
	}
	int room ;
	cout << "请选择预约的机房" << endl;
	for (int i = 0; i < comv.size(); i++) {
		cout <<"机房编号：" << comv[i].c_id << " 房间座位：" << comv[i].c_cap<<endl;
	}
	
	while (1) {
		cout << "请输入机房编号：";
		cin >> room;
		vector<computerRoom>::iterator it = find(comv.begin(), comv.end(), room);
		if ( it!=comv.end()) {
			break;
		}
		cout << "您的输入有误！" << endl;
	}
	cout << "预约成功！正在审核中!" << endl;
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << day << " "
		<< "time:" << time << " "
		<< "stuid:" << this->s_id << " "
		<< "stuName:" << this->m_name<<" "
		<< "roomid:" << room << " "
		<< "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");

}

void student::showMyOrder()
{
	orderfile s;
	
	int flag = 0;
	for (int i = 0; i < s.orderm.size(); i++) {
		if (atoi(s.orderm[i]["stuid"].c_str()) == this->s_id) {
			flag = 1;
			cout << "预约时间: 周" << s.orderm[i]["date"] << " ";
			cout << (s.orderm[i]["time"]=="1"?"上午":"下午") << " ";
			cout <<  "预约机房 " << s.orderm[i]["roomid"] << "号  ";
			string status = "申请状态：";
			if (s.orderm[i]["status"] == "1") {
				status += "审核中";
			}
			else if (s.orderm[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (s.orderm[i]["status"] == "-1") {
				status += "预约失败";
			}
			else if (s.orderm[i]["status"] == "0") {
				status += "预约已取消";
			}
			cout << status << endl;
			
		}
	}
	if (s.order_size == 0||flag==0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
	return;
}

void student::showAllOrder()
{
	orderfile s;
	if (s.order_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < s.orderm.size(); i++) {
		cout << i + 1 << ". ";
			cout << "预约时间: 周" << s.orderm[i]["date"] << " ";
			cout << (s.orderm[i]["time"] == "1" ? "上午" : "下午") << " ";
			cout << "学生ID：" << s.orderm[i]["stuid"] << " "
				<< "姓名：" << s.orderm[i]["stuName"] << " "
				<< "预约机房 " << s.orderm[i]["roomid"] << "号  ";
			string status = "申请状态：";
			if (s.orderm[i]["status"] == "1") {
				status += "审核中";
			}
			else if (s.orderm[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (s.orderm[i]["status"] == "-1") {
				status += "预约失败";
			}
			else if(s.orderm[i]["status"] == "0") {
				status += "预约已取消";
			}
			cout << status << endl;
	}
	system("pause");
	system("cls");
	return;
}

void student::cancelOrder()
{
	orderfile s;
	if (s.order_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "注意：只能取消审核中和预约成功的预约" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < s.orderm.size(); i++) {
		if (atoi(s.orderm[i]["stuid"].c_str()) == this->s_id) {
			if (atoi(s.orderm[i]["status"].c_str()) == 0
				|| atoi(s.orderm[i]["status"].c_str()) == 1) {
				cout<<index++<<". ";
				v.push_back(i);
				cout << "预约时间: 周" << s.orderm[i]["date"] << " ";
				cout << (s.orderm[i]["time"] == "1" ? "上午" : "下午") << " ";
				cout << "学生ID：" << s.orderm[i]["stuid"] << " "
					<< "姓名：" << s.orderm[i]["stuName"] << " "
					<< "预约机房 " << s.orderm[i]["roomid"] << "号  ";
				string status = "申请状态：";
				if (s.orderm[i]["status"] == "1") {
					status += "审核中";
				}
				else if (s.orderm[i]["status"] == "2") {
					status += "预约成功";
				}
				else if (s.orderm[i]["status"] == "-1") {
					status += "预约失败";
				}
				else if (s.orderm[i]["status"] == "0") {
					status += "预约已取消";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入要取消的申请！(注意：可以输入0返回取消操作)" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select == 0) {
			system("cls");
			return;
		}
		else if (select > 0 && select <= v.size()) {
			s.orderm[v[select-1]]["status"] = "0";
			s.updataorderfile();
			cout << "取消预约成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "输入错误！重新输入：";
	}
}

void student::intitRoom()
{
	comv.clear();
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "房间信息初始化失败！" << endl;
		return;
	}
	computerRoom com;
	while (ifs >> com.c_id && ifs >> com.c_cap) {
		comv.push_back(com);
	}
	ifs.close();
	//cout << comv.size() << endl;;
}
