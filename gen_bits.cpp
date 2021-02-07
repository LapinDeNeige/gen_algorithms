//#include <stdio.h>
//#include <sys/time.h>
//#include <time.h>
//#include <iostream>
//#include <math.h>
//#include "BigInt.h"
#include "gen_bits.h"

#define MX 99999999



//Random bits generation
//

unsigned int gen_bits(unsigned int nm) //random bits generate
{

unsigned int lg=log2(nm)+1;
unsigned int t=0;

struct timeval ty;

for(int i=0;i!=lg;i++)
{
//int nm=pr();

t=t<<1;//shift

gettimeofday(&ty,0);

int cr=(int)ty.tv_usec; //get miliseconds
unsigned int nam=cr;

int hj=clock();

int cl=(nam>>(hj%32))|(hj%65535);

if(cl%2==0) //if 
{
//nam=clock();
nam=(nam>>(cr%32))|(cr%(cl%65535));
}
else
	nam=(nam|(cr%hj));

nam=nam%2;
t=t|nam;

}

if(nm>0)
	t=t%nm;
return t;
}


//generate bbits by count
unsigned int  gen_bits_cnt(unsigned short bit_cnt)
{
unsigned int ret=1;

for(unsigned short i=0;i<bit_cnt;i++)
{
ret=ret<<1;
struct timeval ty;
gettimeofday(&ty,0);

int nm=(int)ty.tv_usec;
int o=time(0);
o=o%15;

nm=(nm>>o)&1; //second last bit
ret=ret|nm;
}

return ret;

}


unsigned int gen_rand(unsigned int nm)
{

unsigned int lg=log2(nm);
unsigned int to=clock()%lg;

struct timeval vl;
unsigned int h=0;

for(unsigned int i=1;i<=to;i=i+1)
{

gettimeofday(&vl,0);
unsigned int tmp=(unsigned int)vl.tv_usec;

int cl=(int)clock();

if(cl&1==0)
	tmp=(tmp>>16)|(cl%65537);
else
	tmp=tmp|(cl%65537);
h=h^tmp;
h=h%nm;
}
return h;

}


BigInt gen_rand(BigInt rng)
{
BigInt on;

while(on<=(rng.lg()))
{
unsigned int nm=gen_rand(MX);

std::string st=on.conv_int_to_str(nm);
on.app_str(st);
}

on=on%rng;
return on;
}
/*
BigInt gen_bits(BigInt rng) //generate random bits for bigint
{

BigInt on;
BigInt tw(2);

while(on<=rng)
{
unsigned int tm=gen_bits(MX); //generate bits in range of BigInt


std::string sr=on.conv_int_to_str(tm);
on.app_str(sr);

}
BigInt qq=tw.pow(rng,"0");
on=on%qq;

return on ;
}
*/

BigInt gen_bits_cnt(unsigned int bit_cnt)
{
BigInt ret;
unsigned int i=0;
for(i;i<bit_cnt;i=i+16)
{
int tmp=gen_bits_cnt((unsigned short)16); //16 bits
std::string st=ret.conv_int_to_str(tmp);
ret.app_str(st);
}

i=(i-bit_cnt);

unsigned int val=pow(2,i);

ret=ret/val;//delete last bits

return ret;
}




