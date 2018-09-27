#include "user.h"


User::User(ECn g, Big p, unsigned short ids)
{
	User::idi = randonIdentity();
	User::pwi = randomString(RANDOM_STRING_LENGTH);
	User::ri = randomString(HASH_MESSAGE_LENGH);
	User::rbi = randomString(HASH_MESSAGE_LENGH);

	User::g = g;
	User::p = p;
	User::ids = ids;
}

RegUser User::generateReg()
{
	string tem = (hashSha256(User::pwi + User::rbi));
	User::Hi = xor ( ri, tem);

	RegUser regUser = RegUser(User::idi, User::Hi);
	return regUser;
}

void User::getBackUser(BackUser backUser)
{
	User::B2 = xor (backUser.getB2_(), User::ri); 
	User::B1 = xor(backUser.getB1_(), User::ri);
	User::ei = backUser.getEi();
	//cout << "key user : " << xor (xor (User::B1, hashSha256(User::pwi + User::rbi)), hashSha256(User::idi + User::ei)) << endl;
}

Message1 User::generateM1()
{
	User::alpha = rand(User::p);
	User::C1 = User::g;
	User::C1 *= User::alpha;

	User::ui = randomString(4);

	string hashPwiRbi = hashSha256(User::pwi + User::rbi);
	string key = xor (xor (User::B1, hashPwiRbi), hashSha256(to_string(User::idi) + to_string(User::ei) ));
	User::C2 =xor(User::ui, key);

	User::C3 = xor (User::B2 , hashPwiRbi);
	string C4 = hashSha256(ecn2String(C1) + User::C2 + User::C3 + to_string(User::ei) + User::ui);
	string C5 = encryption(identity2String(User::idi) + C4, ui);
	
	//cout << endl;
	//cout << "key : " << key << endl;
	//cout << "C2  : " << C2 << endl;
	//cout << "ui1 : " << ui << endl;
	//cout << "idi : " << idi << endl;
	//cout << "c41 : " << C4 << endl;
	//cout << endl;

	Message1 message1(User::C1, C2, C5, User::ei);
	return message1;
}

void User::getM2(Message2 m2) {

	string c91 = xor (User::C3 , User::ui);
	string temStr = decryption(m2.getC11(), c91);

	string c61 = temStr.substr(0, HASH_MESSAGE_LENGH);
	string c81 = temStr.substr(HASH_MESSAGE_LENGH, RANDOM_NUMBER_LENGTH);
	string c101 = temStr.substr(RANDOM_NUMBER_LENGTH + HASH_MESSAGE_LENGH);

	//cout << endl;
	//cout << "c61 : " << c61 << endl;
	//cout << "c81  : " << c81 << endl;
	//cout << "c101 : " << c101 << endl;

	ECn temKey = m2.getC7();
	temKey *= User::alpha;
	//Big key;
	//temKey.get(key);
	User::sku = hashSha256(ecn2String(User::C1) + ecn2String(m2.getC7()) + ecn2String(temKey));

	int eiNew = string2int(xor (c81, xor (User::C2, int2String(User::ei) )));
	//cout << "User::ei  : " << User::ei << endl;
	//cout << "User::C2 : " << User::C2 << endl;

	//cout << endl;
	//cout << "eiNew : " << eiNew << endl;
	//cout << "sku  : " << sku << endl;
	//cout << "c9  : " << c91 << endl;
	//cout << "ids  : " << ids << endl;
	//cout << "idi  : " << idi << endl;
	//cout << "c61 : " << c61 << endl;
	//cout << "c81 : " << c81 << endl;
	//cout << "c101 : " << c101 << endl;

	string temC10 = hashSha256(to_string(User::idi) + to_string(User::ids) + c61 + c81 + c91 + User::sku + to_string(eiNew));
	if (temC10 != c101) {
		cout << "c101 from gateway at user side not equal" << endl;
		system("pause");
	}

	User::B1 = xor(xor (xor (c61, User::C3), hashSha256(User::pwi + User::rbi)), hashSha256(to_string(User::idi) + to_string(eiNew)));
	User::ei = eiNew;
}


MsgChaningPassword User::generateChaningPassword()
{
	User::alpha = rand(p);
	User::C1 = User::g;
	User::C1 *= User::alpha;
	User::ui = randomString(HASH_MESSAGE_LENGH);


	string hashPwiRbi = hashSha256(User::pwi + User::rbi);
	string key = xor (xor (User::B1, hashPwiRbi), hashSha256(to_string(User::idi) + to_string(User::ei)));
	User::C2 = xor (User::ui, key);

	User::C3 = xor (User::B2, hashPwiRbi);
	string C4 = hashSha256(ecn2String(C1) + User::C2 + User::C3 + to_string(User::ei) + User::ui);
	string C5 = encryption(identity2String(User::idi) + C4, ui);

	//cout << endl;
	//cout << "key : " << key << endl;
	//cout << "C2  : " << C2 << endl;
	//cout << "ui1 : " << ui << endl;
	//cout << "idi : " << idi << endl;
	//cout << "c41 : " << C4 << endl;
	//cout << endl;

	MsgChaningPassword msg(User::C1, C2, C5, User::ei, true);
	return msg;
}

void User::getChaningPasswordBack(MsgBackChaningPassword mb)
{
	string temSa = hashSha256(User::ui + to_string(User::ei) + User::C3 + User::C2 + ecn2String(User::C1));
	if (temSa != mb.getSa()) {
		cout << "temSa from gateway not equal at user side" << endl;
		system("pause");
	}

	string hashPwiRbi = hashSha256(User::pwi + User::rbi);

	User::pwi = randomString(RANDOM_STRING_LENGTH);
	User::rbi = randomString(HASH_MESSAGE_LENGH);
	
	string hashPwiNewRbiNew = hashSha256(User::pwi + User::rbi);

	User::B1 = xor (xor (User::B1, hashPwiRbi), hashPwiNewRbiNew);
	User::B2 = xor (xor (User::B2, hashPwiRbi), hashPwiNewRbiNew);
}





