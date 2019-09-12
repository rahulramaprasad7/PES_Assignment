#ifndef _Problem1_h
#define _Problem1_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

struct dataStructure
{
	int32_t value;
	int32_t radix;
	int32_t opSize;
} numProperties[11];

bool negative = false;
int32_t operand = 0, min = 0, max = 0;
int32_t value, radix, opSize, compMins;

void convToBin(int32_t input, int32_t opSize);
int32_t onesComp(int32_t signedNo, int32_t opSize);
int32_t twosComp(int32_t signedNo, int32_t opSize);
int32_t toSigned(int32_t unsignedNo, int32_t opSize);
void printAbsBin(void);
void printAbsOct(void);
void printAbsDec(void);
void printAbsHex(void);
void printSignedBin(void);
void printSignOnesComp(void);
void printSignTwosComp(void);
void printAllOutputs(void);

#endif
