#ifndef MESSAGES_H
#define MESSAGES_H
#include<string>
#include "ecn.h"

using namespace std;

class RegUser {
public:
	RegUser();
	RegUser(unsigned short idi, Big mpi);
	~RegUser()
	{

	}
	unsigned short getIdi();
	void setIdi(unsigned short idi);

	Big getMpi();
	void RegUser::ShowMpi();
	void setMpi(Big mpi);

private:
	unsigned short idi;
	Big mpi;
};

class BackUser {
public:
	BackUser();
	BackUser::BackUser(ECn AIDua, string BIDua);
	~BackUser()
	{

	}
	ECn getAIDua();
	void setAIDua(ECn AIDua);

	string getBIDua();
	void setBIDua(string BIDua);

private:
	ECn AIDua;
	string BIDua;
};


class Message1 {
public:
	Message1(string Didua, ECn Qua, string EIDua);
	~Message1()
	{
	}
	ECn getQua();
	string getDIDua();
	string getEIDua();

	void setQua(ECn Qua);
	void setDIDua(string Didua);
	void setEIDua(string EIDua);

private:
	ECn Qua;
	string DIDua;
	string EIDua;
};

class Message2 {
public:
	Message2();
	Message2(string Tsb, string Hsb);
	~Message2() {}

	string getTsb();
	string getHsb();

	void setTsb(string auths);
	void setHsb(string hsb);
private:
	string Tsb;
	string Hsb;
};

class Message3 {
public:
	Message3();
	Message3(string Hua);
	~Message3() {}

	string getHua();
	void setHua(string Hua);

private:
	string Hua;
};


#endif
