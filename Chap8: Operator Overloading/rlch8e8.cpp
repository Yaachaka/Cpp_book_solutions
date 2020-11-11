/*
--PROGRAM NAME: rlch8e8.cpp
--PROGRAM STATEMENT: Modify the bMoney class from Exercise 12 in Chapter 7, 
“Arrays and Strings,” to include the following arithmetic operations, performed 
with overloaded operators: 
	bMoney = bMoney + bMoney 
	bMoney = bMoney - bMoney 
	bMoney = bMoney * long double  (price per widget times number of widgets) 
	long double = bMoney / bMoney  (total price divided by price per widget) 
	bMoney = bMoney / long double  (total price divided by number of widgets) 
Notice that the  / operator is overloaded twice. The compiler can distinguish 
between the two usages because the arguments are different. Remember that it’s 
easy to perform arithmetic operations on bMoney objects by performing the same 
operation on their long double data. 
Make sure the main() program asks the user to enter two money strings and a 
floatingpoint number. It should then carry out all five operations and display 
the results. This should happen in a loop, so the user can enter more numbers if 
desired. 
Some money operations don’t make sense: bMoney * bMoney doesn’t represent 
anything real, since there is no such thing as square money; and you can’t add 
bMoney to long double (what’s dollars plus widgets?). To make it impossible to 
compile such illegal operations, don’t include conversion operators for bMoney 
to long double or long double to bMoney. If you do, and you write an expression 
like 
	bmon2 = bmon1 + widgets;  // doesn’t make sense 
then the compiler will automatically convert widgets to  bMoney and carry out 
the addition. Without them, the compiler will flag such conversions as errors, 
making it easier to catch conceptual mistakes.  Also, make any conversion 
constructors explicit. 
There are some other plausible money operations that we don’t yet know how to 
perform with overloaded operators, since they require an object on the right 
side of the operator but  not the left: 
	long double * bMoney  // can’t do this yet: bMoney only on right 
	long double / bMoney  // can’t do this yet: bMoney only on right 
We’ll learn how to handle this situation when we discuss friend functions in 
Chapter 11.
*/
#include<iostream>
#include<string>
#include<sstream>  //string stream.
#include<cmath>  //fabs()
using namespace std;

class bMoney
{
	private:
		string smoney;
		long double ldmoney;
	public:
		bMoney(){}  //Default constructor(no parameters). Here it is necessary, to create
		               //objects without initialisation since other constructors are explicit.
		~bMoney(){}  //destructor.
		explicit bMoney(string sm){smoney=sm;mstold();}  //Constructor for string money argument.
		explicit bMoney(long double ldm){ldmoney=ldm;ldtoms();}  //Constructor for long double money argument.
		
		void getmoney()  //Gets money as string and and stores in long double as well.
		{cin>>smoney;mstold();}
		void putmoney()  //Displays money string.
		{cout<<smoney;}
		void mstold();  //money string to money long double.
		void ldtoms();  //money long double to money string.
		
		bMoney operator +(bMoney m2)  //Adds 2 amounts in long double and store the sum in string form too.
		{return bMoney(ldmoney+m2.ldmoney);}
		bMoney operator -(bMoney m2)  //Difference of 2 amounts in long double and store the sum in string form too.
		{return bMoney(fabs(ldmoney-m2.ldmoney));}
		bMoney operator *(long double ld)  //Product of an amount and a factor in long double and store the sum in string form too.
		{return bMoney(ldmoney*ld);}
		long double operator /(bMoney m2)  //Division of an amount by another amount in long double and store the sum in string form too.
		{return ldmoney/m2.ldmoney;}
		bMoney operator /(long double ld)  //Division of an amount by a factor in long double and store the sum in string form too.
		{return bMoney(ldmoney/ld);}
		
};

int main(void)
{
	bMoney m1,m2,msum,mdiff,total_price,price_per_widget;
	long double n_widgets;
	char q='y';
	
	while(q=='y'||q=='Y')
	{
		//Getting two money strings from the user.
		cout<<"Enter amount m1($xxx,xxx.xxx,xx format): ";
		m1.getmoney();
		cout<<"Enter amount m2($xxx,xxx.xxx,xx format): ";
		m2.getmoney();
		cout<<"Enter no of widgets(a multiplier): ";  //price_per widget being the multiplicand.
		cin>>n_widgets;
		
		//Adding the two amounts and displaying the sum.
		cout<<"\n----bMoney = bMoney + bMoney;----\n";
		msum=m1+m2;
		cout<<"Sum of two amounts(msum=m1+m2): ";
		msum.putmoney();
		
		//Finding difference of two amounts and displaying the difference.
		cout<<"\n\n----bMoney = bMoney - bMoney;----\n";
		mdiff=m1-m2;
		cout<<"Difference of two amounts(mdiff=m1-m2): ";
		mdiff.putmoney();
		
		//total_price=price_per_widget*n_widgets
		cout<<"\n\n----bMoney = bMoney * long double;----\n";
		price_per_widget=m2;
		cout<<"price_per_widget(=m2)= ";price_per_widget.putmoney();
		total_price=price_per_widget*n_widgets;
		cout<<"\ntotal_price(=price_per_widget*n_widgets)= ";
		total_price.putmoney();
		
		//n_widgets=total_price/price_per_widget
		cout<<"\n\n----long double = bMoney / bMoney;----\n";
		price_per_widget=m1;
		cout<<"price_per_widget(=m1)= ";price_per_widget.putmoney();
		n_widgets=total_price/price_per_widget;
		cout<<"\nn_widgets(=total_price/price_per_widget)= "<<n_widgets;
		
		//price_per_widget=total_price/n_widgets
		cout<<"\n\n----bMoney = bMoney / long double;----\n";
		n_widgets+=1;
		cout<<"n_widgets= ";cout<<n_widgets;
		price_per_widget=total_price/n_widgets;
		cout<<"\nprice_per_widget(=total_price/n_widgets)= ";
		price_per_widget.putmoney();
		
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
