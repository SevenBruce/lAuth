#include "gateway.h"

Gateway::Gateway(ECn g, Big p)
{
	Gateway::g = g;
	Gateway::p = p;
	Gateway::s = rand(p);
}

BackUser Gateway::getRegUser(RegUser regUser)
{
	ECn r = Gateway::g;
	Big tem = regUser.getMpi() + string2Big(to_string(regUser.getIdi()) + big2String(Gateway::s));
	r *= tem;

	BackUser backUser(r);
	return backUser;
}


Message2 Gateway::getM1(Message1 m1)
{
	ECn v2 = m1.getV();
	string idi = to_string(m1.getIdi());
	v2 *= string2Big(idi + big2String(Gateway::s));
	Gateway::w1 = hashSha256( idi + ecn2String(m1.getV()) + ecn2String(v2));

	if (w1 != m1.getW()) {
		cout << "m1m1 from user not equal at gateway side" << endl;
		system("pause");
	}

	Big c = rand(p);
	ECn C = Gateway::g;
	C *= c;

	Gateway::temKey = m1.getV();
	Gateway::temKey *= c;

	Gateway::r = rand(p);
	Gateway::sk = hashSha256(ecn2String(Gateway::temKey) + big2String(r) + idi);

	string auths = hashSha256(ecn2String(Gateway::temKey) + w1 + big2String(r) + Gateway::sk);

	return Message2(C, r, auths);
}

void Gateway::getM3(Message3 m3) {
	string authu = hashSha256(ecn2String(Gateway::temKey) + Gateway::w1 + big2String(Gateway::r + 1) + Gateway::sk);
	if (authu != m3.getAuthu()) {
		cout << "authu from user not equal at gateway side" << endl;
		system("pause");
	}
}

MsgBackChaningPassword Gateway::getChangingPassword(MsgChaningPassword mc)
{
	string temStr = decryption(mc.getC1(), Gateway::sk);
	
	/*cout << temStr.length() << endl;*/

	string idi = to_string(string2Identity(temStr.substr(0, IDENTITY_LENGTH)));

	int len = string2__int8( temStr.substr(IDENTITY_LENGTH,1) );
	string N = temStr.substr(IDENTITY_LENGTH, len + 1);

	int start = IDENTITY_LENGTH + len + 1;
	len = string2__int8( temStr.substr(start,1) );
	string mpi = temStr.substr(start, len + 1);

	string temHash = temStr.substr(start + len + 1, HASH_MESSAGE_LENGH);
	//cout << start + len * 2 + 2 + HASH_MESSAGE_LENGH << endl;
	//cout << endl;
	//cout << "Gateway::sk " << Gateway::sk << endl;
	//cout << "idi " << idi << "    " << idi.length() << endl;
	//cout << "N " << N <<"    " << N.length() << endl;
	//cout << "mpi " << mpi << "    " << mpi.length() << endl;
	//cout << "temHash " << temHash <<"    " << temHash.length() << endl;
	//cout << "********************************************************************************" << endl;

	Big NBig = binary2Big(N);
	//cout << "N    is : " << big2Binary(NBig) << endl;
	NBig += 1;
	//cout << "N    is : " << big2Binary(NBig) << endl;

	//hashSha256(User::idi + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + User::aNew)));
	string temM1 = hashSha256(idi + N + mpi);

	//cout << endl; cout << endl;
	//cout << "mc.getC1().length() " << mc.getC1().length() << endl;
	//cout << "idi " << idi << endl;
	//cout << "N " << binary2Big(N) << endl;
	//cout << "mpi " << binary2Big(mpi) << endl;
	//cout << "temHash "; coutHash(temHash); cout << temHash.length() << endl;

	//cout <<  "********************************************************************************" << endl;
	//cout <<  "R len " << temStr.length() << endl;
	////cout << "G len " << start + len * 2 + 2 + HASH_MESSAGE_LENGH << endl;
	//cout << endl;
	//cout << "temHash " << temHash << "    " << temHash.length() << endl;
	//cout << "temM1   " << temM1 << "    " << temM1.length() << endl;

	if (temM1 != temHash) {
		cout << "password change from user not equal at gateway side" << endl;
		system("pause");
	}

	ECn R = Gateway::g;
	Big mpiBig = binary2Big(mpi) + string2Big(idi + big2String(Gateway::s));
	R *= mpiBig;

	//cout << "idi is : " << idi << endl;
	////cout << "tem is : "; coutHash(temC2); cout << endl;
	//cout << "N    is : " << big2Binary(NBig) << endl;
	//cout << "R    is : " << ecn2BinaryString(R) << endl;
	//string m3m3 = hashSha256(idi + di + mc.getKi() + to_string(mc.getT1()));
	//cout << "hash is : "; coutHash(hashSha256(idi + big2String(NBig) + ecn2BinaryString(R)));cout << endl;
	
	string temC2 = ecn2BinaryString(R) + hashSha256(idi + big2String(NBig) + ecn2BinaryString(R));
	string C2 = encryption(temC2, Gateway::sk);
	return MsgBackChaningPassword(C2);
}