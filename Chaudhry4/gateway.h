#ifndef GATEWAY_H
#define GATEWAY_H

#include "utils.h"
#include "messages.h"
#include <string>
#include<iostream>
using namespace std;

#include "ECn.h"
#include "Big.h"

#include "PublicPara.h"

class Gateway {
public:
	Gateway(ECn g, Big p);
	~Gateway() {
	}
	ECn getMpk();
	BackUser getRegUser(RegUser regUser);
	Message2 getM1(Message1 m1);
	void getM3(Message3 m3);

private:
	Big msk;
	Big p;

	ECn g;
	ECn Qua1;
	ECn Qsb;
	ECn mpk;
	string sk;
};

#endif