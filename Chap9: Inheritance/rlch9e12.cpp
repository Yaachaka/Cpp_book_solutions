/*
--PROGRAM NAME: rlch9e12.cpp
--PROGRAM STATEMENT: Amazing as it may seem, the old British 
pounds-shillings-pence money notation (£9.19.11—see Exercise 10 in Chapter 4, 
“Structures”) isn’t the whole story. A penny was further divided into 
halfpennies and farthings, with a farthing being worth 1/4 of a penny. There 
was a halfpenny coin, a farthing coin, and a halffarthing coin. Fortunately 
all this can be expressed numerically in eighths of a penny: 
	1/8 penny is a halffarthing 
	1/4 penny is a farthing 
	3/8 penny is a farthing and a half 
	1/2 penny is a halfpenny (pronounced ha’penny) 
	5/8 penny is a halfpenny plus a halffarthing 
	3/4 penny is a halfpenny plus a farthing 
	7/8 penny is a halfpenny plus a farthing and a half 
Let’s assume we want to add to the sterling class the ability to handle such 
fractional pennies. The I/O format can be something like £1.1.1-1/4 or 
£9.19.11-7/8, where the hyphen separates the fraction from the pennies. 
Derive a new class called sterfrac from sterling. It should be able to perform 
the four arithmetic operations on sterling quantities that include eighths of 
a penny. Its only member data is an int indicating the number of eighths; you 
can call it eighths. You’ll need to overload many of the functions in sterling 
to handle the eighths. The user should be able to type any fraction in lowest 
terms, and the display should also show fractions in lowest terms. It’s not 
necessary to use the full-scale fraction class (see Exercise 11 in Chapter 6), 
but you could try that for extra credit.
*/
/*
• no-argument constructor
• one-argument constructor, taking type double (for converting from decimal)
• three-argument constructor, taking pounds, shillings, and pence
• getSterling() to get an amount in pounds, shillings, and pence from the user, 
format £9.19.11
• putSterling() to display an amount in pounds, shillings, and pence, format 
£9.19.11
• addition (sterling + sterling) using overloaded + operator
• subtraction (sterling - sterling) using overloaded - operator
• multiplication (sterling * double) using overloaded * operator
• division (sterling / sterling) using overloaded / operator
• division (sterling / double) using overloaded / operator
• operator double (to convert to double)
*/
#include<iostream>
#include<cmath>  //fabs()
using namespace std;
//------------------------------------------------------------------------//
class sterling
{
	protected:
		long pounds;  //1 pound = 20 shillings = 240 pence.
		int shillings, pence;  //1 shilling = 12 pence.
	public:
		//Constructors
		sterling(){}  //Default constructor
		~sterling(){}  //destructor
		sterling(double new_pounds);  //To convert from double to sterlin.
		sterling(long po,int sh, int pe):pounds(po),shillings(sh),pence(pe){}
		
		//User interaction
		void getsterling()  //get user i/p for sterling.
		{char c;cin>>pounds>>c>>shillings>>c>>pence;}
		void putsterling()const //Display amount in £pounds.shillings.pence format.
		{cout<<"£"<<pounds<<"."<<shillings<<"."<<pence;}
		/*
		//Internal operations
		sterling operator +(sterling s2)  //Adding 2 amounts.
		{return sterling(double(sterling(pounds,shillings,pence)) + double(s2));}
		sterling operator -(sterling s2)  //Difference of 2 amounts.
		{return sterling(fabs(double(sterling(pounds,shillings,pence)) - double(s2)));}
		sterling operator *(double dd)  //Product of amount and a factor of type double.
		{return sterling(double(sterling(pounds,shillings,pence))*dd);}
		double operator /(sterling s2)  //Division of an amount by an amount resulting in a quantity(factor).
		{return double(sterling(pounds,shillings,pence))/double(s2);}
		sterling operator /(double dd)  //Division of an amount by a factor resulting an amount.
		{return sterling(double(sterling(pounds,shillings,pence))/dd);}
		
		operator double()  //Old style pounds to new style pounds(type double) conversion.
		{return double(pounds*240+shillings*12+pence);}  //Notice the inbuilt casting. Only numerator casting.
		*/
};
//------------------------------------------------------------------------//
class sterfrac:public sterling
{
	private:
		int eighth;
	public:
		//Constructors and destructor
		sterfrac():sterling(),eighth(0){}
		~sterfrac(){}
		sterfrac(long po,int sh, int pe,int ei)
		:sterling(po,sh,pe),eighth(ei){}
		sterfrac(sterling s,int ei):sterling(s),eighth(ei){}
		
		//User interaction
		void getsterling()
		{
			cout<<"(Note: Pounds(start at 0),shillings(0 to 19), pence(0 to 11), "
			<<"\nn-no. of eights(1 to 7))";
			cout<<"\n(format: £pounds.shillings.pence-n/8)= £";
			sterling::getsterling();
			char c;
			cin>>c>>eighth>>c>>c;
		}
		void putsterling()
		{sterling::putsterling();cout<<"-"<<eighth<<"/8";}
		
		//Internal operations.
		sterfrac operator +(sterfrac s2)  //Adding 2 amounts.
		{
			double dd=double(sterfrac(pounds,shillings,pence,eighth)) + double(s2);
			return sterfrac(sterling(dd),int((dd-floor(dd))*8));
		}
		sterfrac operator -(sterfrac s2)  //Difference of 2 amounts.
		{
			double dd=fabs(double(sterfrac(pounds,shillings,pence,eighth)) - double(s2));
			return sterfrac(sterling(dd),int((dd-floor(dd))*8));
		}
		sterfrac operator *(double dd)  //Product of amount and a factor of type double.
		{
			dd*=double(sterfrac(pounds,shillings,pence,eighth));
			return sterfrac(sterling(dd),int((dd-floor(dd))*8));
		}
		double operator /(sterfrac s2)  //Division of an amount by an amount resulting in a quantity(factor).
		{return double(sterfrac(pounds,shillings,pence,eighth))/double(s2);}
		sterfrac operator /(double dd)  //Division of an amount by a factor resulting an amount.
		{
			dd=double(sterfrac(pounds,shillings,pence,eighth))/dd;
			return sterfrac(sterling(dd),int((dd-floor(dd))*8));
		}
		
		operator double()
		{return double(pounds*240+shillings*12+pence+eighth/8.0);}
};
//--------------------------START OF MAIN()--------------------------------//
int main(void)
{
	sterling st(23,14,5);
	sterfrac s1(34,15,9,6),s2(23,11,3,4),s3(st,7),ssum,sdif,sprod,sdiv;
	double dd;
	//Description of amount features.
	cout<<"Sterling: 1 pound = 20 shillings = 240 pence. ranges: shillings(0-19), pence(0-11).";
	
	//Displaying initialised amounts.
	cout<<"\ns1= ";s1.putsterling();
	cout<<"\ns2= ";s2.putsterling();
	cout<<"\ns2= ";s3.putsterling();
	
	//Getting amounts from user.
	cout<<"\nEnter amount s1";s1.getsterling();
	cout<<"Enter amount s2";s2.getsterling();
	cout<<"Enter multiplier: ";cin>>dd;
	
	//sterling=sterling+sterling
	cout<<"\n----sterling = sterling + sterling----\n";
	ssum=s1+s2;
	cout<<"ssum(=s1+s2)= ";ssum.putsterling();
	
	//sterling=sterling-sterling
	cout<<"\n\n----sterling = sterling - sterling----\n";
	sdif=s1-s2;
	cout<<"sdif(=s1-s2)= ";sdif.putsterling();
	
	//sterling=sterling*double
	cout<<"\n\n----sterling = sterling * double----\n";
	sprod=s1*dd;
	cout<<"sprod(=s1*dd)= ";sprod.putsterling();
	
	//double=sterling/sterling
	cout<<"\n\n----double = sterling / sterling----\n";
	dd=s1/s2;
	cout<<"dd(=s1/s2)= ";cout<<dd;
	
	//sterling=sterling/double
	cout<<"\n\n----sterling = sterling / double----\n";
	sdiv=s1/dd;
	cout<<"sdiv(=s1/dd)= ";sdiv.putsterling();
	
	cout<<endl;
	return 0;
}
//-----------------------------END OF MAIN()---------------------------------//

sterling::sterling(double dd)
{
	pounds=long(dd/240);
	shillings=int(int(dd)%240/12);
	pence=int(dd)%12;
	
}

//------------------------------------------------------------------------//
//------------------------------------------------------------------------//