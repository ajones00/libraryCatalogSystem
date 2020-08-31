#ifndef MAGAZINES_H
#define MAGAZINES_H
#include <iostream>
#include <string>
#include "LibraryItem.h"

class Magazines : public LibraryItem
{
public:
	Magazines(int idnum, string titlename, bool itemstatus, int issue);
	int getIssue() const;
	void printData() const;

private:
	int issue_number;

};

#endif // !MAGAZINES_H
