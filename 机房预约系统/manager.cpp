#include "manager.h"
#include"globlefile.h"
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include<fstream>
#include<algorithm>
manager::manager(string name, string pwd)
{
	//��ʼ������Ա
	this->m_name = name;
	this->m_pwd = pwd;
	initVector();
	initcomv();

}

void manager::opermenu()
{
	cout << endl;
	cout << "           -------->>>>>>>��ӭ����Ա��" << this->m_name << "<<<<<<<------\n"
		<< "\t\t\t------------------------\t\t\n"
		<< "\t\t\t|\t          \t|\t\t\n"
		<< "\t\t\t|\t1.����˺�\t|\t\t\n"
		<< "\t\t\t|\t2.�鿴�˺�\t|\t\t\n"
		<< "\t\t\t|\t3.�鿴����\t|\t\t\n"
		<< "\t\t\t|\t4.��ӻ���\t|\t\t\n"
		<< "\t\t\t|\t5.���ԤԼ\t|\t\t\n"
		<< "\t\t\t|\t0.ע����¼\t|\t\t\n"
		<< "\t\t\t|\t          \t|\t\t\n"
		<< "\t\t\t------------------------\t\t\n";
	cout << "���������ѡ��>>:";
}

void manager::addUser()
{
	cout << "��������ӵ��˺�����" << endl;
	cout << "1.ѧ���˺�" << endl;
	cout << "2.��ʦ�˺�" << endl;
	int select = 0;
	int id;
	string filename;
	string name;
	string pwd;
	string errortip;
	cout << ">>>:";
	cin >> select;
	if (select == 1) {
		cout << "����������ѧ�ţ�";
		errortip = "�������ѧ���ظ������������룺";
		filename = STUDENT_FILE;
	}
	else if(select==2){
		cout << "���������Ľ�ְ�ţ�";
		errortip = "������Ľ�ְ���ظ������������룺";
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
	cout << "�����������û�����";
	cin >> name;
	cout << "�������������룺";
	cin >> pwd;

	ofstream ofs(filename, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();
	initVector();
	cout << "��ӳɹ���\n";
	system("pause");
	system("cls");
	return;
}
void printstudent(student &p) {
	cout << "ѧ�ţ�" << p.s_id << "  ������" << p.m_name << "  ���룺" << p.m_pwd << endl;
}
void printteacher(teacher& p) {
	cout << "ְ���ţ�" << p.t_id << "  ������" << p.m_name << "  ���룺" << p.m_pwd << endl;
}
void manager::showUser()
{
	cout << "��������Ҫ�鿴���˺�����" << endl;
	cout << "1.ѧ���˺�" << endl;
	cout << "2.��ʦ�˺�" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		cout << "---------���е�ѧ���˺���Ϣ����---------" << endl;
		for_each(stuv.begin(), stuv.end(), printstudent);
		system("pause");
		system("cls");
	}
	else {
		cout << "---------���еĽ�ʦ�˺���Ϣ����---------" << endl;

		for_each(teav.begin(), teav.end(), printteacher);
		system("pause");
		system("cls");
	}
}
void printcom(computerRoom &com) {
	cout << "�������: " << com.c_id << "  ��λ��" << com.c_cap <<endl;
}
void manager::showComperterRoom()
{
	cout << ">>������Ϣ����>>" << endl;
	for_each(comv.begin(), comv.end(), printcom);
	system("pause");
	system("cls");
}

void manager::addComputerRoom()
{
	int id;
	int cap;
	cout << "������Ҫ��ӵĻ�����:";
	cin >> id;
	cout << "���������������";
	cin >> cap;
	ofstream ofs(COMPUTER_FILE, ios::app);
	ofs << id << " " << cap;
	ofs.close();
	
	cout << "�����ɣ�" << endl;
	initcomv();
	system("pause");
	system("cls");
	return;
}

void manager::cleanFile()
{
	cout << "ȷ��Ҫ�������ԤԼ��" << endl;
	cout << "     1.ȷ��" << endl;
	cout << "     0.ȡ��" << endl;
	cout << "������ѡ��>>:";
	int select;
	cin >> select;
	if (select == 1) {
		ofstream ofs(ORDER_FILE, ios::trunc);
		ofs.close();
		cout << "	�����ɣ�" << endl;
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
		ifstream ifs;//��ʼ��ѧ������
		ifs.open(STUDENT_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "��ʼ����ʧ�ܣ�" << endl;
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
		cout << "ѧ���˺�������" << stuv.size() << endl;
		cout << "��ʦ�˺�������" << teav.size() << endl;;

	}

void manager::initcomv()
{
	comv.clear();
	ifstream ifs(COMPUTER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		ifs.close();
		return;
	}
	computerRoom com;
	while (ifs >> com.c_id && ifs >> com.c_cap) {
		comv.push_back(com);
	}
	cout << "Ŀǰ���û�����" << comv.size()<<"��" << endl;
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



