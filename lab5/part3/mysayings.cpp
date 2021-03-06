// Patrick Soga
// Section 2 Lab 4
// 16 October 2019
// mysayings.cpp: terminal-based sayings manager
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <iostream>
using namespace std;

vector<string> startup();
void menu(vector<string>);
void prompt();
void decider(int, vector<string> &saying);
void display(vector<string>);
void newSaying(string, vector<string> &saying);
void findString(string, vector<string>);
void removeSaying(vector<string> &sayings);
void saveSayings(vector<string>);

int main() {

	vector<string> sayings;

	sayings = startup();		// Initialize the sayings into the sayings vector
	menu(sayings);

	return 0;
}

// Set up for startup file
vector<string> startup() {
	ifstream ifs;
	string path;
	string saying;
	vector<string> sayings;		// Contains all sayings during session

	cout << "Welcome to the sayings manager!" << endl;
	cout << "Please enter the path to a valid startup file that contains some initial sayings." << endl;
	cout << "If you have none, then use startup.txt." << endl;
	getline(cin, path);
	ifs.open(path);
	if (!ifs) {
		cout << "Error opening file " << path << endl << endl << "No sayings loaded"<< endl << endl;
	}
	else {
		getline(ifs, saying);
		while (!ifs.eof()) {
			sayings.push_back(saying);
			getline(ifs, saying);
		}
		ifs.close();
		cout << endl;
		return sayings;
	}
}

void menu(vector<string> sayings) {
	int choice;
	prompt();
	cin >> choice;
	cin.ignore();
	// Ensure user options are within constraints
	while (true) {
		if (!(choice < 7 && choice > 0))
			cout << endl << "Invalid. Try again." << endl;
		else if (choice == 6)
		{
			decider(choice, sayings);
			break;
		}
		else decider(choice, sayings);
		prompt();
		cin >> choice;
		cin.ignore();
	}
}

// Display options to user
void prompt() {
	cout << "Select an option:" << endl;
	cout << "1. display all sayings currently in the database" << endl;
	cout << "2. enter a new saying into the database" << endl;
	cout << "3. list sayings that contain a given substring entered by the user" << endl;
	cout << "4. save all sayings in a new text file" << endl;
	cout << "5. remove a saying" << endl;
	cout << "6. quit the program" << endl;	
}

// Determine what to do based on choice
void decider(int choice, vector<string> &sayings) {
	string saying;
	string substring;
	switch (choice)
	{
	case 1:
		display(sayings);
		break;
	case 2:
		cout << endl <<"Enter a new saying: " << endl;
		getline(cin, saying);
		newSaying(saying, sayings);
		break;
	case 3:
		cout << endl << "Enter a substring to search for: " << endl;
		getline(cin, substring);
		findString(substring, sayings);
		break;
	case 4:
		saveSayings(sayings);
		cout << endl << "Sayings saved in save.txt" << endl;
		break;
	case 5:
		removeSaying(sayings);
		break;
	case 6:
		cout << endl << "Good bye!" << endl;
		break;
	default:
		cout << endl << "Invalid input" << endl;
		break;
	}
}

// Show all sayings
void display(vector<string> sayings) {
	cout << endl;
	for (auto it = sayings.begin(); it < sayings.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
}

// Enter a new saying
void newSaying(string saying, vector<string> &sayings) {
	sayings.push_back(saying);
	cout << endl << "Saying saved" << endl << endl;
}

// Find sayings given a substring
void findString(string substring, vector<string> sayings) {
	for (auto it = sayings.begin(); it < sayings.end(); it++) {
		if ((*it).find(substring) != string::npos) {
			cout << *it << endl;
		}
	}
	cout << endl;
}

void removeSaying(vector<string> &sayings) {
	int count = 0;
	int choice = 0;
	cout << endl << "Which saying would you like to remove? (enter 0-n)" << endl;
	for (auto it = sayings.begin(); it < sayings.end(); it++) {
		cout << count << "  " << "\"" << *it << "\"" << endl;
		count++;
	}
	cin >> choice;
	cin.ignore();
	while (!(choice > 0 && choice < choice + 1)) {
		cout << "Invalid input. Enter another number between 0 and n." << endl;
		cin >> choice;
		cin.ignore();
	}
	sayings.erase(sayings.begin() + choice);
	cout << endl << "Saying deleted!" << endl << endl;
}

// Save sayings in save.txt
void saveSayings(vector<string> sayings) {
	ofstream ofs;
	string filename;
	cout << endl << "Enter a file to save sayings to (ending with .txt)" << endl;
	getline(cin, filename);
	ifstream ifs(filename);		// Create save file
	ofs.open(filename);
	if(!ofs)
		cout << "error saving to file" << endl;	// Error message
	else {
		for (auto it = sayings.begin(); it < sayings.end(); it++) {
			ofs << *it;
			ofs << endl;
		}
		cout << "Sayings saved in " << filename << endl << endl << endl;
	}
	ofs.close();
	ifs.close();
}