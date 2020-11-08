/*
--PROGRAM NAME: rlch8e7.cpp
--PROGRAM STATEMENT: Modify the fraction class in the four-function fraction 
calculator from Exercise 11 in Chapter 6 so that it uses overloaded operators 
for addition, subtraction, multiplication, and division. (Remember the rules for 
fraction arithmetic in Exercise 12 in Chapter 3, “Loops and Decisions.”)  Also 
overload the == and != comparison operators, and use them to exit from the loop 
if the user enters 0/1, 0/1 for the values of the two input fractions. You may 
want to modify the lowterms() function so that it returns the value of its 
argument reduced to lowest terms. This makes it more useful in the arithmetic 
functions, where it can be applied just before the answer is returned.
*/
#include<iostream>
#include<cmath>	//abs().
using namespace std;

class fraction
{
	private:
		int num,den;
	public:
		fraction(){}  //default constructor.
		~fraction(){}  //destructor.
		fraction(int n,int d)  //parameterised constructor.
		{num=n;den=d;}
		void read()  //To get fractions from the user.
		{char c;cin>>num>>c>>den;}

		void disp()const  //To display fraction
		{cout<<num<<'/'<<den;}

		fraction operator +(fraction f)  //Add two fractions.
		{return fraction(num*f.den+den*f.num,den*f.den);}
		fraction operator -(fraction f)  //Find difference of two fractions
		{return fraction(num*f.den-den*f.num,den*f.den);}
		fraction operator *(fraction f)  //Product of two fractions.
		{return fraction(num*f.num,den*f.den);}
		fraction operator /(fraction f)  //Quotient (in fraction form) of two fractions.
		{return fraction(num*f.den,den*f.num);}

		void fraccheck(fraction f,char c);
		void gcd();		//GCD of numerator and denominator.
		
		bool operator ==(fraction f)  //return true if f1 is equal to f2 both by numerator and denominator.
		{return (num==f.num)?((den==f.den)?1:0):0;}
		
		bool operator !=(fraction f)  //return true if f1 is not equal to f2 by either numerator or denominator.
		{return (num==f.num)?((den==f.den)?0:1):1;}
};

int main()
{
	fraction f1,f2,fr;
	char c,q='y';
	
	while(q=='y'||q=='Y')
	{
		cout<<"Enter first fraction: ";
		f1.read();
		cout<<"Enter second fraction: ";
		f2.read();
		cout<<"Enter operator(+,-,*,/)(defualt:+): ";
		cin>>c;
		
		f1.fraccheck(f2,c);  //check for possible negative outcome. 
		
		switch(c)
		{
			case '-': fr=f1-f2;break;
			case '*': fr=f1*f2;break;
			case '/': fr=f1/f2;break;
			default: fr=f1+f2;
			
		}
		
		fr.gcd();
		cout<<"Resulting fraction: ";
		fr.disp();
		
		//Using overloaded operators == and != .
		cout<<"\nf1==f2 is ";(f1==f2)?cout<<"true.":cout<<"false.";
		cout<<"\nf1!=f2 is ";(f1!=f2)?cout<<"true.":cout<<"false.";
		
		cout<<"\nGo again (y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

void fraction::fraccheck(fraction f,char c)
{
	if((c=='/' && den*f.num==0)||((c=='+'||c=='-'||c=='*')&&den*f.den==0))
	{
		cout<<"Denominator results in 0. Exiting.\n";
		exit(1);
	}
}

void fraction::gcd()
{
	if(num!=0)
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
	
}