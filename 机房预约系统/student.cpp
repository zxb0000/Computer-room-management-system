#include "student.h"
student::student()
{
	//intitRoom();
}

void student::opermenu()
{
	cout << endl;
	cout << "		-------->>>>>>>��ӭѧ������" << this->m_name << "<<<<<<<------\n"
		<< "\t\t\t------------------------\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t|\t1.����ԤԼ    \t|\t\t\n"
		<< "\t\t\t|\t2.�鿴�ҵ�ԤԼ\t|\t\t\n"
		<< "\t\t\t|\t3.�鿴����ԤԼ\t|\t\t\n"
		<< "\t\t\t|\t4.ȡ��ԤԼ    \t|\t\t\n"
		<< "\t\t\t|\t0.ע����¼    \t|\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t------------------------\t\t\n";
	cout << "���������ѡ��>>:";
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
	cout << "��ע�⣡����ÿ��һ�����忪�ţ�	" << endl;
	cout << "��ѡ��ԤԼ��ʱ��" << endl;
	cout << "	1.��һ" << endl;
	cout << "	2.�ܶ�" << endl;
	cout << "	3.����" << endl;
	cout << "	4.����" << endl;
	cout << "	5.����" << endl;
	int day;
	while (1) {
		cout << "�������ţ�";
		cin >> day;
		if (day >= 1 && day <= 5) {
			break;
		}
		cout << "������������" << endl;
	}
	int time;
	cout << "��ѡ��ԤԼ��ʱ���" << endl;
	cout << "	1.����" << endl;
	cout << "	2.����" << endl;
	while (1) {
		cout << "�������ţ�";
		cin >> time;
		if (time >= 1 && time <= 2) {
			break;
		}
		cout << "������������" << endl;
	}
	int room ;
	cout << "��ѡ��ԤԼ�Ļ���" << endl;
	for (int i = 0; i < comv.size(); i++) {
		cout <<"������ţ�" << comv[i].c_id << " ������λ��" << comv[i].c_cap<<endl;
	}
	
	while (1) {
		cout << "�����������ţ�";
		cin >> room;
		vector<computerRoom>::iterator it = find(comv.begin(), comv.end(), room);
		if ( it!=comv.end()) {
			break;
		}
		cout << "������������" << endl;
	}
	cout << "ԤԼ�ɹ������������!" << endl;
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
			cout << "ԤԼʱ��: ��" << s.orderm[i]["date"] << " ";
			cout << (s.orderm[i]["time"]=="1"?"����":"����") << " ";
			cout <<  "ԤԼ���� " << s.orderm[i]["roomid"] << "��  ";
			string status = "����״̬��";
			if (s.orderm[i]["status"] == "1") {
				status += "�����";
			}
			else if (s.orderm[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (s.orderm[i]["status"] == "-1") {
				status += "ԤԼʧ��";
			}
			else if (s.orderm[i]["status"] == "0") {
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
			
		}
	}
	if (s.order_size == 0||flag==0) {
		cout << "��ԤԼ��¼" << endl;
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < s.orderm.size(); i++) {
		cout << i + 1 << ". ";
			cout << "ԤԼʱ��: ��" << s.orderm[i]["date"] << " ";
			cout << (s.orderm[i]["time"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��ID��" << s.orderm[i]["stuid"] << " "
				<< "������" << s.orderm[i]["stuName"] << " "
				<< "ԤԼ���� " << s.orderm[i]["roomid"] << "��  ";
			string status = "����״̬��";
			if (s.orderm[i]["status"] == "1") {
				status += "�����";
			}
			else if (s.orderm[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (s.orderm[i]["status"] == "-1") {
				status += "ԤԼʧ��";
			}
			else if(s.orderm[i]["status"] == "0") {
				status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "ע�⣺ֻ��ȡ������к�ԤԼ�ɹ���ԤԼ" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < s.orderm.size(); i++) {
		if (atoi(s.orderm[i]["stuid"].c_str()) == this->s_id) {
			if (atoi(s.orderm[i]["status"].c_str()) == 0
				|| atoi(s.orderm[i]["status"].c_str()) == 1) {
				cout<<index++<<". ";
				v.push_back(i);
				cout << "ԤԼʱ��: ��" << s.orderm[i]["date"] << " ";
				cout << (s.orderm[i]["time"] == "1" ? "����" : "����") << " ";
				cout << "ѧ��ID��" << s.orderm[i]["stuid"] << " "
					<< "������" << s.orderm[i]["stuName"] << " "
					<< "ԤԼ���� " << s.orderm[i]["roomid"] << "��  ";
				string status = "����״̬��";
				if (s.orderm[i]["status"] == "1") {
					status += "�����";
				}
				else if (s.orderm[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				else if (s.orderm[i]["status"] == "-1") {
					status += "ԤԼʧ��";
				}
				else if (s.orderm[i]["status"] == "0") {
					status += "ԤԼ��ȡ��";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������Ҫȡ�������룡(ע�⣺��������0����ȡ������)" << endl;
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
			cout << "ȡ��ԤԼ�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "��������������룺";
	}
}

void student::intitRoom()
{
	comv.clear();
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "������Ϣ��ʼ��ʧ�ܣ�" << endl;
		return;
	}
	computerRoom com;
	while (ifs >> com.c_id && ifs >> com.c_cap) {
		comv.push_back(com);
	}
	ifs.close();
	//cout << comv.size() << endl;;
}
