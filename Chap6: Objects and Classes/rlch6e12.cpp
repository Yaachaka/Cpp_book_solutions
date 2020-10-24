/*
--PROGRAM NAME: rlch6e12.cpp
--PROGRAM STATEMENT: Note that one advantage of the OOP approach is that an 
entire class can be used, without modification, in a different program. Use the 
fraction class from Exercise 11 in a program that generates a multiplication 
table for fractions. Let the user input a denominator, and then generate all 
combinations of two such fractions that are between 0 and 1, and multiply them 
together. Here’s an example of the output if the denominator is 6:
					1/6     1/3    1/2    2/3    5/6
-----------------------------------------
1/6    1/36    1/18   1/12   1/9    5/36
1/3    1/18    1/9    1/6    2/9    5/18
1/2    1/12    1/6    1/4    1/3    5/12
2/3    1/9     2/9    1/3    4/9    5/9
5/6    5/36    5/18   5/12   5/9    25/36
*/
#include<iostream>
#include<iomanip>		//setw(), setfill(), right, left.
#include<ncurses.h>
using namespace std;

class fraction
{
	private:
		int num,den;
	public:
		void read();
		void disp()const;
		void mul(fraction);
		void rep(fraction,fraction,fraction,fraction,fraction,fraction);
};

int main()
{
	fraction f,f1,f2,f3,f4,f5;
	//Taking user input.
	cout<<"Enter five fractions: \n";
	f1.read();
	f2.read();
	f3.read();
	f4.read();
	f5.read();
	//Displaying entered fractions as row head of the table
	cout<<left<<setw(8)<<"";
	f1.disp();cout<<setw(3)<<"";
	f2.disp();cout<<setw(3)<<"";
	f3.disp();cout<<setw(3)<<"";
	f4.disp();cout<<setw(3)<<"";
	f5.disp();cout<<setw(3)<<"";
	//Underlining the head of the table.
	cout<<endl<<setw(48)<<setfill('-')<<""<<setfill(' ')<<""<<endl;
	f=f1;f.rep(f,f1,f2,f3,f4,f5);
	f=f2;f.rep(f,f1,f2,f3,f4,f5);
	f=f3;f.rep(f,f1,f2,f3,f4,f5);
	f=f4;f.rep(f,f1,f2,f3,f4,f5);
	f=f5;f.rep(f,f1,f2,f3,f4,f5);
	
	return 0;
}

void fraction::read()
{
	char c;
	cin>>num>>c>>den;
}

void fraction::disp()const
{
	cout<<setw(2)<<right<<num<<'/'<<setw(2)<<left<<den;
}

void fraction::mul(fraction f)
{
	num*=f.num;
	den*=f.den;
}

void fraction::rep(fraction f,fraction f1,fraction f2,fraction f3,fraction f4,fraction f5)
{
	fraction f6=f;
	f.disp();cout<<setw(3)<<"";		//To display column header.
	f.mul(f1);f.disp();f=f6;cout<<setw(3)<<"";
	f.mul(f2);f.disp();f=f6;cout<<setw(3)<<"";
	f.mul(f3);f.disp();f=f6;cout<<setw(3)<<"";
	f.mul(f4);f.disp();f=f6;cout<<setw(3)<<"";
	f.mul(f5);f.disp();f=f6;cout<<setw(3)<<"";
	cout<<endl;
}