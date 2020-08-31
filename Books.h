#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <string>
#include "LibraryItem.h"

class Books : public LibraryItem
{
public:
	Books(int idnum, string titlename, bool itemstatus, string author);
	string getAuthorName() const;
	void printData() const;
	

private:
	string author_name;

};

#endif // !BOOKS_H
