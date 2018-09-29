#include <iostream>
#include <string>
#include <cstdlib>
#include "Currency.h"

using namespace std;

class Currency {

protected: //so derived class can read it too
	string currency_name, fractional_name;
	int whole_parts, frac_parts;

public:

	string getCurrencyName();
	string getFractionalName();
	int getwhole_parts();
	int getfrac_parts();

	Currency() {
		
	}

	friend ostream& operator<<(ostream &out, const Currency &C);
	friend istream& operator>>(istream &in, Currency &C); 
};

string Currency::getCurrencyName()
{
	return currency_name;
}

string Currency::getFractionalName()
{
	return fractional_name;
}

int Currency::getwhole_parts()
{
	return whole_parts;
}

int Currency::getfrac_parts()
{
	return frac_parts;
}


class Dollar : public Currency { //Derived class

public:

	Dollar() {}; //constructor
	Dollar(int x, int y)
	{
		currency_name = "Dollar";
		fractional_name = "Cent";
		whole_parts = x;
		frac_parts = y;
	}
	~Dollar() {}; // destructor

	Dollar operator+(const Dollar &dollar) //overloaded operator for add
	{
		Dollar x;
		x.whole_parts = whole_parts + dollar.whole_parts;
		whole_parts++;
		x.frac_parts = frac_parts + dollar.frac_parts;
		return x;
	}

	Dollar operator-(const Dollar &dollar1) //overloaded operator for subtract 
	{
		Dollar x;
		x.whole_parts = whole_parts = dollar1.whole_parts;
		x.frac_parts = frac_parts = dollar1.frac_parts;
		return x;
	}

	friend istream &operator>>(istream &in, Dollar &D) //overloaded in stream operator
	{
		cin >> D.whole_parts;
		cout << "Now enter cents: "<< endl;
		cin>> D.frac_parts;
		return in;
	}

	friend ostream &operator<<(ostream &out, const Dollar &D) //overloaded out stream operator
	{ 
		out << "Current savings for Dollars: " << D.whole_parts << " Dollars and " << D.frac_parts << " Cent" << endl;
		return out;
	}
};

class Euro : public Currency {

public:
	Euro() {}
	Euro(int x, int y) //constructor
	{
		currency_name = "Euro";
		fractional_name = "Cent";
		whole_parts = x;
		frac_parts = y;
	}

	~Euro() {}; // destructor

	Euro operator+(const Euro &euro) //overloaded in stream operator
	{
		Euro x;
		x.whole_parts = whole_parts + euro.whole_parts;
		x.frac_parts = frac_parts + euro.frac_parts;
		return x;
	}

	Euro operator-(const Euro &euro) //overloaded operator
	{
		Euro x;
		x.whole_parts = whole_parts - euro.whole_parts;
		x.frac_parts = frac_parts - euro.frac_parts;
		return x;
	}

	friend istream &operator>>(istream &in, Euro &E)  //overloaded in stream operator
	{
		cin >> E.whole_parts;
		cout << "Now enter Cents: " << endl;
		cin >> E.frac_parts;
		return in;
	}

	friend ostream &operator<<(ostream &out, const Euro &E)  //overloaded out stream operator
	{ 
		out << "Current Savings for Euro: " << E.whole_parts << " Euros and " << E.frac_parts << " Cent" << endl;
		return out;
	}
};

class Yen : public Currency {

public:

	Yen() {};
	Yen(int whole, int fract) //constructor
	{
		currency_name = "Yen";
		fractional_name = "Sen";
		whole_parts = whole;
		frac_parts = fract;
	}

	~Yen() {}; // destructor to empty dollars in wallet

	Yen operator+(const Yen &yen) //overloaded operator
	{
		Yen x;
		x.whole_parts = whole_parts + yen.whole_parts;
		x.frac_parts = frac_parts + yen.frac_parts;
		return x;
	}

	Yen operator-(const Yen &yen1) //overloaded operator
	{
		Yen x;
		x.whole_parts = whole_parts - yen1.whole_parts;
		x.frac_parts = frac_parts - yen1.frac_parts;
		return x;
	}

	friend istream &operator>>(istream &in, Yen &Y)  //overloaded  input operator
	{
		cin >> Y.whole_parts;
		cout << "Now enter Sen: " << endl;
		cin >> Y.frac_parts;
		return in;
	}

	friend ostream &operator<<(ostream &out, const Yen &Y)  //overloaded output operator
	{ 
		out << "Current Savings for Yen: " << Y.whole_parts << " Yen and " << Y.frac_parts << " Sen" << endl;
		return out;
	}
};

class Rupee : public Currency {

public:

	Rupee() {};
	Rupee(int whole, int fract) //constructor
	{
		currency_name = "Rupee";
		fractional_name = "Paise";
		whole_parts = whole;
		frac_parts = fract;
	}

	~Rupee() {}; // destructor 

	Rupee operator+(const Rupee &rupee) //overloaded operator
	{
		Rupee x;
		x.whole_parts = whole_parts + rupee.whole_parts;
		x.frac_parts = frac_parts + rupee.frac_parts;
		return x;
	}

	Rupee operator-(const Rupee &rupee1)  //overloaded operator

	{
		Rupee x;
		x.whole_parts = whole_parts - rupee1.whole_parts;
		x.frac_parts = frac_parts - rupee1.frac_parts;
		return x;
	}

	friend istream &operator>>(istream &in, Rupee &R)  //overloaded input operator
	{
		cin >> R.whole_parts;
		cout << "Now enter Paise: " << endl;
		cin >> R.frac_parts;
		return in;
	}

	friend ostream &operator<<(ostream &out, const Rupee &R)   //overloaded output operator
	{
		out << "Current Savings for Rupee: " << R.whole_parts << " Rupee and " << R.frac_parts << " Paise" << endl;
		return out;
	}
};

class Yuan : public Currency {

public:
	Yuan() {};
	Yuan(int whole, int fract) //constructor
	{
		currency_name = "Yuan";
		fractional_name = "Fen";
		whole_parts = whole;
		frac_parts = fract;
	}

	~Yuan() {}; // destructor

	Yuan operator+(const Yuan &yuan) //overloaded operator
	{
		Yuan tempYuan;
		tempYuan.whole_parts = whole_parts + yuan.whole_parts;
		tempYuan.frac_parts = frac_parts + yuan.frac_parts;
		return tempYuan;
	}

	Yuan operator-(const Yuan &yuan1)  //overloaded operator
	{
		Yuan tempYuan1;
		tempYuan1.whole_parts = whole_parts - yuan1.whole_parts;
		tempYuan1.frac_parts = frac_parts - yuan1.frac_parts;
		return tempYuan1;
	}

	friend istream &operator>>(istream &in, Yuan &Y)  //overloaded input operator
	{
		cin >> Y.whole_parts;
		cout << "Now enter Fen: " << endl;
		cin >> Y.frac_parts;
		return in;
	}

	friend ostream &operator<<(ostream &out, const Yuan &Y) 
	{  //overloaded output operator
		out << "Current Savings for Yuan: " << Y.whole_parts << " Yuan and " << Y.frac_parts << " Fen" << endl;
		return out;
	}
};

int main()

{
	int answer1=0, answer2=0;

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
			cout << endl << "Select the type of currency: " << endl;
			cout << "1. Dollar" << endl;
			cout << "2. Euro" << endl;
			cout << "3. Yen" << endl;
			cout << "4. Rupee" << endl;
			cout << "5. Yuan" << endl << endl;
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
