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

unsigned short RegUser::getIdi()
{
	return RegUser::idi;
}

void RegUser::setIdi(unsigned short idi)
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
BackUser::BackUser(ECn AIDua, string BIDua)
{
	BackUser::AIDua = AIDua;
	BackUser::BIDua = BIDua;
}

ECn BackUser::getAIDua()
{
	return BackUser::AIDua;
}

void BackUser::setAIDua(ECn r)
{
	BackUser::AIDua = r;
}

void BackUser::setBIDua(string BIDua)
{
	BackUser::BIDua = BIDua;
}

string BackUser::getBIDua()
{
	return BackUser::BIDua;
}
#pragma endregion


#pragma region M1
Message1::Message1(string DIDua, ECn Qua, string EIDua)
{
	Message1::Qua = Qua;
	Message1::DIDua = DIDua;
	Message1::EIDua = EIDua;
}
ECn Message1::getQua()
{
	return Message1::Qua;
}
void Message1::setQua(ECn Qua)
{
	Message1::Qua = Qua;
}

string Message1::getEIDua()
{
	return Message1::EIDua;
}

void Message1::setEIDua(string EIDua)
{
	Message1::EIDua = EIDua;
}

string Message1::getDIDua()
{
	return Message1::DIDua;
}

void Message1::setDIDua(string idi)
{
	Message1::DIDua = idi;
}
#pragma endregion

#pragma region Message2
Message2::Message2()
{
}
Message2::Message2(string Tsb, string Hsb)
{
	Message2::Tsb = Tsb;
	Message2::Hsb = Hsb;
}

string Message2::getHsb()
{
	return Message2::Hsb;
}
void Message2::setHsb(string Hsb)
{
	Message2::Hsb = Hsb;
}

string Message2::getTsb()
{
	return Message2::Tsb;
}

void Message2::setTsb(string Tsb)
{
	Message2::Tsb = Tsb;
}
#pragma endregion

#pragma region Message333
Message3::Message3()
{
}
Message3::Message3(string Hua)
{
	Message3::Hua = Hua;
}

string Message3::getHua()
{
	return Message3::Hua;
}

void Message3::setHua(string Hua)
{
	Message3::Hua = Hua;
}
#pragma endregion



