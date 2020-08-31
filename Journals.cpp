#include "Journals.h"

Journals::Journals(int idnum, string titlename, bool itemstatus, int vol) :LibraryItem(idnum, titlename, itemstatus, LibraryItemType::Journals) {
	volume = vol;
}

int Journals::getVolume() const {
	return volume;
};

void Journals::printData() const {
	LibraryItem::printData();
	cout << "Vol: " << getVolume() << endl;
}