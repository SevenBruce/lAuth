#ifndef UTILS_H
#define UTILS_H

#include <string>
#include<iostream>
using namespace std;

#include "big.h"
#include "mirdef.h"
#include "ecn.h"
#include <random>
#include <ctime>

void coutHash(string);

string randomString(int);

string __int82String(__int8 org);
__int8 string2__int8(string str);

unsigned short randonIdentity();
int randonIntegerNumber();

unsigned short string2Identity(string str);
string identity2String(unsigned id);

int string2int(string str);
string int2String(int num);

string ecn2String(ECn ecn);
ECn string2ECn(string org);
string big2String(Big big);
Big string2Big(string org);
string hashSha256(string org);
string xor (string org, string key);
string encryption (string org, string key);
string decryption(string org, string key);
ECn hash_and_map(char *ID, Big cof);

string big2Binary(Big big);
Big binary2Big(string org);

string ecn2BinaryString(ECn ecn);
ECn binary2Ecn(string org);

char* hexstringToBytes(string s);
int hexCharToInt(char c);
string bytestohexstring(char* bytes, int bytelength);

bool isValidTime(int time);
void timeDeal(int time,string t1);
double diffclock(clock_t clock1, clock_t clock2);
#endif
