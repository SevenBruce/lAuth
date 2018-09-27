#include "entities.h"


#pragma region User
User::User(ECn g)
{
	User::idi = randomString(RANDOM_STRING_LENGTH);
	User::pwi = randomString(RANDOM_STRING_LENGTH);
	User::ri = randomString(RANDOM_STRING_LENGTH);

	User::mpi = (hashSha256(User::ri + User::idi + User::pwi));
	User::g = g;
}

RegUser User::generateReg()
{
	RegUser regUser = RegUser();
	regUser.setIdi(User::idi);
	regUser.setMpi(User::mpi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::fi = backUser.getFi();
	User::ki = backUser.getKi();
	User::li = backUser.getLi();
}

void User::setSidj(string sidj)
{
	User::sidj = sidj;
}

Message1 User::generateM1()
{
	User::di = xor (User::fi, User::mpi);
	User::ei = xor (User::li, User::mpi);

	User::k1 = rand(160, 2);
	//cout << "k1:" << k1 << endl;
	User::A = User::g;
	User::A *= User::k1;

	User::timeStamp = time(NULL);
	string m2m2 = hashSha256(ecn2String(User::A) + User::idi + User::sidj + User::di + std::to_string(User::timeStamp));
	string m1m1 = xor ((User::idi + User::sidj + m2m2), ei);

	Message1 message1(User::A, User::ki, m1m1, User::timeStamp);
	return message1;
}

void User::getM4(Message4 m4) {
	string temStr = xor (m4.getM6(), User::ei);
	string einew = temStr.substr(0, HASH_MESSAGE_LENGH);
	string k3 = temStr.substr(HASH_MESSAGE_LENGH, RANDOM_STRING_LENGTH);
	string m7Tem = temStr.substr((HASH_MESSAGE_LENGH + RANDOM_STRING_LENGTH));

	ECn temKey = m4.getB();
	temKey *= User::k1;
	Big key;
	temKey.get(key);
	User::skij = hashSha256(big2String(key));
	//cout << "key: "; cout << ecn2String(temKey) << endl;
	cout << "Usssor::skij: "; coutHash(User::skij);

	string m4m4 = hashSha256(ecn2String(User::A) + User::skij + ecn2String(m4.getB()));
	string m7m7 = hashSha256(einew + k3 + User::di + std::to_string(User::timeStamp) + m4m4);

	if (m7m7 != m7Tem) {
		cout << "m7 not equal, exit(7)" << endl;
		system("pause");
	}
	User::ki = k3;
	User::li = xor (einew, User::mpi);
}
#pragma endregion

#pragma region Gateway
Gateway::Gateway()
{
	Gateway::xgwn = randomString(RANDOM_STRING_LENGTH);
}

ECn Gateway::getG()
{
	return Gateway::g;
}

BackUser Gateway::getRegUser(RegUser regUser)
{
	BackUser backUser;
	string di = (hashSha256(regUser.getIdi() + Gateway::xgwn));
	backUser.setFi(xor (di, regUser.getMpi()));

	string ki = randomString(RANDOM_STRING_LENGTH);
	backUser.setKi(ki);

	string ei = hashSha256(ki + Gateway::xgwn);
	backUser.setLi(xor (ei, regUser.getMpi()));

	return backUser;
}


BackSensor Gateway::getRegSensor(RegSensor regSensor)
{
	string xj = (hashSha256(regSensor.getSidj() + Gateway::xgwn));
	BackSensor backSensor(xj);
	return backSensor;
}


Message2 Gateway::getM1(Message1 m1)
{
	//authentication of the user
	timeDeal(m1.getT1(), "T1");

	Gateway::ei = hashSha256(m1.getKi() + Gateway::xgwn);
	string temStr = xor (m1.getM1(), ei);

	Gateway::idi = temStr.substr(0, RANDOM_STRING_LENGTH);
	Gateway::di = hashSha256(Gateway::idi + Gateway::xgwn);
	Gateway::sidj = temStr.substr(RANDOM_STRING_LENGTH, RANDOM_STRING_LENGTH);
	Gateway::xj = hashSha256(Gateway::sidj + Gateway::xgwn);

	string m2m2 = temStr.substr(RANDOM_STRING_LENGTH * 2);

	//check if m2' equals to hash
	string tem = hashSha256(ecn2String(m1.getA()) +
		Gateway::idi +
		Gateway::sidj +
		Gateway::di +
		std::to_string(m1.getT1())
	);
	if (tem != m2m2) {
		cout << "hash M2 test not pass, exit(2)" << endl;
		system("pause");
	}

	// the generation of Message 2
	Gateway::timeStamp1 = m1.getT1();
	Gateway::A = m1.getA();

	Gateway::timeStamp2 = time(NULL);
	Gateway::m3 = hashSha256(ecn2String(Gateway::A) + Gateway::sidj + Gateway::xj + std::to_string(Gateway::timeStamp2));

	Message2 m2(Gateway::A, Gateway::m3, Gateway::timeStamp2);
	return m2;
}

Message4 Gateway::getM3(Message3 m3) {
	string m5m5 = hashSha256(
		ecn2String(Gateway::A) + Gateway::xj + Gateway::m3 + m3.getM4() + ecn2String(m3.getB()));
	if (m5m5 != m3.getM5()) {
		cout << "m5 not equal, exist(0)" << endl;
		system("pause");
	}

	string k3 = randomString(RANDOM_STRING_LENGTH);
	string einew = hashSha256(k3 + Gateway::xgwn);
	string m7m7 = hashSha256(einew + k3 + Gateway::di + std::to_string(Gateway::timeStamp1) + m3.getM4());
	string m6m6 = xor ((einew + k3 + m7m7), Gateway::ei);

	Message4 m4(m3.getB(), m6m6);
	return m4;
}
#pragma endregion


#pragma region Sensor
Sensor::Sensor(ECn g)
{
	Sensor::sidj = randomString(RANDOM_STRING_LENGTH);
	Sensor::g = g;
}
string Sensor::getSidj()
{
	return Sensor::sidj;
}

RegSensor Sensor::generateRegSensor()
{
	RegSensor regSensor(Sensor::sidj);
	return regSensor;
}

void Sensor::getBackSensor(BackSensor backSensor)
{
	Sensor::xj = backSensor.getXj();
}

Message3 Sensor::getM2(Message2 m2)
{
	timeDeal(m2.getT2(), "T2");

	string m3m3 = hashSha256(ecn2String(m2.getA()) + Sensor::sidj + Sensor::xj + std::to_string(m2.getT2()));
	if (m2.getM3() != m3m3) {
		cout << "m2 not equal." << endl;
		system("pause");
	}

	Sensor::k2 = rand(160, 2);
	//cout << "k2:" << k2 << endl;
	Sensor::B = Sensor::g;
	Sensor::B *= Sensor::k2;

	ECn temKey = m2.getA();
	temKey *= Sensor::k2;
	Big key;
	temKey.get(key);
	Sensor::skij = hashSha256(big2String(key));
	//cout << "key: "; cout << big2String(key) << endl;;
	cout << "Sensor::skij: "; coutHash(Sensor::skij);

	string m4m4 = hashSha256(ecn2String(m2.getA()) + Sensor::skij + ecn2String(Sensor::B));
	string m5m5 = hashSha256(ecn2String(m2.getA()) + Sensor::xj + m2.getM3() + m4m4 + ecn2String(Sensor::B));

	Message3 m3(Sensor::B, m4m4, m5m5);
	return m3;
}

#pragma endregion
