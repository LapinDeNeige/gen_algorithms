#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "BigInt.h"

#ifndef __GEN_BTS
#define __GEN_BTS
unsigned int gen_bits(unsigned int nm);
unsigned int  gen_bits_cnt(unsigned short bit_cnt);
unsigned int gen_rand(unsigned int nm);

BigInt gen_bits_cnt(unsigned int bit_cnt);
BigInt gen_rand(BigInt rng);
#endif
