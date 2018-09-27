#ifndef USER_H
#define USER_H

#include "utils.h"
#include "messages.h"
#include "PublicPara.h"

#include <string>
#include<iostream>

using namespace std;

class User {
public:
	User(ECn g, Big p, unsigned short ids);
	~User() {
	}
	RegUser generateReg();
	void getBackUser(BackUser backUser);
	Message1 generateM1();
	void getM2(Message2 m2);
	MsgChaningPassword User::generateChaningPassword();
	void User::getChaningPasswordBack(MsgBackChaningPassword backMsg);

private:
	unsigned short idi;
	unsigned short ids;
	string pwi;
	string ri;
	string Hi;
	string rbi;

	string fi;
	string B2;
	string B1;
	int ei;
	ECn g;
	Big p;

	string ui;

	string m2m2;
	Big alpha;
	ECn C1;
	string C2;
	string C3;
	int timeStamp;

	string di;
	string sku;
};
#endif

