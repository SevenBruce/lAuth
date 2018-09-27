#include "messages.h"

#pragma region RegUser
RegUser::RegUser()
{
}

RegUser::RegUser(unsigned short idi, Big mpi)
{
	RegUser::idi = idi;
	RegUser::mpi = mpi;
}

unsigned short  RegUser::getIdi()
{
	return RegUser::idi;
}

void RegUser::setIdi(unsigned short  idi)
{
	RegUser::idi = idi;
}

Big RegUser::getMpi()
{
	return RegUser::mpi;
}

void RegUser::setMpi(Big mpi)
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
}
BackUser::BackUser(ECn r)
{
	BackUser::r = r;
}

ECn BackUser::getR()
{
	return BackUser::r;
}

void BackUser::setR(ECn r)
{
	BackUser::r = r;
}
#pragma endregion


#pragma region M1
Message1::Message1(unsigned short idi, ECn v, string w)
{
	Message1::V = v;
	Message1::idi = idi;
	Message1::w = w;
}
ECn Message1::getV()
{
	return Message1::V;
}
void Message1::setV(ECn v)
{
	Message1::V = v;
}

string Message1::getW()
{
	return Message1::w;
}

void Message1::setW(string w)
{
	Message1::w = w;
}

unsigned short Message1::getIdi()
{
	return Message1::idi;
}

void Message1::setIdi(unsigned short idi)
{
	Message1::idi = idi;
}
#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(ECn c, Big r, string auths)
{
	Message2::C = c;
	Message2::r = r;
	Message2::auths = auths;
}

ECn Message2::getC()
{
	return Message2::C;
}
void Message2::setC(ECn c)
{
	Message2::C = c;
}

Big Message2::getR()
{
	return Message2::r;
}
void Message2::setR(Big r)
{
	Message2::r = r;
}

string Message2::getAuths()
{
	return Message2::auths;
}

void Message2::setAuths(string auths)
{
	Message2::auths = auths;
}
#pragma endregion

#pragma region Message333
Message3::Message3()
{
}
Message3::Message3(string authu)
{
	Message3::authu = authu;
}

string Message3::getAuthu()
{
	return Message3::authu;
}

void Message3::setAuthu(string authu)
{
	Message3::authu = authu;
}
#pragma endregion

#pragma region Message333
MsgChaningPassword::MsgChaningPassword()
{
}
MsgChaningPassword::MsgChaningPassword(string c1, Big N)
{
	MsgChaningPassword::c1 = c1;
	MsgChaningPassword::N = N;
}

void MsgChaningPassword::setN(Big N) {
	MsgChaningPassword::N = N;
}

Big MsgChaningPassword::getN() {
	return MsgChaningPassword::N;
}

string MsgChaningPassword::getC1() {
	return MsgChaningPassword::c1;
}
void MsgChaningPassword::setC1(string c1) {
	MsgChaningPassword::c1 = c1;
}


#pragma endregion


#pragma region Message4
MsgBackChaningPassword::MsgBackChaningPassword()
{
}
MsgBackChaningPassword::MsgBackChaningPassword(string c2)
{
	MsgBackChaningPassword::c2 = c2;
}

string MsgBackChaningPassword::getC2() {
	return MsgBackChaningPassword::c2;
}

void MsgBackChaningPassword::setC2(string c2) {
	MsgBackChaningPassword::c2 = c2;
}
#pragma endregion




