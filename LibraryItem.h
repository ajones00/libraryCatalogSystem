#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


enum class LibraryItemType {Unknown, Books, Journals, Magazines};

class LibraryItem
{
public:
	LibraryItem(int idnum, string titleName, bool itemStatus, LibraryItemType type);
	void setData(int idnum, string titleName, bool itemStatus);
	void setID(int idnum);
	void setName(string titleName);
	void setStatus(bool itemStatus);
	int getID() const;
	string getName() const;
	bool getStatus() const;
	virtual void printData() const;
	LibraryItemType type;


private:
	int id;
	string name;
	bool status;
};
#endif // !LIBRARYITEM_H