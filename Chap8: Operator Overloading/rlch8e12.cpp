/*
--PROGRAM NAME: rlch8e12.cpp
--PROGRAM STATEMENT: Write a program that incorporates both the bMoney class from 
Exercise 8 and the sterling class from Exercise 11. Write conversion operators to 
convert between bMoney and sterling,assuming that one pound (£1.0.0) equals fifty 
dollars ($50.00). This was the approximate exchange rate in the 19th century when 
the British Empire was at its height and the pounds-shillings-pence format was in 
use. Write a main() program that allows the user to enter an amount in either 
currency and then converts it to the other currency and displays the result. 
Minimize any modifications to the existing bMoney and sterling classes.
*/
#include<iostream>
#include<string>
#include<sstream>  //string stream.
#include<cmath>  //fabs()
using namespace std;

class sterling
{
	private:
		long pounds;  //1 pound = 20 shillings = 240 pence.
		int shillings, pence;  //1 shilling = 12 pence.
	public:
		sterling(){}  //Default constructor
		~sterling(){}  //destructor
		sterling(long pence1);  //To convert from new style pounds to old sterling style.
		sterling(long po,int sh,int pe):pounds(po),shillings(sh),pence(pe){}
		void getsterling();  //get user i/p for old sterling style.
		void putsterling()  //Display amount in £pounds.shillings.pence format.
		{cout<<"£"<<pounds<<"."<<shillings<<"."<<pence;}
		operator double()  //Old style pounds to new style pounds(type double) conversion.
		{return double(pounds*240+shillings*12+pence)/240;}  //Notice the inbuilt casting. Only numerator casting.
		
		long double rpence()
		{return (long double)(pounds*240+shillings*12+pence);}
};

class bMoney
{
	private:
		string smoney;
		long double ldmoney;
	public:
		bMoney(){}
		~bMoney(){}
		bMoney(string sm){smoney=sm;mstold();}  //Constructor for string money argument.
		bMoney(long double ldm){ldmoney=ldm;ldtoms();}  //Constructor for long double money argument.
		
		void getmoney()  //Gets money as string and and stores in long double as well.
		{cin>>smoney;mstold();}
		void putmoney()  //Displays money string.
		{cout<<smoney;}
		void mstold();  //money string to money long double.
		void ldtoms();  //money long double to money string.
		
		operator sterling()const  //dollars to pounds.
		{return sterling(long(ldmoney/0.2083));}
		
		void pound_to_dollar(long double ldp)
		{ldmoney=ldp;ldtoms();}

};

int main(void)
{
	sterling s1;
	bMoney bm1;
	char q='y';
	int choice;
	
	cout<<"£1.0.0=$50.00, £0.1.0=$2.5, £0.0.1=$0.2083\n";
	cout<<"****Please note that we couldn't make conversion operator for \
	sterling to bMoney. To create operator bMoney, bMoney is not visible to sterling.\n";
	
	while(q=='y'||q=='Y')
	{
		cout<<"Enter 1 to convert from dollars($) to pounds(£), 2 to convert otherway around: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter amount in dollars(format: $xxx,xxx.xxx,xx): ";
				bm1.getmoney();
				s1=bm1;
				cout<<"= ";s1.putsterling();
				break;
			case 2:
				cout<<"Enter amount in pounds ";
				s1.getsterling();
				bm1.pound_to_dollar(s1.rpence()*0.2083);
				cout<<"= ";bm1.putmoney();
				
		}
		cout<<"Flaw: Conversion not accurate. We receive suggestions.\n";
		cout<<"\nGo again(y/n)?: ";
		cin>>q;
	}
	return 0;
}

void bMoney::mstold()
{
	string m=smoney;
	m.erase(0,1);  //Remove $ sign
	while(m.find(',')>0 && m.find(',')<m.size()-1)  //within the limit of string size.
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

void sterling::getsterling()
{
	char c;  //dummy character.
	cout<<"(format: pounds.shillings.pence)= £";
	cin>>pounds>>c>>shillings>>c>>pence;
}

sterling::sterling(long pence1) //new style pounds to sterling style pounds.
{
	pounds=long(pence1/240);  //pounds=9
	shillings=int((pence1%240)/12);  //shillings=11
	pence=int(pence1%12);  //pence=9
	
}
