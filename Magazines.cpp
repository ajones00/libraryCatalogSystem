#include "Magazines.h"

Magazines::Magazines(int idnum, string titlename, bool itemstatus, int issue):LibraryItem(idnum, titlename, itemstatus, LibraryItemType::Magazines) {
	issue_number = issue;
}

int Magazines::getIssue() const {
	return issue_number;
};

void Magazines::printData() const {
	LibraryItem::printData();
	cout << "Issue: " << getIssue() << endl;
}