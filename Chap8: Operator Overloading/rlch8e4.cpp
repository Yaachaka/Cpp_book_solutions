/*
--PROGRAM NAME: rlch8e4.cpp
--PROGRAM STATEMENT: Create a class Int based on Exercise 1 in Chapter 6. 
Overload four integer arithmetic operators (+, -, *, and /) so that they operate 
on objects of type Int. If the result of any such arithmetic operation exceeds 
the normal range of ints (in a 32-bit environment)— from 2,147,483,648 to 
–2,147,483,647 — have the operator print a warning and terminate the program. 
Such a data type might be useful where mistakes caused by arithmetic overflow are 
unacceptable. Hint: To facilitate checking for overflow, perform the calculations 
using type long double. Write a program to test this class.
*/
#include<iostream>
using namespace std;

class Int
{
	private:
		int i;
	public:
		Int()
			{i=0;}
		Int(int a)
			{i=a;}
		Int operator +(Int i2){return aofcheck((long double)i+i2.i);}
		Int operator -(Int i2){return aofcheck((long double)i-i2.i);}
		Int operator *(Int i2){return aofcheck((long double)i*i2.i);}
		Int operator /(Int i2);
		Int aofcheck(long double);  //Arithmetic Overflow check
		void get(){cin>>i;}
		void disp()const
		{cout<<i;}
};

int main()
{
	Int i1,i2,i3;
	char op;
	cout<<"Enter i2: ";
	i2.get();
	cout<<"Enter i3: ";
	i3.get();
	cout<<"Enter operator(Mis-type will be considered as +): ";
	cin>>op;
	
	switch(op)
	{
		case '-':
			i1=i2-i3;
			cout<<"i1(=i1-i2)= ";
			break;
		case '*':
			i1=i2*i3;
			cout<<"i1(=i1*i2)= ";
			break;
		case '/':
			i1=i2/i3;
			cout<<"i1(=i1/i2)= ";
			break;
		default:
			i1=i2+i3;
			cout<<"i1(=i1+i2)= ";
			break;
		
	}
	i1.disp();
	cout<<endl;
	
	return 0;
}

Int Int::operator /(Int i2)
{
	if(i2.i)
		return aofcheck((long double)i/i2.i);
	cout<<"= ∞    (Divide by 0 error. exit(1)\n)";
	exit(1);
}

Int Int::aofcheck(long double result)
{
	if(result>=-2147483648.0L && result<=2147483647.0L)
		return Int(int(result));
	cout<<"\nArithmetic Overflow: Error 1\n";
	exit(1);
}