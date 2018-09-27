#include "user.h"


User::User()
{
	User::idi = randonIdentity();
	User::pwi = randomString(RANDOM_STRING_LENGTH);
	//cout << "idi : " << idi << endl;
}

User::User(ECn g, Big p)
{
	User::idi = randonIdentity();
	User::pwi = randomString(RANDOM_STRING_LENGTH);
	User::g = g;
	User::p = p;
}


RegUser User::generateReg()
{
	User::ri = randonIntegerNumber();
	User::mpi = (hashSha256(int2String(User::ri) + to_string(User::idi) + User::pwi));

	RegUser regUser = RegUser(User::idi, User::mpi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::ki = backUser.getKi();
	User::hi = backUser.getHi();
	User::fi = backUser.getFi();
}

Message1 User::generateM1()
{
	User::di = xor (User::fi, User::mpi);
	User::ei = xor (User::hi, User::mpi);

	//cout << "di " << di << endl;
	//cout << "ei " << ei << endl;

	User::k1 = rand(User::p);
	User::A = User::g;
	User::A *= User::k1;
	//cout << "idi " << to_string(User::idi) << endl;
	User::timeStamp = time(NULL);

	//test of hash
	/*cout << "ecn2String(m1.getA()) " << ecn2String(User::A) << endl;
	cout << "idi " << to_string(User::idi) << endl;
	cout << "to_string(m1.getKi()) " << to_string(User::ki) << endl;
	cout << "di " << User::di << endl;*/
	string m1m1 = hashSha256(ecn2String(User::A) + to_string(User::idi) + to_string(User::ki) + User::di + std::to_string(User::timeStamp));
	User::m2m2 = xor (identity2String(User::idi) + m1m1, User::ei);

	Message1 message1(User::A, User::ki, User::m2m2, User::timeStamp);
	return message1;
}

void User::getM2(Message2 m2) {

	ECn temKey = m2.getB();
	temKey *= User::k1;

	User::skij = hashSha256(ecn2String(temKey) + to_string(User::timeStamp));

	string temStr = xor (m2.getM4(), hashSha256(User::di + to_string(User::timeStamp)));

	string eiNew = temStr.substr(0, HASH_MESSAGE_LENGH);
	int kiNew = string2int(temStr.substr(HASH_MESSAGE_LENGH, RANDOM_NUMBER_LENGTH));
	string m3m3 = temStr.substr(HASH_MESSAGE_LENGH + RANDOM_NUMBER_LENGTH, HASH_MESSAGE_LENGH);

	//cout << endl; cout << endl;
	//cout << "ecn2String(B) " << ecn2String(m2.getB()) << endl;
	//cout << "eiNew " << eiNew << endl;
	//cout << " to_string(kiNew) " << to_string(kiNew) << endl;
	//cout << "di " << User::di << endl;
	//cout << "User::skij " << User::skij << endl;
	string temM3 = hashSha256(ecn2String(m2.getB()) + eiNew + to_string(kiNew) + User::di + User::skij);
	if (temM3 != m3m3) {
		cout << "m3m3 from gateway at user side not equal" << endl;
		system("pause");
	}
	User::ki = kiNew;
	User::hi = xor (eiNew, User::mpi);
}


MsgChaningPassword User::generateChaningPassword()
{
	User::di = xor (User::fi, User::mpi);
	User::ei = xor (User::hi, User::mpi);

	User::timeStamp = time(NULL);
	string m1m1 = hashSha256(to_string(User::idi) + to_string(User::ki)  + User::di + std::to_string(User::timeStamp));
	User::m2m2 = xor (identity2String(User::idi) + m1m1, User::ei);

	MsgChaningPassword msg(User::ki, User::m2m2, User::timeStamp);
	return msg;
}

void User::getChaningPasswordBack(MsgBackChaningPassword backMsg)
{
	string temM3 = hashSha256(to_string(User::idi) + di + to_string(User::ki) + std::to_string(User::timeStamp));
	if (temM3 != backMsg.getM3()) {
		cout << "temM3 from gateway not equal at user side" << endl;
		system("pause");
	}

	User::pwi = randomString(RANDOM_STRING_LENGTH);
	
	User::di = xor (User::fi, User::mpi);
	User::ei = xor (User::hi, User::mpi);

	User::mpi = (hashSha256(int2String(User::ri) + to_string(User::idi) + User::pwi));
	User::fi = xor (User::di, User::mpi);
	User::hi = xor (User::ei, User::mpi);
}





