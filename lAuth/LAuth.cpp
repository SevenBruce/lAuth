#include "LAuth.h"

int expRunningTime = 500;
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

	myfile.open("E:\\data\\runningtime\\lightweightidentity\\LAuth_9_17.txt");
	myfile << "running time 2018 - 9 - 17 - 1.00 " << endl;


	//gateway initiation;
	Gateway gateWay(g, p);
	//user initiation and registration at gateway.
	User aUser(g, p);
	RegUser regUser = aUser.generateReg();
	BackUser backUser = gateWay.getRegUser(regUser);
	aUser.getBackUser(backUser);

	//Message1 m1 = aUser.generateM1();
	//Message2 m2 = gateWay.getM1(m1);
	//aUser.getM2(m2);

	//MsgChaningPassword cp = aUser.generateChaningPassword();
	//MsgBackChaningPassword bcp = gateWay.getChangingPassword(cp);
	//aUser.getChaningPasswordBack(bcp);

	//m1 = aUser.generateM1();
	//m2 = gateWay.getM1(m1);
	//aUser.getM2(m2);

	userRegistrationTime(gateWay, aUser);
	userAuthTime(gateWay, aUser);
	userChaningPasswordTime(gateWay, aUser);

	system("PAUSE");

	return 0;

}

void userAuthTime(Gateway gateWay, User aUser) {
	clock_t clock1, clock2;
	double sum = 0;
	for (int j = 0; j < sizeof(times) / sizeof(times[0]); j++) {
		for (int k = 0; k < expRunningTime; k++) {
			for (int i = 0; i < times[j]; i++) {
				clock1 = clock();
				Message1 m1 = aUser.generateM1();
				Message2 m2 = gateWay.getM1(m1);
				aUser.getM2(m2);
				clock2 = clock();
				sum = sum + diffclock(clock2, clock1);
			}
		}
		cout << "User auth time of running LAuth " << times[j] << " times is :: " << endl;
		cout << sum / expRunningTime << endl;
		myfile << "User auth time of running LAuth " << times[j] << " times is :: " << endl;
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
		cout << "User registration time of running LAuth " << times[j] << " times is :: " << endl;
		cout << sum / expRunningTime << endl;
		myfile << "User registration time of running LAuth " << times[j] << " times is :: " << endl;
		myfile << sum / expRunningTime << endl;
		sum = 0;
	}
}

	void userChaningPasswordTime(Gateway gateWay, User aUser) {
		clock_t clock1, clock2;
		double sum = 0;

		for (int j = 0; j < sizeof(times) / sizeof(times[0]); j++) {
			for (int k = 0; k < expRunningTime; k++) {
				for (int i = 0; i < times[j]; i++) {
					clock1 = clock();
					MsgChaningPassword cp = aUser.generateChaningPassword();
					MsgBackChaningPassword bcp = gateWay.getChangingPassword(cp);
					aUser.getChaningPasswordBack(bcp);
					clock2 = clock();
					sum = sum + diffclock(clock2, clock1);
				}
			}
			cout << "User password change time of running LAuth " << times[j] << " times is :: " << endl;
			cout << sum / expRunningTime << endl;
			myfile << "User password change time of running LAuth " << times[j] << " times is :: " << endl;
			myfile << sum / expRunningTime << endl;
			sum = 0;
		}
	}


