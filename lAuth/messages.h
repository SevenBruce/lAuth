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
		//string getIdi();
		//void setIdi(string idi);
		unsigned short  getIdi();
		void setIdi(unsigned short idi);

		string getMpi();
		void RegUser::ShowMpi();
		void setMpi(string mpi);
	
	private:
		//string idi;
		unsigned short idi;
		string mpi;
};

class BackUser {
	public:
		BackUser();
		BackUser::BackUser(string fi, string hi, int ki);
		~BackUser()
		{

		}
		string getFi();
		void setFi(string fi);

		string getHi();
		void setHi(string hi);

		int getKi();
		void setKi(int ki);


	private:
		string fi;
		string hi;
		int ki;
};


class Message1 {
	public:
		Message1(ECn a,int ki, string m2,int t1);
		~Message1()
		{
		}
		ECn getA();
		int getKi();
		string getM2();
		int getT1();

		void setA(ECn a);
		void setKi(int ki);
		void setM2(string m2);
		void setT1(int t1);

	private:
		ECn A;		
		int ki;
		string m2;
		time_t t1;
};

class Message2 {
public:
	Message2();
	Message2(ECn B, string m4);
	~Message2(){}

	ECn getB();
	string getM4();

	void setB(ECn a);
	void setM4(string m4);
private:
	ECn B;
	string m4;
};

class MsgChaningPassword {
public:
	MsgChaningPassword();
	MsgChaningPassword(int ki,string m2, int t1);
	~MsgChaningPassword(){}

	int getKi();
	void setKi(int ki);

	string getM2();
	void setM2(string m2);

	int getT1();
	void setT1(int t1);
private:
	int ki;
	string m2;
	time_t t1;
};

class MsgBackChaningPassword {
public:
	MsgBackChaningPassword();
	MsgBackChaningPassword(string m3);
	~MsgBackChaningPassword()	{}

	string getM3();
	void setM3(string m3);
private:
	string m3;	
};

#endif
