#include "messages.h"

#pragma region RegUser
RegUser::RegUser()
{
}

RegUser::RegUser(unsigned short idi, string mpi)
{
	RegUser::idi = idi;
	RegUser::Hi = mpi;
}

unsigned short RegUser::getIdi()
{
	return RegUser::idi;
}

void RegUser::setIdi(unsigned short idi)
{
	RegUser::idi = idi;
}

string RegUser::getHi()
{
	return RegUser::Hi;
}

void RegUser::setHi(string Hi)
{
	RegUser::Hi = Hi;
}
#pragma endregion

#pragma region BackUser
BackUser::BackUser()
{
}
BackUser::BackUser(int ei, string B1_, string B2_)
{
	BackUser::ei = ei;
	BackUser::B1_ = B1_;
	BackUser::B2_ = B2_;
}


int BackUser::getEi()
{
	return BackUser::ei;
}

void BackUser::setEi(int ei)
{
	BackUser::ei = ei;
}

string BackUser::getB1_()
{
	return BackUser::B1_;
}

void BackUser::setB1_(string B1_)
{
	BackUser::B1_ = B1_;
}

string BackUser::getB2_()
{
	return BackUser::B2_;
}

void BackUser::setB2_(string B2_)
{
	BackUser::B2_ = B2_;
}

#pragma endregion


#pragma region M1
Message1::Message1(ECn c1, string c2, string c5, int ei)
{
	Message1::C1 = c1;
	Message1::C2 = c2;
	Message1::C5 = c5;
	Message1::ei = ei;
}
ECn Message1::getC1()
{
	return Message1::C1;
}
void Message1::setC1(ECn C1)
{
	Message1::C1 = C1;
}

string Message1::getC2()
{
	return Message1::C2;
}

void Message1::setC2(string C2)
{
	Message1::C2 = C2;
}

string Message1::getC5()
{
	return Message1::C5;
}

void Message1::setC5(string C5)
{
	Message1::C5 = C5;
}

int Message1::getEi()
{
	return Message1::ei;
}

void Message1::setEi(int ei)
{
	Message1::ei = ei;
}

#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(ECn C7, string C11)
{
	Message2::C7 = C7;
	Message2::C11 = C11;
}

ECn Message2::getC7()
{
	return Message2::C7;
}
void Message2::setC7(ECn C7)
{
	Message2::C7 = C7;
}

string Message2::getC11()
{
	return Message2::C11;
}

void Message2::setC11(string C11)
{
	Message2::C11 = C11;
}
#pragma endregion



#pragma region Message333
MsgChaningPassword::MsgChaningPassword()
{
}
MsgChaningPassword::MsgChaningPassword(ECn c1, string c2, string c5, int ei, bool request)
{
	MsgChaningPassword::C1 = c1;
	MsgChaningPassword::C2 = c2;
	MsgChaningPassword::C5 = c5;
	MsgChaningPassword::ei = ei;
	MsgChaningPassword::request = request;
}

ECn MsgChaningPassword::getC1()
{
	return MsgChaningPassword::C1;
}
void MsgChaningPassword::setC1(ECn C1)
{
	MsgChaningPassword::C1 = C1;
}

string MsgChaningPassword::getC2()
{
	return MsgChaningPassword::C2;
}

void MsgChaningPassword::setC2(string C2)
{
	MsgChaningPassword::C2 = C2;
}

string MsgChaningPassword::getC5()
{
	return MsgChaningPassword::C5;
}

void MsgChaningPassword::setC5(string C5)
{
	MsgChaningPassword::C5 = C5;
}

int MsgChaningPassword::getEi()
{
	return MsgChaningPassword::ei;
}

void MsgChaningPassword::setEi(int ei)
{
	MsgChaningPassword::ei = ei;
}


bool MsgChaningPassword::getRequest()
{
	return MsgChaningPassword::request;
}

void MsgChaningPassword::setRequest(bool request)
{
	MsgChaningPassword::request = request;
}
#pragma endregion


#pragma region Message4
MsgBackChaningPassword::MsgBackChaningPassword()
{
}
MsgBackChaningPassword::MsgBackChaningPassword(string m3, bool permission)
{
	MsgBackChaningPassword::Sa = m3;
	MsgBackChaningPassword::permission = permission;
}

string MsgBackChaningPassword::getSa() {
	return MsgBackChaningPassword::Sa;
}

void MsgBackChaningPassword::setSa(string Sa) {
	MsgBackChaningPassword::Sa = Sa;
}

bool MsgBackChaningPassword::getPermission()
{
	return MsgBackChaningPassword::permission;
}

void MsgBackChaningPassword::setPermission(bool permission)
{
	MsgBackChaningPassword::permission = permission;
}
#pragma endregion




