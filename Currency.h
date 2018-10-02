#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
using namespace std;

class Currency {
protected:
	string currency_name, fractional_name;

public:
	Currency();
	Currency(int x, int y);
	Currency operator+(Currency& other);
	Currency operator-(Currency& other);
	istream& operator>>(istream& is);
	ostream& operator<<(ostream& os);
	int whole_parts, frac_parts;
	void simplify();
	void show() const;
};

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

	friend istream &operator>>(istream &in, Dollar &D) //overloaded in stream operator
	{
		cin >> D.whole_parts;
		cout << "Now enter cents: " << endl;
		cin >> D.frac_parts;
		D.simplify();

		return in;
	}

	friend ostream &operator<<(ostream &out, const Dollar &D) //overloaded out stream operator
	{
		out << "A transaction of  " << D.whole_parts << " Dollars and " << D.frac_parts << " Cent has been made" << endl;
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

	friend istream &operator>>(istream &in, Euro &E)  //overloaded in stream operator
	{
		cin >> E.whole_parts;
		cout << "Now enter Cents: " << endl;
		cin >> E.frac_parts;
		E.simplify();
		return in;
	}

	friend ostream &operator<<(ostream &out, const Euro &E)  //overloaded out stream operator
	{
		out << "A transaction of  " << E.whole_parts << " Euros and " << E.frac_parts << " Cent has been made" << endl;
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

	friend istream &operator>>(istream &in, Yen &Y)  //overloaded  input operator
	{
		cin >> Y.whole_parts;
		cout << "Now enter Sen: " << endl;
		cin >> Y.frac_parts;
		Y.simplify();
		return in;
	}

	friend ostream &operator<<(ostream &out, const Yen &Y)  //overloaded output operator
	{
		out << "A transaction of  " << Y.whole_parts << " Yen and " << Y.frac_parts << " Sen has been made" << endl;
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

	friend istream &operator>>(istream &in, Rupee &R)  //overloaded input operator
	{
		cin >> R.whole_parts;
		cout << "Now enter Paise: " << endl;
		cin >> R.frac_parts;
		R.simplify();
		return in;
	}

	friend ostream &operator<<(ostream &out, const Rupee &R)   //overloaded output operator
	{
		out << "A transaction of  " << R.whole_parts << " Rupee and " << R.frac_parts << " Paise has been made" << endl;
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

	friend istream &operator>>(istream &in, Yuan &Y)  //overloaded input operator
	{
		cin >> Y.whole_parts;
		cout << "Now enter Fen: " << endl;
		cin >> Y.frac_parts;
		Y.simplify();
		return in;
	}

	friend ostream &operator<<(ostream &out, const Yuan &Y)
	{  //overloaded output operator
		out << "A transaction of  " << Y.whole_parts << " Yuan and " << Y.frac_parts << " Fen has been made" << endl;
		return out;
	}
};

#endif
