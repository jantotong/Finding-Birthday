#include "Currency.h"
#include "Wallet.h"
#include <iostream>

int main()

{
	using namespace std;

	int answer1 = 0, answer2 = 0;

	Wallet wallet;
	Dollar dollar;
	Euro euro;
	Yen yen;
	Rupee rupee;
	Yuan yuan;

	Currency *d = &dollar;
	Currency *e = &euro;
	Currency *y = &yen;
	Currency *r = &rupee;
	Currency *yu = &yuan;

	do { //Do while loop while answer inst 6
		cout << "Please choose a Number:" << endl << endl;
		cout << "1. Add Money" << endl;
		cout << "2. Subtract Money" << endl;
		cout << "3. Display Money in Wallet" << endl;
		cout << "4. check if type is empty" << endl;
		cout << "5. check if wallet is empty" << endl;
		cout << "6. Empty Money in Wallet" << endl;
		cout << "7. Exit" << endl << endl;
		cout << "Please Enter: ";
		
		cin >> answer1;
		
		switch(answer1){
		case 6: wallet.removeAll(); break;
		cout << "Select the type of currency: " << endl;
		cout << "1. Dollar" << endl;
		cout << "2. Euro" << endl;
		cout << "3. Yen" << endl;
		cout << "4. Rupee" << endl;
		cout << "5. Yuan" << endl;
		cout << "Please Enter: " << endl;
		cin >> answer2;
		case 1: 
			switch (answer2) {
			case 1:
				cout << "Please enter amount of Dollars: " << endl;
				cin >> dollar;    //input stream overloader
				wallet.add(1, dollar);
				cout << dollar; //output stream overloader
				break;
			case 2:
				cout << "Please enter amount of Euros: " << endl;
				cin >> euro;
				wallet.add(2, euro);
				cout << euro;
				break;
			case 3:
				cout << "Please enter amount of Yens: " << endl;
				cin >> yen;
				wallet.add(3, yen);
				cout << yen;
				break;
			case 4:
				cout << "Please enter amount of Rupees: " << endl;
				cin >> rupee;
				wallet.add(4, rupee);
				cout << rupee;
				break;
			case 5:
				cout << "Please enter amount of Yuans: " << endl;
				cin >> yuan;
				wallet.add(5, yuan);
				cout << yuan;
				break;
			default: cout << "you have entered an invalid number"; break;
			}
		case 2:
			switch (answer2) {
			case 1:
					cout << "Please enter amount of Dollars: " << endl;
					cin >> dollar;
					wallet.subtract(1, dollar);
					cout << dollar;
					break;
			case 2:
					cout << "Please enter amount of Euros" << endl;
					cin >> euro;
					wallet.subtract(2, euro);
					cout << euro;
					break;
			case 3:
					cout << "Please enter amount of Yens: " << endl;
					cin >> yen;
					wallet.subtract(3, yen);
					cout << yen;
					break;
			case 4: 
					cout << "Please enter amount of Rupees: " << endl;
					cin >> rupee;
					wallet.subtract(4, rupee);
					cout << rupee;
					break;
				
			case 5:
					cout << "Please enter amount of Yuans & Fens: " << endl;
					cin >> yuan;
					wallet.subtract(5, yuan);
					cout << yuan;
					break;
			default: cout << "you have entered an invalid number"; break;
			}
		case 3:
			switch (answer2) {
			case 1: wallet.show(1); break;
			case 2: wallet.show(2); break;
			case 3: wallet.show(3); break;
			case 4: wallet.show(4); break;
			case 5: wallet.show(5); break;
			default: cout << "you have entered an invalid number"; break;
			}
		case 4:
			switch(answer2){
			case 1: wallet.typeExists(1); break;
			case 2: wallet.typeExists(2); break;
			case 3: wallet.typeExists(3); break;
			case 4: wallet.typeExists(4); break;
			case 5: wallet.typeExists(5); break;
			}
		case 5:
			wallet.isEmpty(); 
			break;
		default: cout << "you have entered an invalid number"; break;
		}

		system("pause");
	} while (answer1 != 6); //6=Exit; end of do-while loop
}








/*if (answer1 >= 1 && answer1 <= 4)
{
cout << "Select the type of currency: " << endl;
cout << "1. Dollar" << endl;
cout << "2. Euro" << endl;
cout << "3. Yen" << endl;
cout << "4. Rupee" << endl;
cout << "5. Yuan" << endl;
cout << "Please Enter: " << endl;
cin >> answer2;
}

if (answer1 == 1 && answer2 >= 1 && answer2 <= 5)
{
if (answer2 == 1)
{
cout << "Please enter amount of Dollars: " << endl;
cin >> dollar;    //input stream overloader
wallet.add(1, dollar);
cout << dollar; //output stream overloader
}

else if (answer2 == 2)
{
cout << "Please enter amount of Euros: " << endl;
cin >> euro;
wallet.add(2, euro);
cout << euro;
}

else if (answer2 == 3)
{
cout << "Please enter amount of Yens: " << endl;
cin >> yen;
wallet.add(3, yen);
cout << yen;
}

else if (answer2 == 4)
{
cout << "Please enter amount of Rupees: " << endl;
cin >> rupee;
wallet.add(4, rupee);
cout << rupee;
}

else if (answer2 == 5)
{
cout << "Please enter amount of Yuans: " << endl;
cin >> yuan;
wallet.add(5, yuan);
cout << yuan;
}
}
if (answer1 == 2 && answer2 >= 1 && answer2 <= 5)
{
if (answer2 == 1)
{
cout << "Please enter amount of Dollars: " << endl;
cin >> dollar;
wallet.subtract(1, dollar);
cout << dollar;
}

else if (answer2 == 2)
{
cout << "Please enter amount of Euros" << endl;
cin >> euro;
wallet.subtract(2, euro);
cout << euro;
}

else if (answer2 == 3)
{
cout << "Please enter amount of Yens: " << endl;
cin >> yen;
wallet.subtract(3, yen);
cout << yen;
}

else if (answer2 == 4)
{
cout << "Please enter amount of Rupees: " << endl;
cin >> rupee;
wallet.subtract(4, rupee);
cout << rupee;
}

else if (answer2 == 5)
{
cout << "Please enter amount of Yuans & Fens: " << endl;
cin >> yuan;
wallet.subtract(5, yuan);
cout << yuan;
}
else
cout << "Please enter a valid in" << endl;
}
if (answer1 == 3 && answer2 >= 1 && answer2 <= 5)
{
if (answer2 == 1)
{
wallet.show(1);
}

else if (answer2 == 2)
{
wallet.show(2);
}

else if (answer2 == 3)
{
wallet.show(3);
}

else if (answer2 == 4)
{
wallet.show(4);
}
else if (answer2 == 5)
{
wallet.show(5);
}

else
cout << "Please enter a valid in" << endl;
}
if (answer1 == 4 && answer2 >= 1 && answer2 <= 5)
{
if (answer2 == 1)
{
wallet.typeExists(1);
}

else if (answer2 == 2)
{
wallet.typeExists(2);
}

else if (answer2 == 3)
{
wallet.typeExists(3);
}

else if (answer2 == 4)
{
wallet.typeExists(4);
}
else if (answer2 == 5)
{
wallet.typeExists(5);
}

else
cout << "Please enter a valid in" << endl;
}
if (answer1 == 5)
{
wallet.removeAll();
}
*/
