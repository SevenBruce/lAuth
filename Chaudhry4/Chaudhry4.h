#pragma once
#ifndef CHAUDHRY4_H
#define CHAUDHRY4_H

#include <iostream>
#include <fstream>
using namespace std;
#include <string>
#include "utils.h"
#include "defines.h"
#include "gateway.h"
#include "user.h"
#include "messages.h"

void userRegistrationTime(Gateway gateWay, User aUser);
void userAuthTime(Gateway gateWay, User aUser);

#endif

