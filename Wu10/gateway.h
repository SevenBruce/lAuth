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
	BackUser getRegUser(RegUser regUser);
	Message2 getM1(Message1 m1);
	MsgBackChaningPassword Gateway::getChangingPassword(MsgChaningPassword mc);

	unsigned short Gateway::getIds();

private:
	string x;
	string idi;
	unsigned short ids;
	string sidj;

	ECn g;
	Big p;
};

#endif