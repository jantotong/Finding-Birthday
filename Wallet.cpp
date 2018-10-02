#include "Wallet.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

Wallet::Wallet() {
	Dollar = Currency(0, 0);
	Euro = Currency(0, 0);
	Yen = Currency(0, 0);
	Rupee = Currency(0, 0);
	Yuan = Currency(0, 0);
}

void Wallet::add(int x, Currency type){
	wallet[x] + type;
}

void Wallet::subtract(int x, Currency type) {
	wallet[x] - type;
}

void Wallet::typeExists(int x) {
		if (wallet[x].whole_parts == 0 && wallet[x].frac_parts == 0) {
			cout << "Currency is empty" << endl;
		}
		else {
			cout << "Currency is not empty" << endl;
		}
}

void Wallet::show(int x) {
	if(x==1)
	cout << endl << "Your current saving for Dollar is " << wallet[x].whole_parts << " Dollars and " << wallet[x].frac_parts << " Cents " << endl;
	else if(x==2)
	cout << endl << "Your current saving for Euro is " << wallet[x].whole_parts << " Euros and " << wallet[x].frac_parts << " Cents " << endl;
	else if(x==3)
	cout << endl << "Your current saving for Yen is " << wallet[x].whole_parts << " Yens and " << wallet[x].frac_parts << " Sens " << endl;
	else if(x==4)
	cout << endl << "Your current saving for Rupee is " << wallet[x].whole_parts << " Rupees and " << wallet[x].frac_parts << " Paises " << endl;
	else if(x==5)
	cout << endl << "Your current saving for Yuan is " << wallet[x].whole_parts << " Yuans and " << wallet[x].frac_parts << " Fens " << endl;
}

void Wallet::removeAll(){
	for (int i = 0; i < (5);) {
		wallet[i].whole_parts = 0;
		wallet[i].frac_parts = 0;
		i++;
	}
	cout << endl << "Wallet has been emptied" << endl << endl;
}
