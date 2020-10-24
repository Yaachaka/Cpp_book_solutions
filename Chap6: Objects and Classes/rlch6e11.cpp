/*
--PROGRAM NAME: rlch6e11.cpp
--PROGRAM STATEMENT: Modify the four-function fraction calculator of Exercise 12 
in Chapter 5 to use a fraction class rather than a structure. There should be 
member functions for input and output, as well as for the four arithmetical 
operations. While you’re at it, you might as well install the capability to 
reduce fractions to lowest terms. Here’s a member function that will reduce the 
fraction object of which it is a member to lowest terms. It finds the greatest 
common divisor (gcd) of the fraction’s numerator and denominator, and uses this 
gcd to divide both numbers. 

void fraction::lowterms()     // change ourself to lowest terms
{
	long tnum, tden, temp, gcd;tnum = labs(num);	// use non-negative copies
	tden = labs(den);          //(needs cmath)
	if(tden==0 )   //check for n/0
	{
		cout<<“Illegal fraction: division by 0”; 
		exit(1);
	}else if( tnum==0 )     // check for 0/n
	{
		num=0;
		den = 1;
		return;
	}// this ‘while’ loop finds the gcd of tnum and tden
	while(tnum != 0)
	{
		if(tnum < tden)  // ensure numerator larger
		{
			temp=tnum;
			tnum=tden;
			tden=temp;
		}  // swap them
		tnum = tnum - tden;     // subtract them
	}
	gcd = tden;  // this is greatest common divisor
	num = num / gcd;    // divide both num and den by gcd
	den = den / gcd;    // to reduce frac to lowest terms
}

You can call this function at the end of each arithmetic function, or just 
before you per-form output. You’ll also need the usual member functions:four 
arithmetic operations, input, and display. You may find a two-argument 
constructor useful.
*/
#include<iostream>
#include<cmath>	//abs().
using namespace std;

class fraction
{
	private:
		int num,den;
	public:
		void read();	//To get fractions from the user.
		void disp()const;		//To display fraction
		void add(fraction);		//Add two fractions.
		void sub(fraction);		//Find difference of two fractions
		void mul(fraction);		//Product of two fractions.
		void div(fraction);		//Quotient (in fraction form) of two fractions.
		void gcd();		//GCD of numerator and denominator.
};

int main()
{
	fraction f1,f2;
	char c;
	
	cout<<"Enter first fraction: ";
	f1.read();
	cout<<"Enter second fraction: ";
	f2.read();
	cout<<"Enter operator(+,-,*,/)(defualt:+): ";
	cin>>c;
	
	switch(c)
	{
		case '-': f1.sub(f2);break;
		case '*': f1.mul(f2);break;
		case '/': f1.div(f2);break;
		default: f1.add(f2);
		
	}
	
	f1.gcd();
	cout<<"Resulting fraction: ";
	f1.disp();
	cout<<endl;
	return 0;
}

void fraction::read()
{
	char c;
	cin>>num>>c>>den;
}

void fraction::disp()const
{
	cout<<num<<'/'<<den;
}

void fraction::add(fraction f)
{
	num=num*f.den+den*f.num;
	den*=f.den;
}

void fraction::sub(fraction f)
{
	num=num*f.den-den*f.num;
	den*=f.den;
}

void fraction::mul(fraction f)
{
	num*=f.num;
	den*=f.den;
}

void fraction::div(fraction f)
{
	num*=f.den;
	den*=f.num;
}

void fraction::gcd()
{
	int n=abs(num),d=abs(den),r=1;//n-numerator, d-denominator, r-remainder.
	if(d>n)
	{
		n=abs(den);
		d=abs(num);
	}
	while(r!=0)
	{
		r=n%d;
		n=d;
		d=r;
	}		//At the end of the while n holds the GCD.
	//Reducing fraction to lowest term.
	num/=n;
	den/=n;
}