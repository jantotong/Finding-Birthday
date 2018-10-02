#include <iostream>
#include <string>
#include <cstdlib>
#include "Currency.h"

using namespace std;

Currency::Currency() {
	whole_parts = 0;
	frac_parts = 0;
}
Currency::Currency(int x, int y) {
	whole_parts = x;
	frac_parts = y;
	simplify();
}
Currency Currency::operator+(Currency& other) {
	whole_parts += other.whole_parts;
	frac_parts += other.frac_parts;
	simplify();
	return *this;
}
Currency Currency::operator-(Currency& other) {
	Currency c = Currency(this->whole_parts, this->frac_parts);
	c.whole_parts -= other.whole_parts;
	c.frac_parts -= other.frac_parts;
	whole_parts = c.whole_parts;
	frac_parts = c.frac_parts;
	return *this;
}

void Currency::show() const {
	cout << endl<< "Your Cu" << whole_parts << " Dollars and " << frac_parts << " Cents " << endl;
}

void Currency::simplify() {
	if (frac_parts > 99) {
		whole_parts += frac_parts / 100;
		frac_parts = frac_parts % 100;
	}
	else if (frac_parts < 0) {
		frac_parts *= -1;
		whole_parts -= frac_parts / 100 - 1;
		frac_parts = 100 - (frac_parts % 100);
		simplify();
	}
	if (whole_parts < 0 || frac_parts < 0) {
		throw "Can't have negative " + currency_name;
	}
}
