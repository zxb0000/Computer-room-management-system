#pragma once
class computerRoom {
public:
	computerRoom();
	computerRoom(int id, int cap);
	bool operator==(int id);
	int c_id;//���
	int c_cap;//����
};
