#include <string>
#include <iostream>
#include <fstream>
#include <cstring> 
#include "HashMap.h"
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::endl;
using std::getline;

int main() {
	HashMap<string> hash(12);
	ifstream infile;
	int i;
	infile.open("bst_testfile.txt");
	string bdaya[25], namea[25];
	string str = "";
	string ans1;

	for (i = 0; !infile.eof(); i++) {
		getline(infile, namea[i]);
		getline(infile, bdaya[i]);
	}

	for (i = 0; hash.size()>= i; i++) {
	hash.insert(bdaya[i], namea[i]);
	}

	cout << "Statistics:" << endl;
	cout << "Hash Size: " << hash.bucketsUsed() << " of " << hash.size() << " Attempts" << endl;
	cout << "Buckets Used: " << hash.bucketsUsed() << endl;
	cout << "Load Factor: " << (double)hash.bucketsUsed() / (double)hash.size() * 100 << '%' << endl;
	cout << "Collisions: " << hash.collisions() << endl<<endl;
	cout << "Enter Birthday to find Name, or enter 0 to quit: " << endl;
	cin >> ans1;

	if (ans1 != "0") {
		do {
			cout << "Name: " << hash.find(ans1) <<endl;
			cout << "Enter another Birthday or 0 to quit: " << endl;
			cin >> ans1;
			bool temp = false;

			//for checking validity of input
			for (int j = 0; j < 26; j++) {
				if (bdaya[j] == ans1) {
					temp = true;
				}
			}
			if (temp == false)
			{
				cout << "Invalid Input" << endl;
			}
			
		} while (ans1 != "0");
	}

	infile.close();
	return 0;
}
