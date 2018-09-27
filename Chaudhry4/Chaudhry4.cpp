#include "Chaudhry4.h"

int expRunningTime = 500;
//int expRunningTime = 1;
int times[5] = { 5, 10 , 15, 20 , 25 };
ofstream myfile;

int main()
{
	time_t seed;
	Big a, b, p, q, x, y;
	ECn g;
	miracl *mip = &precision;

	time(&seed);
	irand((long)seed);   /* change parameter for different values */
	a = 0;
	mip->IOBASE = 16;
	b = ecb_user_define;
	p = ecp_user_define;
	ecurve(a, b, p, MR_BEST);  // means use PROJECTIVE if possible, else AFFINE coordinates
	x = ecx_user_define;
	y = ecy_user_define;
	mip->IOBASE = 10;
	g = ECn(x, y);

	myfile.open("E:\\data\\runningtime\\lightweightidentity\\Chaudhry4_9_18.txt");
	myfile << "Chaudhry4_9_18" << endl;

	//gateway initiation;
	Gateway gateWay(g, p);

	//user initiation and registration at gateway.
	User aUser(g, p, gateWay.getMpk());
	RegUser regUser = aUser.generateReg();
	BackUser backUser = gateWay.getRegUser(regUser);
	aUser.getBackUser(backUser);

	//Message1 m1 = aUser.generateM1();
	//Message2 m2 = gateWay.getM1(m1);
	//Message3 m3 = aUser.getM2(m2);
	//gateWay.getM3(m3);

	userRegistrationTime(gateWay, aUser);
	userAuthTime(gateWay, aUser);

	system("PAUSE");
	return 0;

}

void userAuthTime(Gateway gateWay, User aUser) {
	clock_t clock1, clock2;
	BackUser backUser;
	double sum = 0;

	for (int j = 0; j < sizeof(times) / sizeof(times[0]); j++) {
		for (int k = 0; k < expRunningTime; k++) {
			for (int i = 0; i < times[j]; i++) {
				clock1 = clock();
				Message1 m1 = aUser.generateM1();
				Message2 m2 = gateWay.getM1(m1);
				Message3 m3 = aUser.getM2(m2);
				gateWay.getM3(m3);
				clock2 = clock();
				sum = sum + diffclock(clock2, clock1);
			}
		}
		cout << "User auth time of running Chaudhry4 " << times[j] << " times is :: " << endl;
		cout << sum / expRunningTime << endl;
		myfile << "User auth time of running Chaudhry4 " << times[j] << " times is :: " << endl;
		myfile << sum / expRunningTime << endl;
		sum = 0;
	}
}



void userRegistrationTime(Gateway gateWay, User aUser) {
	clock_t clock1, clock2;
	double sum = 0;

	for (int j = 0; j < sizeof(times) / sizeof(times[0]); j++) {
		for (int k = 0; k < expRunningTime; k++) {
			for (int i = 0; i < times[j]; i++) {
				clock1 = clock();
				RegUser regUser = aUser.generateReg();
				BackUser backUser = gateWay.getRegUser(regUser);
				aUser.getBackUser(backUser);
				clock2 = clock();
				sum = sum + diffclock(clock2, clock1);
			}
		}
		cout << "User registration time of running Chaudhry4 " << times[j] << " times is :: " << endl;
		cout << sum / expRunningTime << endl;
		myfile << "User registration time of running Chaudhry4 " << times[j] << " times is :: " << endl;
		myfile << sum / expRunningTime << endl;
		sum = 0;
	}
}


