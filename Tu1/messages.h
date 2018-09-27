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
		BackUser::BackUser(ECn r);
		~BackUser()
		{

		}
		ECn getR();
		void setR(ECn r);
	private:
		ECn r;
};


class Message1 {
public:
		Message1() {};
		Message1(unsigned short idi,ECn v, string w);
		~Message1()
		{
		}
		ECn getV();
		unsigned short getIdi();
		string getW();

		void setV(ECn a);
		void setIdi(unsigned short idi);
		void setW(string w);

	private:
		ECn V;		
		unsigned short idi;
		string w;
};

class Message2 {
public:
	Message2();
	Message2(ECn C, Big r, string auths);
	~Message2(){}

	ECn getC();
	string getAuths();
	Big getR();

	void setC(ECn c);
	void setAuths(string auths);
	void setR(Big r);
private:
	ECn C;
	Big r;
	string auths;
};

class Message3 {
public:
	Message3();
	Message3(string authu);
	~Message3() {}

	string getAuthu();
	void setAuthu(string authu);

private:
	string authu;
};

class MsgChaningPassword {
public:
	MsgChaningPassword();
	MsgChaningPassword(string ki,Big N);
	~MsgChaningPassword(){}

	Big getN();
	void setN(Big N);

	string getC1();
	void setC1(string c1);

private:
	string c1;
	Big N;
};

class MsgBackChaningPassword {
public:
	MsgBackChaningPassword();
	MsgBackChaningPassword(string c2);
	~MsgBackChaningPassword()	{}

	string getC2();
	void setC2(string c2);
private:
	string c2;	
};

#endif
