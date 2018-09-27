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
	User(ECn g, Big p, ECn mpk);
	~User() {
	}
	RegUser generateReg();
	void getBackUser(BackUser backUser);
	Message1 generateM1();
	Message3 getM2(Message2 m2);

private:
	//string IDua;
	unsigned short IDua;
	string pwua;
	int rua;
	Big mpi;

	Big p;
	ECn AIDua;
	string BIDua;
	ECn Mua;
	ECn g;
	ECn mpk;

	ECn TIDua;
	string EIDua;

	Big qua;
	ECn Qua;

	string sk;
};
#endif

