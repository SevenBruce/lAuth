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
	ECn getG();
	BackUser getRegUser(RegUser regUser);
	Message2 getM1(Message1 m1);
	MsgBackChaningPassword Gateway::getChangingPassword(MsgChaningPassword mc);

	//bool Gateway::isInIdentieis(string idenity);
	//void clearIdentities();

private:
	string xgwn;
	string idi;

	ECn g;
	Big p;
};

#endif