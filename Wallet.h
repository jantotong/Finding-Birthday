#include "Currency.h"
#ifndef WALLET_H
#define WALLET_H
using namespace std;

class Wallet {
private:
	Currency Dollar, Euro, Yen, Rupee, Yuan;
	Currency wallet[5] = {Dollar, Euro, Yen, Rupee, Yuan};
	int numTypes;
public:
	Wallet();
	~Wallet() {}; // destructor

	void typeExists(int x);
	void add(int x, Currency type);
	void subtract(int x, Currency type);
	void show(int x);
	void removeAll();
	void isEmpty();
};
#endif
