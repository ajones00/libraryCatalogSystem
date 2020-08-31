#include "LibraryItem.h"
#include "Books.h"
#include "Journals.h"
#include "Magazines.h"
#include <memory>
#include <sstream>

void displayChoices() {
	cout << "1. Search Catalog" << endl;
	cout << "2. Check out item" << endl;
	cout << "3. Return" << endl;
	cout << "4. Add a new item" << endl;
	cout << "5. Exit" << endl;
}

string getInput(string prompt, const vector<string>& validOptions = {})
{
	string input = string();
	while (true) {
		cout << prompt << endl;
		cin >> input;

		if (validOptions.size()) {
			if (find(validOptions.begin(), validOptions.end(), input) == validOptions.end())
			{
				cout << "Invalid input, please try again" << endl;
			}
			else break;
		}
		else break;
	}
	return input;
}

void searchCatalog(vector<LibraryItem*>& libraryelements) {

	string searchTerm;
	string userInput;
	char base[50];
	bool found = false;

	userInput = getInput("would you like to see a list of certain library items?", { "yes", "no" });

	if (userInput == "no") {
		searchTerm = getInput("Please enter the title of the item you are looking for: ");
		for (int i = 0; i < libraryelements.size(); i++) {
			if (searchTerm == libraryelements[i]->getName()) {
				libraryelements[i]->printData();
				found = true;
				break;
			}
			else {
				found = false;
			}
		}
		if (!found) {
			cout << "Item not found.\n";
		}
	}
	else if (userInput == "yes") {
		string userInput2 = getInput("Which library item would you like to see: books, journals, or magazines?", { "books", "journals", "magazines" });

		if (userInput2 == "books") {
			for (LibraryItem* item : libraryelements) {
				if (item->type == LibraryItemType::Books) {
					item->printData();
				}
			}
			cout << endl;
		}
		else if (userInput2 == "journals") {
			for (LibraryItem* item : libraryelements) {
				if (item->type == LibraryItemType::Journals) {
					item->printData();
				}
			}
			cout << endl;
		}
		else if (userInput2 == "magazines") {
			for (LibraryItem* item : libraryelements) {
				if (item->type == LibraryItemType::Magazines) {
					item->printData();
				}
			}
			cout << endl;
		}
	}
}

void checkOut(vector<LibraryItem*>& libraryelements) {
	char userInput[50];
	bool found = false;
	cout << "Enter the title of the item you want to check out: ";
	cin.getline(userInput, 50);
	while (!found) {
		for (int i = 0; i < libraryelements.size();){
			if (userInput == libraryelements[i]->getName() && libraryelements[i]->getStatus() == true) {
				libraryelements[i]->setStatus(false);
				cout << userInput << " has been found, checking out item." << endl;
				found = true;
				break;
			}
			else if (userInput == libraryelements[i]->getName() && libraryelements[i]->getStatus() == false) {
				cout << "This item is already checked out." << endl;
				found = true;
				break;
			}
			else {
				i++;
			}
		}
		if (!found) {
			cout << userInput << " does not exist." << endl;
			return;
		}
	}
}

void returnItem(vector<LibraryItem*>& libraryelements) {
	char userInput[50];
	bool found = false;
	cout << "Enter the title of the item you want to return: ";
	cin.getline(userInput, 50);
	while (!found) {
		for (int i = 0; i < libraryelements.size();) {
			if (userInput == libraryelements[i]->getName() && libraryelements[i]->getStatus() == false) {
				libraryelements[i]->setStatus(true);
				cout << userInput << " has been found, returning item." << endl;
				found = true;
				break;
			}
			else if (userInput == libraryelements[i]->getName() && libraryelements[i]->getStatus() == true) {
				cout << "This item has already been returned." << endl;
				found = true;
				break;
			}
			else {
				found = false;
				i++;
			}
		}
		if (!found) {
			cout << userInput << " does not exist." << endl;
			return;
		}
	}
}

void addItem(vector<LibraryItem*> &libraryelements) {
	int idNumber;
	int num1;
	char itemTitle[50];
	char itemAuthor[50];

	string userInput = getInput("Enter the type of item you would like to add to the library: book, journal, or magazine?", { "book","journal","magazine" });

	if (userInput == "book") {
		cout << "Please enter the ID number: ";
		cin >> idNumber; 
		cin.ignore();
		cout << "\nPlease enter the book title: ";
		cin.getline(itemTitle, 50 );
		cin.ignore();
		cout << "\nPlease enter the name of the book's author: ";
		cin.getline(itemAuthor, 50);
		cin.ignore();
		libraryelements.push_back(new Books(idNumber, itemTitle, true, itemAuthor));
	}
	else if (userInput == "journal") {
		cout << "Please enter the ID number: ";
		cin >> idNumber;
		cin.ignore();
		cout << "\nPlease enter the journal title: ";
		cin.getline(itemTitle, 50);
		cin.ignore();
		cout << "\nPlease enter the journal volume: ";
		cin >> num1;
		cin.ignore();
		libraryelements.push_back(new Journals(idNumber, itemTitle, true, num1));
	}
	else if (userInput == "magazine") {
		cout << "Please enter the ID number: ";
		cin >> idNumber;
		cin.ignore();
		cout << "\nPlease enter the magazine's title: ";
		cin.getline(itemTitle, 50);
		cin.ignore();
		cout << "\nPlease enter the magazine's issue: ";
		cin >> num1;
		cin.ignore();
		libraryelements.push_back(new Magazines(idNumber, itemTitle, true, num1));
	}
}



int main() {
	vector<LibraryItem*> libraryitems;
	libraryitems.push_back(new Books(22, "Apple vine", true, "Day Rey"));
	libraryitems.push_back(new Books(2243, "Frey", false, "Picolo"));
	libraryitems.push_back(new Books(23, "Ape", true, "Jimmy Fuergo"));
	libraryitems.push_back(new Books(2123, "Rent", true, "Hendrix Reyan"));
	libraryitems.push_back(new Books(1223, "Grape vine", false, "Lenay Jane"));
	libraryitems.push_back(new Magazines(124, "Entertainment", false, 6));
	libraryitems.push_back(new Magazines(6624, "Modern Middle East", true, 12));
	libraryitems.push_back(new Magazines(74, "EEC", true, 15));
	libraryitems.push_back(new Magazines(294, "Vogue", false, 2));
	libraryitems.push_back(new Magazines(216, "People!", false, 65));
	libraryitems.push_back(new Journals(225, "Science: life science", true, 75));
	libraryitems.push_back(new Journals(15, "Sociology: all about the brain", true, 53));
	libraryitems.push_back(new Journals(90, "Physics: testing Gravity", false, 22));
	libraryitems.push_back(new Journals(995, "History", true, 55));
	libraryitems.push_back(new Journals(6515, "geophysical science journal", false, 12));

	string trash = "";
	char action = 0;
	while (true) {
		try {
			cout << "\n";
			displayChoices();
			cout << "\nPlease select an option: \n";
			cin >> action;
			getline(cin, trash);
			switch (action) {
			case '1':searchCatalog(libraryitems);
				break;

			case '2':checkOut(libraryitems);
				break;

			case '3':returnItem(libraryitems);
				break;

			case '4':addItem(libraryitems);
				break;

			case '5':return 0;

			default:cout << "Invalid Input. Try again.\n";
			}
		}
		catch (exception e) {
			cout << e.what() << endl;
			cin.clear();
			getline(cin, trash);
		}
	}
}