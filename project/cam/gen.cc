/*
Author: Samuel Villarreal
title: 8 million numbers
description:
	This takes place of a buffer throwing random 64bit values
*/
#include <iostream>
#include <stdlib.h>

int64_t mmax = 0xFFFFFFFFFFFFFFFFLL;
int eight_mil = 8000000;

using namespace std;


unsigned long long lcg(unsigned long seed){
	//credit for number to MMIX by Donald Knuth
	unsigned long long k = 6364136223846793005;
	unsigned long long c = 1;
	unsigned long long t1 = seed * k;
	unsigned long long t2 = t1 + c;
	return t2 % mmax ;
}
int main()
{
	unsigned long long seed1 = time(NULL);	
	for(int64_t i = 0; i < eight_mil; i++)
	{
		seed1 = lcg(seed1);
		cout << seed1 << endl;
	}
	return 0;
}
