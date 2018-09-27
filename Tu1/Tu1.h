#pragma once
#ifndef TU1_H
#define TU1_H

#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include "ecn.h"
#include "big.h"
#include "utils.h"
//#include "entities.h"
#include "gateway.h"
#include "user.h"
#include "messages.h"

void userRegistrationTime(Gateway gateWay, User aUser);
void userAuthTime(Gateway gateWay, User aUser);
void userChaningPasswordTime(Gateway gateWay, User aUser);

#ifndef MR_NOFULLWIDTH
Miracl precision(50, 0);
#else 
Miracl precision(50, MAXBASE);
#endif


#endif

