#include "utils.h"

string randomString(int len)
{
	string str = "";
	int i;
	for (i = 0; i < len; ++i)
		str += 'a' + rand() % 26;
	return str;
}

string __int82String(__int8 org) {
	string str = "";
	str += *((char*)&org);
	//cout << endl;;
	return str;
}

__int8 string2__int8(string str) {
	char *ret = new char[1];
	ret[0] = str[0];
	__int8 id = *(__int8*)(ret);
	return id;
}

unsigned short randonIdentity() {
	srand((unsigned)time(NULL));
	return rand() % 65535;
}

int randonIntegerNumber() {
	srand((int)time(NULL));
	return rand() % (INT_MAX - 1) + 1;
}

string identity2String(unsigned id) {
	string str = "";
	for (int i = 0; i < 2; i++) {
		str += *((char*)&id + i);
		//cout << "ret[ "<<i<<" ] :" << *((char*)&id + i) << "[ " << endl;
	}
	//cout << endl;;
	return str;
}

unsigned short string2Identity(string str) {
	char *ret = new char[2];
	for (int i = 0; i < 2; i++) {
		ret[i] = str[i];
		//cout << "ret[ " << i << " ] :" << ret[i] << "[ " << endl;
	}
	unsigned short id = *(unsigned short*)(ret);
	return id;
}


int string2int(string str) {
	char *ret = new char[4];
	for (int i = 0; i < 4; i++) {
		ret[i] = str[i];
		//cout << "ret[ " << i << " ] :" << ret[i] << "[ " << endl;
	}
	int id = *(int*)(ret);
	return id;
}

string int2String(int num) {
	string str = "";
	for (int i = 0; i < 4; i++) {
		str += *((char*)&num + i);
		//cout << "ret[ "<<i<<" ] :" << *((char*)&num + i) << "[ " << endl;
	}
	return str;
}


string ecn2String(ECn ecn)
{
	string result;

	ECn temEcn = ecn;
	char aString[100];
	Big temBigx, temBigy;

	temEcn.get(temBigx, temBigy);
	aString << temBigx;

	aString << temBigy;
	result += aString;

	return result;
}

ECn string2ECn(string org)
{
	Big temBigx = string2Big("");
	Big temBigy = string2Big("");

	ECn temEcn = ECn(temBigx, temBigy);
	return temEcn;
}


string ecn2BinaryString(ECn ecn)
{
	string result;
	ECn temEcn = ecn;
	Big temBigx, temBigy;

	temEcn.get(temBigx, temBigy);

	//cout << "x is " << big2String(temBigx) << endl;
	//cout << "y is " << big2String(temBigy) << endl;
	//string tem = big2Binary(temBigx);
	result += big2Binary(temBigx);

	//tem = big2Binary(temBigy);
	result += big2Binary(temBigy);

	//cout << "result is " << result << endl;
	return result;
}

ECn binary2Ecn(string org) {
	int len = string2__int8(org.substr(0, 1));

	Big temBigx = binary2Big(org.substr(0, len + 1));
	//cout << "len is " << len << endl;

	int len1 = string2__int8(org.substr(len + 1, 1));
	//cout << "len is " << len1 << endl;
	Big temBigy = binary2Big(org.substr(len + 1, len1 + 1));

	//cout << "org.substr(0, pos) is " << org.substr(0, pos) << endl;
	//cout << "org.substr(pos + 1) is " << org.substr(pos + 1) << endl;

	//cout << "x is " << big2String(temBigx) << endl;
	//cout << "y is " << big2String(temBigy) << endl;

	return ECn(temBigx, temBigy);
}

string big2String(Big big)
{
	string result;
	char aString[100];
	aString << big;
	result += aString;

	return result;
}

Big string2Big(string org)
{
	char hash[32];

	int i;
	sha256 sh;
	shs256_init(&sh);
	for (i = 0; org[i] != 0; i++) shs256_process(&sh, org[i]);
	shs256_hash(&sh, hash);

	Big x = from_binary(32, hash);
	return x;
}

string hashSha256(string org)
{
	char hash[32];

	int i;
	sha256 sh;
	shs256_init(&sh);
	for (i = 0; org[i] != 0; i++) shs256_process(&sh, org[i]);
	shs256_hash(&sh, hash);

	string result;
	for (i = 0; i < 32; i++) {
		result += (unsigned char)hash[i];
	}

	//string result = bytestohexstring(hash, 32);

	return result;
}

void coutHash(string hash) {
	int end = hash.length();
	//int end = sizeof(hash);
	for (int i = 0; i < end; i++) printf("%02x", (unsigned char)hash[i]);
}


string encryption(string aString, string key) {

	string aResultString = "";
	int len = aString.length();
	aes a;
	char ch, H[32], iv[16];

	sha256 sh;
	shs256_init(&sh);
	for (int i = 0; key[i] != 0; i++) shs256_process(&sh, key[i]);
	shs256_hash(&sh, H);

	for (int i = 0; i < 16; i++)iv[i] = i; 
	aes_init(&a, MR_PCFB1, 32, H, iv);// Set 128 bit AES Key

	//for (int i = 0; aString[i] != 0; i++) {
	for (int i = 0; i< len; i++) {
		ch = aString[i];
		aes_encrypt(&a, &ch);
		aResultString = aResultString + ch;
	}
	aes_end(&a);

	return aResultString;
}

string decryption(string aString, string key) {

	int len = aString.length();
	string aResultString = "";
	aes a;
	char ch, H[32], iv[16];

	sha256 sh;
	shs256_init(&sh);
	for (int i = 0; key[i] != 0; i++) shs256_process(&sh, key[i]);
	shs256_hash(&sh, H);

	for (int i = 0; i < 16; i++)iv[i] = i;
	aes_init(&a, MR_PCFB1, 32, H, iv);// Set 128 bit AES Key

	for (int i = 0; i< len; i++) {
		ch = aString[i];
		aes_decrypt(&a, &ch);
		aResultString = aResultString + ch;
	}
	aes_end(&a);

	return aResultString;
}


string big2Binary(Big big)
{
	string result;
	char aString[100];
	int len = to_binary(big, 100, aString, FALSE);
	string tem = bytestohexstring(aString, len);

	result += to_string(tem.length()) + tem;
	return result;
}

Big binary2Big(string org)
{
	int len = atoi(org.substr(0, 2).c_str())/2;
	char hash[100];

	char* tem = hexstringToBytes(org.substr(2, len*2));
	for (int i = 0; i <= len; i++) hash[i] = tem[i];

	Big x = from_binary(len, hash);

	return x;
}


char* hexstringToBytes(string s)
{
	int sz = s.length();
	char *ret = new char[sz / 2];
	for (int i = 0; i <sz; i += 2) {
		ret[i / 2] = (char)((hexCharToInt(s.at(i)) << 4)
			| hexCharToInt(s.at(i + 1)));
	}
	return ret;
}

int hexCharToInt(char c)
{
	if (c >= '0' && c <= '9') return (c - '0');
	if (c >= 'A' && c <= 'F') return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f') return (c - 'a' + 10);
	return 0;
}

constexpr char hexmap[] = { '0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };


string bytestohexstring(char* data, int len)
{
	std::string s(len * 2, ' ');
	for (int i = 0; i < len; ++i) {
		s[2 * i] = hexmap[(data[i] & 0xF0) >> 4];
		s[2 * i + 1] = hexmap[data[i] & 0x0F];
	}
	return s;
}


Big H1(char *string)
{ // Hash a zero-terminated string to a number < modulus
	Big h, p;
	char s[64];
	int i, j;
	sha512 sh;

	shs512_init(&sh);

	for (i = 0;; i++)
	{
		if (string[i] == 0) break;
		shs512_process(&sh, string[i]);
	}
	shs512_hash(&sh, s);
	p = get_modulus();
	h = 1; j = 0; i = 1;
	forever
	{
		h *= 256;
	if (j == 64) { h += i++; j = 0; }
	else         h += s[j++];
	if (h >= p) break;
	}
	h %= p;
	return h;
}


Big H3(char *string)
{ // Hash a zero-terminated string to a number < modulus
	Big h, p;
	char s[32];
	int i, j;
	sha256 sh;

	shs256_init(&sh);

	for (i = 0;; i++)
	{
		if (string[i] == 0) break;
		shs256_process(&sh, string[i]);
	}

	shs256_hash(&sh, s);
	p = get_modulus();
	h = 1; j = 0; i = 1;

	forever
	{
		h *= 256;
		if (j == 32) { 
			h += i++; j = 0; 
		}
		else {
			h += s[j++];
		}         

		if (h >= p) break;
	}

	h %= p;
	return h;
}

ECn hash_and_map(char *ID, Big cof)
{
	ECn Q;
	Big x0 = H3(ID);

	while (!Q.set(x0)) x0 += 1;
	Q *= cof;

	return Q;
}

string xor (string org, string key)
{
	string encrypted = "";
	string tem = "";

	while (tem.length() < org.length())
	{
		tem = tem.append(key);
	}
	for (int temp = 0, i = 0; temp < org.size(); temp++, i++) {
		encrypted += ((org[temp] - '0') ^ (tem[i] - '0')) + '0';
	}
	return encrypted;
}

bool isValidTime(int timeCome) {
	int timeNow = time(NULL);
	if (timeNow < (timeCome + 10))
		return true;
	return false;
}

void timeDeal(int timeCome, string t1) {
	if (!isValidTime(timeCome)) {
		cout << "TimeStamp " + t1 + " not valid, exit." << endl;
		system("pause");
	}
}


double diffclock(clock_t clock1, clock_t clock2) {

	double diffticks = clock1 - clock2;
	double diffms = diffticks / (CLOCKS_PER_SEC / 1000);

	return diffms;
}