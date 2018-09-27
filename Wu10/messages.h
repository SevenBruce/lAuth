#ifndef MESSAGES_H
#define MESSAGES_H
#include<string>
#include "ecn.h"

using namespace std;

class RegUser {
	public:
		RegUser();
		RegUser(unsigned short idi, string mpi);
		~RegUser()
		{

		}
		unsigned short getIdi();
		void setIdi(unsigned short idi);

		string getHi();
		void setHi(string mpi);
	
	private:
		unsigned short idi;
		string Hi;
};

class BackUser {
	public:
		BackUser();
		BackUser::BackUser(int ei, string B1_, string B2_);
		~BackUser()
		{

		}
		int getEi();
		void setEi(int ei);

		string getB1_();
		void setB1_(string B1_);

		string getB2_();
		void setB2_(string B2_);

	private:
		int ei;
		string B1_;
		string B2_;
};


class Message1 {
	public:
		Message1(ECn c1,string c2, string c5, int ei);
		~Message1()
		{
		}
		ECn getC1();
		void setC1(ECn C1);
		
		string getC2();
		void setC2(string C2);
		
		void setC5(string c5);
		string getC5();
		
		void setEi(int ei);
		int getEi();

	private:
		ECn C1;		
		string C2;
		string C5;
		int ei;
};

class Message2 {
public:
	Message2();
	Message2(ECn C7, string C11);
	~Message2(){}

	ECn getC7();
	string getC11();

	void setC7(ECn C7);
	void setC11(string C11);
private:
	ECn C7;
	string C11;
};

class MsgChaningPassword {
public:
	MsgChaningPassword();
	~MsgChaningPassword(){}
	MsgChaningPassword(ECn c1, string c2, string c5, int ei, bool request );

	ECn getC1();
	void setC1(ECn C1);

	string getC2();
	void setC2(string C2);

	void setC5(string c5);
	string getC5();

	void setEi(int ei);
	int getEi();

	void setRequest(bool request);
	bool getRequest();

private:
	ECn C1;
	string C2;
	string C5;
	int ei;
	bool request;
};

class MsgBackChaningPassword {
public:
	MsgBackChaningPassword();
	MsgBackChaningPassword(string m3, bool permission);
	~MsgBackChaningPassword()	{}

	string getSa();
	void setSa(string Sa);

	void setPermission(bool permission);
	bool getPermission();
private:
	string Sa;
	bool permission;
};

#endif
