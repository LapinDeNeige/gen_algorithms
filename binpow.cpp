#include "binpow.h"


//binary power modulo

//O(log(n))

//multiplication modulo 
unsigned int mul(unsigned int a,unsigned int b,unsigned int mod)
{
unsigned int res=0;

while(b)
{
if(b&1==1)
	res=(res+a)%mod;
a=(a*2)%mod;
b=b/2;
}

return res;
}


//a pow b (a^b) mod
unsigned int binpow(unsigned int a,unsigned int b ,unsigned int mod)
{

unsigned int kn=1;

if(b==0)
	return kn;

while(b!=0)
{
if((b&1)==1)
{
//kn=(kn*a)%mod;

kn=mul(kn,a,mod); //(kn*a)%mod
b--;
continue;

}


//a=(a*a)%mod;
a=mul(a,a,mod);
b=b/2;

}


return kn; 

}


