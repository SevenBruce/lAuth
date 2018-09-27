#include "gateway.h"

Gateway::Gateway(ECn g, Big p)
{
	Gateway::g = g;
	Gateway::ids = randonIdentity();
	Gateway::x = randomString(HASH_MESSAGE_LENGH);
	Gateway::p = p;
}

BackUser Gateway::getRegUser(RegUser reg)
{
	int ei = randonIntegerNumber();
	string B1_ = xor (reg.getHi(), xor(hashSha256(to_string(Gateway::ids) + Gateway::x + to_string(ei)), hashSha256(to_string(reg.getIdi()) + to_string(ei))));
	string B2_ = xor (hashSha256(to_string(reg.getIdi()) + Gateway::x) , reg.getHi());
	//cout << "key gateway : " << (hashSha256(Gateway::ids + Gateway::x + ei)) << endl;
	//cout << "B1 : " << B1_ << endl;
	//cout << "B2 : " << B2_ << endl;

	BackUser backUser(ei, B1_, B2_);
	return backUser;
}



Message2 Gateway::getM1(Message1 m1)
{
	string ui1 = xor ( m1.getC2(), hashSha256(to_string(Gateway::ids) + Gateway::x + to_string(m1.getEi())));
	//cout << "key : " << (hashSha256(Gateway::ids + Gateway::x + m1.getEi())) << endl;
	//cout << "C2 :  " <<  m1.getC2() << endl;
	//cout << "ui1 : " << ui1 << endl;

	string temStr = decryption(m1.getC5(), ui1);
	
	string idi = to_string(string2Identity(temStr.substr(0, IDENTITY_LENGTH)));
	string c41 = temStr.substr(IDENTITY_LENGTH);
	//cout << "idi : " << idi <<endl;
	//cout << "c41 : " << c41 << endl;
	string C31 = hashSha256(idi + Gateway::x);

	string temC41 = hashSha256(ecn2String(m1.getC1()) + m1.getC2() + C31 + to_string(m1.getEi()) + ui1 );

	if (temC41 != c41) {
		cout<<"temC41 from user not equal at gateway side"<<endl;
		system("pause");
	}

	int eiNew = randonIntegerNumber();
	string hashIdiX = hashSha256(idi + Gateway::x);
	string c6 = xor(hashSha256(to_string(Gateway::ids) + Gateway::x + to_string(eiNew)), hashIdiX);

	Big beta = rand(Gateway::p);
	ECn C7 = Gateway::g;
	C7 *= beta;

	//cout << endl;
	//cout << "int2String(m1.getEi()) : " << m1.getEi() << endl;
	//cout << "m1.getC2()  : " << m1.getC2() << endl;

	string c8 = xor(   xor ( int2String(m1.getEi()), m1.getC2() ), int2String(eiNew)   );
	string c9 = xor (hashIdiX, ui1);

	ECn temKey = m1.getC1();
	temKey *= beta;
	//Big key;
	//temKey.get(key);

	string sks = hashSha256(ecn2String(m1.getC1()) + ecn2String(C7) + ecn2String(temKey));

	string C10 = hashSha256(idi + to_string(Gateway::ids) + c6 + c8 + c9 + sks + to_string(eiNew));
	string C11 = encryption( c6 + c8 + C10, c9);

	//cout << endl;
	//cout << "c61 : " << c6 << endl;
	//cout << "c81  : " << c8 << endl;
	

	//cout << endl;
	//cout << "eiNew : " << eiNew << endl;
	//cout << "sku  : " << sks << endl;
	//cout << "c9  : " << c9 << endl;
	//cout << "ids  : " << ids << endl;
	//cout << "idi  : " << idi << endl;
	//cout << "c61 : " << c6 << endl;
	//cout << "c81 : " << c8 << endl;
	//cout << "c101 : " << C10 << endl;

	return Message2(C7, C11);
}


MsgBackChaningPassword Gateway::getChangingPassword(MsgChaningPassword mc)
{
	string ui1 = xor (hashSha256(to_string(Gateway::ids) + Gateway::x + to_string(mc.getEi()) ), mc.getC2());
	//cout << "key : " << (hashSha256(Gateway::ids + Gateway::x + m1.getEi())) << endl;
	//cout << "C2 :  " <<  m1.getC2() << endl;
	//cout << "ui1 : " << ui1 << endl;

	string temStr = decryption(mc.getC5(), ui1);

	string idi = to_string(string2Identity(temStr.substr(0, IDENTITY_LENGTH)));
	string c41 = temStr.substr(IDENTITY_LENGTH);
	//cout << "idi : " << idi <<endl;
	//cout << "c41 : " << c41 << endl;
	string C31 = hashSha256(idi + Gateway::x);
	string temC41 = hashSha256(ecn2String(mc.getC1()) + mc.getC2() + C31 + to_string(mc.getEi()) + ui1);

	if (temC41 != c41) {
		cout << "temC41 from user not equal at gateway side password" << endl;
		system("pause");
	}
	//string eiNew = randomString(RANDOM_STRING_LENGTH);
	//string hashIdiX = hashSha256(idi + Gateway::x);
	//string c6 = xor (hashSha256(Gateway::ids + Gateway::x + eiNew), hashIdiX);

	//Big beta = rand(Gateway::p);
	//ECn C7 = Gateway::g;
	//C7 *= beta;

	//string c8 = xor (xor (m1.getEi(), m1.getC2()), eiNew);
	//string c9 = xor (hashIdiX, ui1);

	//ECn temKey = m1.getC1();
	//temKey *= beta;
	//Big key;
	//temKey.get(key);

	//string sks = hashSha256(ecn2String(m1.getC1()) + ecn2String(C7) + big2String(key));

	//string C10 = hashSha256(idi + Gateway::ids + c6 + c8 + c9 + sks + eiNew);
	//string C11 = encryption(c6 + c8 + C10, c9);

	//cout << endl;
	//cout << "c61 : " << c6 << endl;
	//cout << "c81  : " << c8 << endl;
	//cout << "c101 : " << C10 << endl;

	///*cout << endl;*/
	//cout << "eiNew : " << eiNew << endl;
	//cout << "sku  : " << sks << endl;
	//cout << "c9  : " << c9 << endl;
	//cout << "ids  : " << ids << endl;
	//cout << "idi  : " << idi << endl;
	string sa = hashSha256(ui1 + to_string(mc.getEi()) + C31 + mc.getC2() + ecn2String(mc.getC1()) );

	return MsgBackChaningPassword(sa, true);
}

unsigned short Gateway::getIds() {
	return Gateway::ids;
}


//void Gateway::clearIdentities() {
//	identities.clear();
//}
