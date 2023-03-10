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
	cout << "		-------->>>>>>>��ӭ��ʦ��" << this->m_name << "��¼��<<<<<<<------\n"
		<< "\t\t\t------------------------\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t|\t1.�鿴����ԤԼ\t|\t\t\n"
		<< "\t\t\t|\t2.���ԤԼ    \t|\t\t\n"
		<< "\t\t\t|\t0.ע����¼    \t|\t\t\n"
		<< "\t\t\t|\t              \t|\t\t\n"
		<< "\t\t\t------------------------\t\t\n";
	cout << "���������ѡ��>>:";
}

void teacher::showAllOrder()
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
		else if (s.orderm[i]["status"] == "0") {
			status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵ļ�¼�б����£�" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.orderm.size(); i++) {
		if (of.orderm[i]["status"] == "1") {
			v.push_back(i);
			cout << index++ << ". ";
			cout << "ԤԼʱ��: ��" << of.orderm[i]["date"] << " ";
			cout << (of.orderm[i]["time"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��ID��" << of.orderm[i]["stuid"] << " "
				<< "������" << of.orderm[i]["stuName"] << " "
				<< "ԤԼ���� " << of.orderm[i]["roomid"] << "��  ";
			string status = "����״̬��";
			if (of.orderm[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.orderm[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.orderm[i]["status"] == "-1") {
				status += "ԤԼʧ��";
			}
			else if (of.orderm[i]["status"] == "0") {
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	int select;
	cout << "������Ҫ��˵ļ�¼���!��ע�⣺����0����ȡ��������"<<endl;
	while (true)
	{
		cout << "�������ţ�";
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			cout << "������Ҫ���еĴ�����ע�⣺����0����ȡ��������" << endl;
			cout << "   1.ͨ��" << endl;
			cout << "   2.�ܾ�" << endl;
			int ret;
			while (true)
			{
				cout << "�����룺";
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
					cout << "�����ɹ��������ϣ�" << endl;
					system("pause");
					system("cls");
					return;
				}
				cout << "����������������룡" << endl;
			}
		}
		else {
			cout << "������������������!" << endl;;
		}

	}
	system("pause");
	system("cls");
	return;
	
}
