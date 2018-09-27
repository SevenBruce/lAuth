#ifndef ENTITIES_H
#define ENTITIES_H

#include "utils.h"
#include "messages.h"
#include "publicPara.h"

#include <time.h>
#include "ecn.h"
#include "big.h"

#include<iostream>
#include <string>
using namespace std;

#pragma region User
class User {
	public:
		User(ECn g);
		~User() {
		}
		RegUser generateReg();
		void getBackUser(BackUser backUser);
		void setSidj(string sidj);
		Message1 generateM1();
		void getM4(Message4 m4);

	private:
		string idi;
		string pwi;
		string ri;
		string mpi;

		string fi;
		string li;
		string ki;
		ECn g;

		string sidj;
		int iUser;
		Big pUser;
		Big k1;
		ECn A;
		int timeStamp;
		
		string ei;
		string di;
		string skij;

};
#pragma endregion


#pragma region Gateway
class Gateway {
		public:
		Gateway();
		~Gateway() {
		}
		ECn getG();
		BackUser getRegUser(RegUser regUser);
		BackSensor getRegSensor(RegSensor regSensor);
		Message2 getM1(Message1 m1);
		Message4 getM3(Message3 m3);

	private:
		string xgwn;
		string idi;
		string sidj;

		string di;
		string ei;
		string ki;

		string xj;
		string m3;

		ECn g;
		ECn A;
		ECn B;
		int timeStamp2;
		int timeStamp1;
};
#pragma endregion

#pragma region Sensor
class Sensor {
public:
	Sensor(ECn g);
	~Sensor() {
	}
	RegSensor generateRegSensor();
	void getBackSensor(BackSensor backSensor);
	Message3 getM2(Message2 m2);
	string getSidj();

private:
	string sidj;
	string xj;
	string skij;
	ECn g;
	Big k2;

	ECn B;
	int timeStamp;
};
#pragma endregion




#endif


