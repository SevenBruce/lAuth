#include "user.h"


User::User()
{
	User::idi = randonIdentity();
	User::pwi = randomString(RANDOM_STRING_LENGTH);
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
	User::a = rand(p);
	User::mpi = string2Big(User::pwi + big2String(User::a));

	RegUser regUser = RegUser(User::idi, User::mpi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::r = backUser.getR();
}

Message1 User::generateM1()
{
	User::b = rand(p);
	User::V = User::g;
	User::V *= User::b;

	ECn tem = User::g;
	tem *= User::mpi;
	User::V1 = User::r;
	User::V1 -= tem;
	User::V1 *= User::b;
	User::w = hashSha256(to_string(User::idi) + ecn2String(User::V) + ecn2String(User::V1));

	Message1 message1(User::idi, User::V, User::w);
	return message1;
}

Message3 User::getM2(Message2 m2) {

	ECn temKey = m2.getC();
	temKey *= User::b;

	User::sk = hashSha256(ecn2String(temKey) + big2String(m2.getR()) + to_string(User::idi));

	string auths = hashSha256(ecn2String(temKey) + User::w + big2String(m2.getR()) + User::sk);

	if (auths != m2.getAuths()) {
		cout << "auths from gateway at user side not equal" << endl;
		system("pause");
	}
	string authu = hashSha256(ecn2String(temKey) + User::w + big2String(m2.getR() + 1) + User::sk);
	return Message3(authu);
}


MsgChaningPassword User::generateChaningPassword()
{
	User::pwNew = randomString(RANDOM_STRING_LENGTH);
	User::aNew = rand(User::p);

	User::N = rand(User::p);

	string tem = identity2String(User::idi) + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + big2String(User::aNew))) +
				hashSha256(to_string(User::idi) + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + big2String(User::aNew))));

	//cout << "user::sk " << User::skij << endl;
	//cout << "idi " << idi << "    "  << endl;
	//cout << "N " << big2Binary(User::N) << "    " << big2Binary(User::N).length() << endl;
	//cout << "mpi " << big2Binary(string2Big(User::pwNew + User::aNew)) << "    " << big2Binary(string2Big(User::pwNew + User::aNew)).length() << endl;
	//cout << "temHash " << hashSha256(to_string(User::idi) + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + User::aNew))) << "    " << hashSha256(to_string(User::idi) + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + User::aNew))).length() << endl;
	//cout << tem.length() << endl;

	//cout << endl; cout << endl;
	//cout << "********************************************************************************" << endl;
	//cout << "idi " << idi  << endl;
	//cout << "N " << binary2Big(big2Binary(User::N)) << endl;
	////cout << "mpi " << string2Big(User::pwNew + User::aNew) << endl;
	//cout << "mpi " << binary2Big(big2Binary(string2Big(User::pwNew + User::aNew))) << endl;
	//cout << "temHash "; coutHash(hashSha256(to_string(User::idi) + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + User::aNew))));
	//cout << hashSha256(to_string(User::idi) + big2Binary(User::N) + big2Binary(string2Big(User::pwNew + User::aNew))).length() << endl;
	//cout << "tem.length() " << tem.length() << endl;
	//cout << "********************************************************************************" << endl;

	/*cout << string2Big(User::pwNew + User::aNew) << endl;*/
	string c1 = encryption(tem, User::sk);
	MsgChaningPassword msg(c1, User::N);
	return msg;
}

void User::getChaningPasswordBack(MsgBackChaningPassword backMsg)
{
	string tem = decryption(backMsg.getC2(), User::sk);

	//int len = string2__int8(tem.substr(0, 1));
	
	//cout << "tem.length() - HASH_MESSAGE_LENGH    is : " <<tem.length() - HASH_MESSAGE_LENGH<< endl;
	string temR = tem.substr(0, tem.length() - HASH_MESSAGE_LENGH);
	string temHash = tem.substr(tem.length() - HASH_MESSAGE_LENGH, HASH_MESSAGE_LENGH);

	//cout << endl;
	
	User::N += 1;
	//cout << "N    is : " << big2Binary(User::N) << endl;
	string temC2 = hashSha256(to_string(User::idi) + big2String(User::N) + temR);

	//cout << endl;
	//cout << "idi is : "<< idi << endl;
	////cout << "tem is : "; coutHash(tem); cout << endl;
	//cout << "N    is : " << big2Binary(User::N) << endl;
	/*cout << "R    is : " << temR << endl;*/
	//cout << "hash is : "; coutHash(temHash); cout << endl;
	//cout << endl;
	//cout << "hash is : "; coutHash(temC2); cout << endl;

	if (temC2 != temHash) {
		cout << "temHash from gateway not equal at user side" << endl;
		system("pause");
	}

	User::pwi = User::pwNew;
	User::a = User::aNew;

	//cout << endl; cout << endl;
	//cout << "tem.length()  " << tem.length() - HASH_MESSAGE_LENGH << endl;
	//cout << "R    is : " << temR << endl;

	User::r = binary2Ecn(temR);
	User::mpi = string2Big(User::pwi + big2String(User::a));
}





