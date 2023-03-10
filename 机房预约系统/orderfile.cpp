#include "orderfile.h"
#include<string>
pair<string, string> datacut(string &data)throw(string) {
	string key;
	string value;
	int pos=data.find(":");
	if (pos != -1) {
		key = data.substr(0, pos);
		value = data.substr(pos + 1, data.size() - pos - 1);
		return make_pair(key, value);
	}
	throw"错误!";

}
orderfile::orderfile()
{
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "读取预约信息失败！" << endl;
		ifs.close();
		return;
	}
	string date;
	string time;
	string stuid;
	string stuName;
	string roomid;
	string status;
	this->order_size = 0;
	while (ifs>>date&&ifs>>time&&ifs>>stuid&&ifs>>stuName&&ifs>>roomid&&ifs>>status)
	{
		/*cout << date << endl;
		cout << time << endl;
		cout << stuid << endl;
		cout << stuName << endl;
		cout << roomid << endl;
		cout << status << endl;
		cout << endl;*/
		string key;
		string value;
		map<string, string>m;
		m.insert(datacut(date));
		m.insert(datacut(time));
		m.insert(datacut(stuid));
		m.insert(datacut(stuName));
		m.insert(datacut(roomid));
		m.insert(datacut(status));
		this->orderm.insert(make_pair(this->order_size++, m)); 
	}
	ifs.close();
	/*for (map<int, map<string, string>>::iterator it = orderm.begin(); it != orderm.end(); it++) {
		cout << it->first << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
			cout << mit->first << ":" << mit->second<<" ";
		}
		cout << endl;
	}*/
}

void orderfile::updataorderfile()
{
	if (this->order_size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->order_size; i++) {
		ofs << "date:" << orderm[i]["date"] << " "
			<< "time:" << orderm[i]["time"] << " "
			<< "stuid:" << orderm[i]["stuid"] << " "
			<< "stuName:" << orderm[i]["stuName"] << " "
			<< "roomid:" << orderm[i]["roomid"] << " "
			<< "status:" << orderm[i]["status"] << endl;
	}
	ofs.close();

}
