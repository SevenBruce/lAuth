#include "gateway.h"

Gateway::Gateway(ECn g, Big p)
{
	Gateway::g = g;
	Gateway::p = p;
	Gateway::xgwn = randomString(IDENTITY_LENGTH);
}

ECn Gateway::getG()
{
	return Gateway::g;
}

//bool Gateway::isInIdentieis(string idenity) {
//	vector<string>::iterator ret;
//
//	ret = std::find(identities.begin(), identities.end(), idenity);
//	if (ret == identities.end()) {
//		return false;
//	}
//	return true;
//}

BackUser Gateway::getRegUser(RegUser regUser)
{
	//if (isInIdentieis(regUser.getIdi())) {
	//	cout << "this identity already exists" << endl;
	//	system("pause");
	//}
	//identities.push_back(regUser.getIdi());

	string di = hashSha256(to_string(regUser.getIdi()) + Gateway::xgwn);
	string fi = xor (di, regUser.getMpi());

	
	int ki = randonIntegerNumber();
	string ei = hashSha256(to_string(ki) + Gateway::xgwn);
	string hi = xor (ei, regUser.getMpi());
	//cout << "di " << di << endl;
	//cout << "ei " << ei << endl;
	BackUser backUser(fi,hi, ki);
	return backUser;
}



Message2 Gateway::getM1(Message1 m1)
{
	//authentication of the user
	timeDeal(m1.getT1(), "T1 from sensor");

	string ei = hashSha256(to_string(m1.getKi()) + Gateway::xgwn);
	string temStr = xor (m1.getM2(), ei);
	
	string idi = to_string( string2Identity( temStr.substr(0, IDENTITY_LENGTH) ) );
	string m1m1 = temStr.substr(IDENTITY_LENGTH);

	string di = hashSha256(idi + Gateway::xgwn);

	////test of hash
	//cout << "ecn2String(m1.getA()) " << ecn2String(m1.getA()) << endl;
	//cout << "idi " << idi << endl;
	//cout << "to_string(m1.getKi()) " << to_string(m1.getKi()) << endl;
	//cout << "di " << di << endl;
	//string temM1 = hashSha256(ecn2String(m1.getA()) + idi + to_string(m1.getKi()) + di + to_string(m1.getT1()));
	//if (temM1 != m1m1) {
	//	cout<<"m1m1 from user not equal at gateway side"<<endl;
	//	system("pause");
	//}
		
	Big k2 = rand(Gateway::p);
	ECn B = Gateway::g;
	B *= k2;

	ECn temKey = m1.getA();
	temKey *= k2;

	string sk = hashSha256(ecn2String(temKey) + to_string(m1.getT1()));

	int kiNew = randonIntegerNumber();
	string eiNew = hashSha256( to_string(kiNew) + Gateway::xgwn);

	//cout << "ecn2String(B) " << ecn2String(B) << endl;
	//cout << "eiNew " << eiNew << endl;
	//cout << " to_string(kiNew) " << to_string(kiNew) << endl;
	//cout << "di " << di << endl;
	//cout << "User::skij " << sk << endl;
	string m3m3 = hashSha256(ecn2String(B) + eiNew + to_string(kiNew) + di + sk);

	temStr = eiNew + int2String(kiNew) + m3m3;

	string m4m4 = xor(temStr, hashSha256(di + to_string(m1.getT1())));
	return Message2(B, m4m4);
}


MsgBackChaningPassword Gateway::getChangingPassword(MsgChaningPassword mc)
{
	//authentication of the user
	timeDeal(mc.getT1(), "T1 from sensor");

	string ei = hashSha256(to_string(mc.getKi()) + Gateway::xgwn);
	string temStr = xor (mc.getM2(), ei);

	string idi = to_string(string2Identity(temStr.substr(0, IDENTITY_LENGTH)));
	string m1m1 = temStr.substr(IDENTITY_LENGTH);

	string di = hashSha256(idi + Gateway::xgwn);
	string temM1 = hashSha256(idi + to_string(mc.getKi()) + di + to_string(mc.getT1()));
	if (temM1 != m1m1) {
		cout << "m1m1 from user not equal at gateway side" << endl;
		system("pause");
	}
	string m3m3 = hashSha256(idi + di + to_string(mc.getKi()) + to_string(mc.getT1()));

	return MsgBackChaningPassword(m3m3);
}


//
//void Gateway::clearIdentities() {
//	identities.clear();
//}
