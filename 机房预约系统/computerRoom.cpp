#include "computerRoom.h"

computerRoom::computerRoom()
{
}

computerRoom::computerRoom(int id, int cap)
{
	this->c_cap = cap;
	this->c_id = id;
}

bool computerRoom::operator==(int id)
{
	if (this->c_id == id) {
		return true;
	}
	return false;
}
