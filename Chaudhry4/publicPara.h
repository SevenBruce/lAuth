#ifndef PUBLICPARA_H
#define PUBLICPARA_H


/* the length of identity */
static int IDENTITY_LENGTH = 2;

/* the length of a random number */
static int RANDOM_NUMBER_LENGTH = 4;

/* the length of password/random string */
static int RANDOM_STRING_LENGTH = 8;

/* the length of a hash 256 string */
static int HASH_MESSAGE_LENGH = 32;

/* NIST p192 bit elliptic curve prime 2#256 − 2#32 − 2#9 − 2#8 − 2#7 − 2#6 − 2#4 − 1*/
static char *ecp_user_define = (char *)"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F";

/* elliptic curve parameter B */
static char *ecb_user_define = (char *)"7";

/* elliptic curve - point of prime order (x,y) */
static char *ecx_user_define = (char *)"79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798";
static char *ecy_user_define = (char *)"483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8";

#endif
