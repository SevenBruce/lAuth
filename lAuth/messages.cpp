#include "messages.h"

#pragma region RegUser
RegUser::RegUser()
{
	RegUser::idi = 0;
	RegUser::mpi = "";
}
RegUser::RegUser(unsigned short idi, string mpi)
{
	RegUser::idi = idi;
	RegUser::mpi = mpi;
}

unsigned short RegUser::getIdi()
{
	return RegUser::idi;
}

void RegUser::setIdi(unsigned short idi)
{
	RegUser::idi = idi;
}

//RegUser::RegUser()
//{
//	RegUser::idi = "";
//	RegUser::mpi = "";
//}
//RegUser::RegUser(string idi, string mpi)
//{
//	RegUser::idi = idi;
//	RegUser::mpi = mpi;
//}
//
//string RegUser::getIdi()
//{
//	return RegUser::idi;
//}
//
//void RegUser::setIdi(string idi)
//{
//	RegUser::idi = idi;
//}

string RegUser::getMpi()
{
	return RegUser::mpi;
}

void RegUser::setMpi(string mpi)
{
	RegUser::mpi = mpi;
}


void RegUser::ShowMpi()
{
	int i;
	for (i = 0; i < 32; i++) printf("%02x", (unsigned char)RegUser::mpi[i]);
	printf("\n");
}
#pragma endregion

#pragma region BackUser
BackUser::BackUser()
{
	BackUser::fi = "";
}
BackUser::BackUser(string fi, string hi, int ki)
{
	BackUser::fi = fi;
	BackUser::hi = hi;
	BackUser::ki = ki;
}


string BackUser::getFi()
{
	return BackUser::fi;
}

void BackUser::setFi(string fi)
{
	BackUser::fi = fi;
}

string BackUser::getHi()
{
	return BackUser::hi;
}

void BackUser::setHi(string hi)
{
	BackUser::hi = hi;
}

int BackUser::getKi()
{
	return BackUser::ki;
}

void BackUser::setKi(int ki)
{
	BackUser::ki = ki;
}
#pragma endregion


#pragma region M1
Message1::Message1(ECn a, int ki, string m2, int t1)
{
	Message1::A = a;
	Message1::ki = ki;
	Message1::m2 = m2;	
	Message1::t1 = t1;
}
ECn Message1::getA()
{
	return Message1::A;
}
void Message1::setA(ECn a)
{
	Message1::A = a;
}

string Message1::getM2()
{
	return Message1::m2;
}

void Message1::setM2(string m2)
{
	Message1::m2 = m2;
}

int Message1::getKi()
{
	return Message1::ki;
}

void Message1::setKi(int ki)
{
	Message1::ki = ki;
}

int Message1::getT1()
{
	return Message1::t1;
}

void Message1::setT1(int t1)
{
	Message1::t1 = t1;
}

#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(ECn b, string m4)
{
	Message2::B = b;
	Message2::m4 = m4;
}

ECn Message2::getB()
{
	return Message2::B;
}
void Message2::setB(ECn b)
{
	Message2::B = b;
}

string Message2::getM4()
{
	return Message2::m4;
}

void Message2::setM4(string m4)
{
	Message2::m4 = m4;
}
#pragma endregion



#pragma region Message333
MsgChaningPassword::MsgChaningPassword()
{
}
MsgChaningPassword::MsgChaningPassword(int ki, string m2, int t1)
{
	MsgChaningPassword::ki = ki;
	MsgChaningPassword::m2 = m2;
	MsgChaningPassword::t1 = t1;
}

int MsgChaningPassword::getKi() {
	return MsgChaningPassword::ki;
}

string MsgChaningPassword::getM2() {
	return MsgChaningPassword::m2;
}

void MsgChaningPassword::setKi(int ki) {
	MsgChaningPassword::ki = ki;
}
void MsgChaningPassword::setM2(string m2) {
	MsgChaningPassword::m2 = m2;
}
int MsgChaningPassword::getT1()
{
	return MsgChaningPassword::t1;
}

void MsgChaningPassword::setT1(int t1)
{
	MsgChaningPassword::t1 = t1;
}

#pragma endregion


#pragma region Message4
MsgBackChaningPassword::MsgBackChaningPassword()
{
}
MsgBackChaningPassword::MsgBackChaningPassword(string m3)
{
	MsgBackChaningPassword::m3 = m3;
}

string MsgBackChaningPassword::getM3() {
	return MsgBackChaningPassword::m3;
}

void MsgBackChaningPassword::setM3(string m3) {
	MsgBackChaningPassword::m3 = m3;
}
#pragma endregion




