/*
--PROGRAM NAME: rlch7e12.cpp
--PROGRAM STATEMENT: Create a class called bMoney. It should store money amounts 
as long doubles. Use the function mstold() to convert a money string entered as 
input into a long double, and the function ldtoms() to convert the long double to 
a money string for display. (See Exercises 6 and 10.). You can call the input and 
output member functions getmoney() and putmoney(). Write another member function 
that adds two bMoney amounts; you can call it madd(). Adding bMoney objects is 
easy: Just add the long double member data amounts in two bMoney objects. Write a 
main() program that repeatedly asks the user to enter two money strings, and then 
displays the sum as a money string. Here’s how the class specifier might look: 
	class bMoney 
	{ 
		private: 
			long double money; 
		public: 
			bMoney(); 
			bMoney(char s[]); 
			void madd(bMoney m1, bMoney m2); 
			void getmoney(); 
			void putmoney(); 
	};
*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class bMoney
{
	private:
		string smoney;
		long double ldmoney;
	public:
		void getmoney();  //Gets money as string and and converts to long double.
		void putmoney();  //Displays money string.
		void madd(bMoney,bMoney);  //Adds 2 amounts in long double and converts the sum to string.
		void mstold();  //money string to money long double.
		void ldtoms();  //money long double to money string.
};

int main(void)
{
	bMoney m1,m2,msum;
	char q='y';
	
	while(q=='y'||q=='Y')
	{
		//Getting two money strings from the user.
		cout<<"Enter amount m1($xxx,xxx.xxx,xx format): ";
		m1.getmoney();
		cout<<"Enter amount m2($xxx,xxx.xxx,xx format): ";
		m2.getmoney();
		
		//Adding the two amounts and displaying the sum.
		msum.madd(m1,m2);
		cout<<"Sum of two amounts(msum=m1+m2): ";
		msum.putmoney();
		
		cout<<"\nGo again(y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

void bMoney::getmoney()
{
	cin>>smoney;
	mstold(); //money string to money long double
}

void bMoney::madd(bMoney m1,bMoney m2)
{
	ldmoney=m1.ldmoney+m2.ldmoney;
	ldtoms();  //money long double to money string.
}

void bMoney::putmoney()
{
	cout<<smoney;
}

void bMoney::mstold()
{
	string m=smoney;
	m.erase(0,1);  //Remove $ sign
	while(m.find(',')>0&&m.find(',')<m.size()-1)
		m.erase(m.find(','),1);
	
	stringstream ss;  //stringstream variable declaration
	ss<<m;  //copying string into string stream.
	
	ss>>ldmoney;  //storing string stream to long double.
}

void bMoney::ldtoms()
{
	stringstream ss;
	
	//Long double to string conversion: Long double to stringstream then stringstream to string.
	//Feeding ss stream with long double value. 
	ss<<fixed<<ldmoney;	//ld will be fed to ss in scientific notation if fixed manipulator is not used.
	//sending string stream to string.
	ss>>smoney;
	
	//Filling necessary symbols: $ and ,
	//Placing commas before decimal point.
	int pos=smoney.find('.');
	for(int i=pos-3;i>0;i-=3)
		smoney.insert(i,",");
	//Placing commas after decimal point.
	pos=smoney.find('.');
	for(int i=pos+4;i<smoney.size();i+=4)
		smoney.insert(i,",");
	smoney.insert(0,"$");
	
}
