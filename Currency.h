//not done yet
#define CURRENCY_H
#ifndef CURRENCY_H
#include <string>

class Currency {

protected: //so derived class can read it too
	string currency_name, fractional_name;
	int whole_parts, frac_parts;

public:

	Currency();
	string getCurrencyName();
	string getFractionalName();
	int getwhole_parts();
	int getfrac_parts();

	friend ostream& operator<<(ostream &out, const Currency &C);
	friend istream& operator>>(istream &in, const Currency &C);
};
	
class Dollar : public Currency {

public:

	Dollar() {};
	Dollar(int x, int y) {};
	~Dollar() {}; // destructor

	Dollar operator+(const Dollar &dollar) const;
	Dollar operator-(const Dollar &dollar1) const;

	std::istream& operator>>(std::istream& in, const Dollar& D);
	std::ostream& operator<<(std::ostream& out, const Dollar& D);
};	

#endif
