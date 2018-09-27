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
	User();
	User(ECn g, Big p);
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
	string pwi;
	int ri;
	string mpi;

	string fi;
	int ki;
	string hi;
	string ei;
	ECn g;

	string m2m2;
	Big k1;
	ECn A;
	Big p;
	int timeStamp;

	string di;
	string skij;

};
#endif

