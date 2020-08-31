#include "Books.h"

Books::Books(int idnum, string titlename, bool itemstatus, string author):LibraryItem(idnum, titlename, itemstatus, LibraryItemType::Books) {
	author_name = author;
}

string Books::getAuthorName() const {
	return this->author_name;
};

void Books::printData() const {
	LibraryItem::printData();
	cout << "Author: " << Books::getAuthorName() << endl;
}
