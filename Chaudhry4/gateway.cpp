#include "gateway.h"

Gateway::Gateway(ECn g, Big p)
{
	Gateway::g = g;
	Gateway::p = p;

	Gateway::msk = rand(p);
	Gateway::mpk = g;
	Gateway::mpk *= Gateway::msk;
}

ECn Gateway::getMpk()
{
	return Gateway::mpk;
}

BackUser Gateway::getRegUser(RegUser regUser)
{
	ECn AIDua = Gateway::g;
	Big tem = regUser.getMpi() + string2Big(   xor(big2String(Gateway::msk), to_string(regUser.getIdi()))   );
	AIDua *= tem;

	string BIDua = hashSha256(  big2String(  string2Big(to_string(regUser.getIdi()))  ) + big2String(regUser.getMpi())  );

	BackUser backUser(AIDua, BIDua);
	return backUser;
}

Message2 Gateway::getM1(Message1 m1)
{
	Gateway::Qua1 = m1.getQua();
	ECn Mua1 = m1.getQua();
	Mua1 *= Gateway::msk;

	string IDua = to_string(string2Identity(xor (m1.getDIDua(), ecn2String(Mua1))));

	ECn TIDua1 = Gateway::g;
	TIDua1 *= string2Big(xor (big2String(Gateway::msk), IDua));

	string temEIDua = hashSha256(hashSha256(ecn2String(TIDua1) + ecn2String(Mua1)) + ecn2String(m1.getQua()) + ecn2String(Mua1));
	if (temEIDua != m1.getEIDua()) {
		cout << "temEIDua from user not equal at gateway side" << endl;
		system("pause");
	}

	Big qsb = rand(p);
	Gateway::Qsb = Gateway::Qua1;
	Gateway::Qsb *= qsb;

	Gateway::sk = hashSha256(ecn2String(Gateway::Qua1) + ecn2String(Gateway::Qsb) + ecn2String(Mua1) + ecn2String(TIDua1));

	//string temStr = ecn2BinaryString(Gateway::Qsb);
	string tsb = xor ( ecn2BinaryString(Gateway::Qsb),ecn2String(Mua1));

	string Hsb = hashSha256(temEIDua + ecn2String(Gateway::Qsb) + ecn2String(TIDua1));
	//cout << endl;
	//cout << "temStr" << temStr << endl;
	//cout << "Qsb1" << Qsb << endl;
	//cout << "TIDua1" << TIDua1 << endl;

	return Message2(tsb, Hsb);
}

void Gateway::getM3(Message3 m3)
{
	string hua1 = hashSha256(ecn2String(Gateway::Qua1) + ecn2String(Gateway::Qsb) );
	if (hua1 != m3.getHua()) {
		cout << "Hua1 from user not equal at gateway side" << endl;
		system("pause");
	}
}
