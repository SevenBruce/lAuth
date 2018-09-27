#include "user.h"


User::User(ECn g, Big p, ECn mpk)
{
	User::IDua = randonIdentity();
	User::pwua = randomString(RANDOM_STRING_LENGTH);
	User::g = g;
	User::p = p;
	User::mpk = mpk;
}

RegUser User::generateReg()
{
	User::rua = randonIntegerNumber();
	User::mpi = string2Big(to_string(User::IDua) + User::pwua + to_string(User::rua));

	RegUser regUser = RegUser(User::IDua, User::mpi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::AIDua = backUser.getAIDua();
	User::BIDua = backUser.getBIDua();
}

Message1 User::generateM1()
{
	string BIDua1 = hashSha256(  big2String(string2Big(to_string(User::IDua))) + big2String(string2Big(to_string(User::IDua) + User::pwua + to_string(User::rua))) );
	if (BIDua1 != User::BIDua) {
		cout << "incorrect identity and password pair" << endl;
		system("pause");
	}

	User::qua = rand(p);
	User::Qua = User::g;
	User::Qua *= User::qua;

	User::Mua = User::mpk;
	User::Mua *= User::qua;
	string did = xor (identity2String(User::IDua), ecn2String(User::Mua));

	User::TIDua = User::AIDua;
	ECn tem = User::g;
	tem *= User::mpi;
	User::TIDua -= tem;
	User::EIDua = hashSha256(hashSha256(ecn2String(TIDua) + ecn2String(User::Mua))+ ecn2String(Qua) + ecn2String(User::Mua));

	Message1 message1(did, User::Qua, User::EIDua);
	return message1;
}

Message3 User::getM2(Message2 m2) {

	string temStr = xor ( m2.getTsb() , ecn2String(User::Mua));
	ECn Qsb1 = binary2Ecn(temStr);

	//cout  << endl;
	//cout << "temStr" << temStr << endl;
	//cout<< "Qsb1" << Qsb1 <<endl;
	//cout << "TIDua1" << TIDua << endl;
	//cout << endl; cout << endl;
	string hsb = hashSha256(User::EIDua + ecn2String(Qsb1) + ecn2String(User::TIDua));

	if (hsb != m2.getHsb()) {
		cout << "hsb from gateway at user side not equal" << endl;
		system("pause");
	}
	User::sk = hashSha256(ecn2String(User::Qua) + ecn2String(Qsb1) + ecn2String(User::Mua) + ecn2String(User::TIDua));

	string hua = hashSha256(ecn2String(User::Qua) + ecn2String(Qsb1));
	return Message3(hua);
}




