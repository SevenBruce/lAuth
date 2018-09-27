#ifndef DEFINES_H
#define DEFINES_H

#include "ecn.h"
#include "big.h"

#ifndef MR_NOFULLWIDTH
Miracl precision(50, 0);
#else 
Miracl precision(50, MAXBASE);
#endif

#endif
