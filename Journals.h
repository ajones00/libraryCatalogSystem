#ifndef JOURNALS_H
#define JOURNALS_H
#include <iostream>
#include <string>
#include "LibraryItem.h"


class Journals : public LibraryItem
{
public:
	Journals(int idnum, string titlename, bool itemstatus, int vol);
	int getVolume() const;
	void printData() const;

private:
	int volume;

};

#endif // !JOURNALS_H