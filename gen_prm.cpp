//#include <stdio.h>
//#include <iostream>
//#include "binpow.h"
//#include <math.h>
//#include "gen_bits.h"
#include "gen_prm.h"

//Random Prime Number generator
//source of entropy is time in milliseconds
//Atkin's sieve and Miller Rabin test


//check if the number is prime 
bool is_prim(unsigned int nm);
//bool is_prm (BigInt nm);


//generate prime number
unsigned int gen_prime(unsigned int rang)
{
//Atkin's sieve
 //4*x^2+y^2=nm
//3*x^2+y^2=nm

bool is=0;
unsigned int rt;

unsigned int x=gen_rand(rang/6);          //gen_bits(rang/6); //generate x number
unsigned int y=0;
unsigned int c;

while(!is)
{

if(y>=(rang/2))
{
y=0;
x= gen_rand(rang/6);//gen_bits(rang/6);
}

else
	++y; //generate y number

c=3*x+y; //3x^2+y^2

if(c%2==0)
	c++;

if(c%12==7||c%3==1||c%4==3) //if num modulo
{
is=is_prim(c); //check additioanly with Miller Rabin test

if(is) //prime found
	continue;
}

c=c+x; //4x^2+y^2
if(c%2==0)
	++c;

if((c%4>=1&&c%4<=5)||c%3==1)
{
is=is_prim(c);

if(is) //prime found
	continue;
}

}

return c;
}





//check if the number is prime with help of Miller Rabin primarity test
bool is_prim(unsigned int num)   //Miller rabin
{
unsigned int sqt=sqrt(num);

if(num==1||num==2||num==3||num==5)
	return 1;
if(num%2==0||num%sqt==0)
	return 0;


unsigned int h=num-1; //number -1
unsigned int d=h;
unsigned int s=0;

bool rt=1;

while(d&&d%2==0) //get number nm  as nm-1=2^s*d where d is odd
{
d=d/2;
s=s+1;
}

unsigned int a=0;
unsigned int res_f;

size_t i=0;
size_t lg=log2(num);

for(i;i<lg;i++)
{
a=gen_rand(num); //generate a in range of nm
res_f=binpow(a,d,num);//a^d mod nm

//res_f=pow(a,d);
//res_f=res_f%num;

if(res_f==1||res_f==(num-1)) // must be 1  or -1 
{
rt=1;
continue; 
}

for(int i=0;i<s;i++) 
{

rt=0;

//res_f=res_f*res_f;
//res_f=res_f%num;
res_f=mul(res_f,res_f,num);//res_f*res_f%num;

if(res_f==1)
	return 0; //not prime

if(res_f==(num-1))//true
{
rt=1;
break;  //continue
}

}



}


if(!rt)
	return 0;

/*
for(unsigned int i=3;i<(log2(num)*log2(num))*2;i=i+2)//
{
if(num%i==0)
	return 0;

}

*/

return 1;
}


/*
int main()
{

unsigned int o=999999999;

unsigned int po=gen_prime(o);

std::cout<<po<<"\n";


return 0;
}
*/



