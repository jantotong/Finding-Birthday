#include "Currency.h"
#include "Wallet.h"
#include <iostream>

int main()

{
	int answer1 = 0, answer2 = 0;

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

	do { //Do while loop
		cout << "Please choose a Number:" << endl << endl;
		cout << "1. Add Money" << endl;
		cout << "2. Subtract Money" << endl;
		cout << "3. Check if Wallet is empty" << endl;
		cout << "4. Display Money in Wallet" << endl;
		cout << "5. Empty Money in Wallet" << endl;
		cout << "6. Exit" << endl << endl;
		cout << "Please Enter: ";

		cin >> answer1;

		if (answer1 >= 1 && answer1 <= 2)
		{
			cout << "Select the type of currency: " << endl;
			cout << "1. Dollar" << endl;
			cout << "2. Euro" << endl;
			cout << "3. Yen" << endl;
			cout << "4. Rupee" << endl;
			cout << "5. Yuan" << endl;
			cout << "Please Enter: ";
			cin >> answer2;
		}

		if (answer1 == 1 && answer2 >= 1 && answer2 <= 5)
		{
			if (answer2 == 1)
			{
				cout << "Please enter amount of Dollars: " << endl;
				cin >> dollar;    //input stream overloader
				cout << dollar;   //output stream overloader
			}

			else if (answer2 == 2)
			{
				cout << "Please enter amount of Euros: " << endl;
				cin >> euro;
				cout << euro;
			}

			else if (answer2 == 3)
			{
				cout << "Please enter amount of Yens: " << endl;
				cin >> yen;
				cout << yen;
			}

			else if (answer2 == 4)
			{
				cout << "Please enter amount of Rupees: " << endl;
				cin >> rupee;
				cout << rupee;
			}

			else if (answer2 == 5)
			{
				cout << "Please enter amount of Yuans: " << endl;
				cin >> yuan;
				cout << yuan;
			}
		}

		if (answer1 == 2 && answer2 >= 1 && answer2 <= 5)
		{
			if (answer2 == 1)
			{
				cout << "Please enter amount of Dollars: " << endl;
				cin >> dollar;
				cout << dollar;
			}

			else if (answer2 == 2)
			{
				cout << "Please enter amount of Euros" << endl;
				cin >> euro;
				cout << euro;
			}

			else if (answer2 == 3)
			{
				cout << "Please enter amount of Yens: " << endl;
				cin >> yen;
				cout << yen;
			}

			else if (answer2 == 4)
			{
				cout << "Please enter amount of Rupees: " << endl;
				cin >> rupee;
				cout << rupee;
			}

			else if (answer2 == 5)
			{
				cout << "Please enter amount of Yuans & Fens: " << endl;
				cin >> yuan;
				cout << yuan;
			}
			else
				cout << "Please enter a valid in" << endl;
		}
		system("pause");

	} while (answer1 != 6); //6=Exit; end of do-while loop
}
