#include "teacher.h"
teacher::teacher()
{
}

teacher::teacher(int id, string name, string pwd)
{
	this->t_id = id;
	this->m_name = name;
	this->m_pwd = pwd;
}

void teacher::opermenu()
{
	cout << endl;
	cout << "		-------->>>>>>>欢迎教师：" << this->m_name << "登录！<<<<<<<------\n"
		<< "\t\t\t------------------------\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t|\t1.查看所有预约\t|\t\t\n"
		<< "\t\t\t|\t2.审核预约    \t|\t\t\n"
		<< "\t\t\t|\t0.注销登录    \t|\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t------------------------\t\t\n";
	cout << "请输入你的选择>>:";
}

void teacher::showAllOrder()
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
		else if (s.orderm[i]["status"] == "0") {
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
	return;
}

void teacher::vaildOrder()
{
	orderfile of;
	if (of.orderm.size() == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的记录列表如下：" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.orderm.size(); i++) {
		if (of.orderm[i]["status"] == "1") {
			v.push_back(i);
			cout << index++ << ". ";
			cout << "预约时间: 周" << of.orderm[i]["date"] << " ";
			cout << (of.orderm[i]["time"] == "1" ? "上午" : "下午") << " ";
			cout << "学生ID：" << of.orderm[i]["stuid"] << " "
				<< "姓名：" << of.orderm[i]["stuName"] << " "
				<< "预约机房 " << of.orderm[i]["roomid"] << "号  ";
			string status = "申请状态：";
			if (of.orderm[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.orderm[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.orderm[i]["status"] == "-1") {
				status += "预约失败";
			}
			else if (of.orderm[i]["status"] == "0") {
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	int select;
	cout << "请输入要审核的记录编号!（注意：输入0返回取消操作）"<<endl;
	while (true)
	{
		cout << "请输入编号：";
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			cout << "请输入要进行的处理！（注意：输入0返回取消操作）" << endl;
			cout << "   1.通过" << endl;
			cout << "   2.拒绝" << endl;
			int ret;
			while (true)
			{
				cout << "请输入：";
				cin >> ret;
				if (ret >= 0 && ret <= 2) {
					if (ret == 0) {
						break;
					}
					if (ret == 1) {
						of.orderm[v[select - 1]]["status"] = "2";
					}
					if (ret == 2) {
						of.orderm[v[select - 1]]["status"] = "-1";
					}
					of.updataorderfile();
					cout << "操作成功！审核完毕！" << endl;
					system("pause");
					system("cls");
					return;
				}
				cout << "输入错误！请重新输入！" << endl;
			}
		}
		else {
			cout << "输入有误！请重新输入!" << endl;;
		}

	}
	system("pause");
	system("cls");
	return;
	
}
