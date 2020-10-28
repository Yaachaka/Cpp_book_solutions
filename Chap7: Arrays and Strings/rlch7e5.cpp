/*
--PROGRAM NAME: rlch7e5.cpp
--PROGRAM STATEMENT: Start with the fraction class from Exercises 11 and 12 in 
Chapter 6. Write a main() program that obtains an arbitrary number of fractions 
from the user, stores them in an array of type fraction, averages them, and 
displays the result.
*/
#include<iostream>
#include<ctime>		//time()
#include<cstdlib>		//rand(), srand()
#include<cmath>		//abs()
using namespace std;

class fraction
{
	private:
		int num,den;		//numerator and denominator.
	public:
		void readfrac();
		void dispfrac()const;
		void avgfrac(fraction [],int);
		void gcdfrac();
};

int main()
{
	srand(time(NULL));
	const int MAX=10;
	int m=2+rand()%(MAX-2+1);		//To get arbitrary number of fractions (Max=10).
	fraction f[MAX],favg;
	
	//Get fractions from user.
	cout<<"Enter "<<m<<" fractions: \n";
	for(int i=0;i<m;i++)
		f[i].readfrac();
	//Finding average of m no. of elements and displaying it.
	favg.avgfrac(f,m);
	cout<<"Average of given "<<m<<" fractions: ";
	favg.dispfrac();
	cout<<endl;
	
	return 0;
}

void fraction::readfrac()
{
	char c;		//Dummy character. To place '/' while entering fraction.
	cin>>num>>c>>den;
}

void fraction::dispfrac()const
{
	cout<<num<<'/'<<den;
}

void fraction::avgfrac(fraction f[],int n)
{
	fraction fa;
	num=f[0].num;
	den=f[0].den;
	//summing all the fractions in the array.
	for(int i=1;i<n;i++)
	{
		num=num*f[i].den+den*f[i].num;
		den*=f[i].den;
	}
	//Finding the average.
	fa.num=num;
	fa.den=den*n;
	//reducing the fraction.
	fa.gcdfrac();
	num=fa.num;
	den=fa.den;
}

void fraction::gcdfrac()
{
	int n=abs(num),d=abs(den),r=1;//n-numerator, d-denominator, r-remainder
								
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
	}
	num/=n;
	den/=n;
}