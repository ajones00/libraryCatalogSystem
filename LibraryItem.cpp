#include "LibraryItem.h"
using namespace std;

LibraryItem::LibraryItem(int idnum, string titleName, bool itemStatus, LibraryItemType type) :type(type) {
	setData(idnum, titleName, itemStatus);
}

void LibraryItem::setData(int idnum, string titleName, bool itemStatus) {
	setID(idnum);
	setName(titleName);
	setStatus(itemStatus);
}

void LibraryItem::setID(int idnum) {
	id = idnum;
}

void LibraryItem::setName(string titleName) {
	name = titleName;
}

void LibraryItem::setStatus(bool itemStatus) {
	status = itemStatus;
}

int LibraryItem::getID() const {
	return id;
}

string LibraryItem::getName() const {
	return name;
}

bool LibraryItem::getStatus() const {
	return status;
}


void LibraryItem::printData() const {
	cout << "ID: " << getID() << "	Title: " << getName() << "	Checked in: ";
	if (getStatus() == true) {
		cout << "Yes ";
	}
	else {
		cout << "No ";
	}
}

