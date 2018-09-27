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
	Message3 getM2(Message2 m2);
	MsgChaningPassword User::generateChaningPassword();
	void User::getChaningPasswordBack(MsgBackChaningPassword backMsg);

private:
	unsigned short idi;
	string pwi;
	Big a;
	Big aNew;
	string pwNew;
	Big mpi;

	Big p;
	ECn r;
	ECn g;

	Big b;
	ECn V;
	ECn V1;
	string w;
	int timeStamp;


	Big N;

	string di;
	string sk;
};
#endif

