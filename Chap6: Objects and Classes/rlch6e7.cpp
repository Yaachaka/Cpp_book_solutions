/*
--PROGRAM NAME: rlch6e7.cpp
--PROGRAM STATEMENT: In ocean navigation, locations are measured in degrees and 
minutes of latitude and longitude. Thus if you’re lying off the mouth of Papeete 
Harbor in Tahiti, your location is 149 degrees 34.8 minutes west longitude, and 
17 degrees 31.5 minutes south latitude. This is written as 149°34.8’ W, 17°31.5’ S. 
There are 60 minutes in a degree. (An older system also divided a minute into 60 
seconds, but the modern approach is to use decimal minutes instead.) Longitude is 
measured from 0 to 180 degrees, east or west from Greenwich, England, to the 
international dateline in the Pacific. Latitude is measured from 0 to 90 degrees, 
north or south from the equator to the poles. Create a class angle that includes 
three member variables: an  int for degrees, a float for minutes, and a char for 
the direction letter (N, S, E, or W). This class can hold either a latitude 
variable or a longitude variable. Write one member function to obtain an angle 
value (in degrees and minutes) and a direction from the user, and a second to 
display the angle value in 179°59.9’ E format. Also write a three-argument 
constructor. 
Write a main() program that displays an angle initialized with the constructor, 
and then, within a loop, allows the user to input any angle value, and then 
displays the value. You can use the hex character constant ‘\xF8’, which usually 
prints a degree (°) symbol.
*/
#include<iostream>
using namespace std;

class angle
{
	private:
		int degrees;
		float minutes;
		char c;	//To store direction (E, W, N, S).
	public:
		angle(){}		//default constructor.
		angle(int d,float m,char cc):degrees(d),minutes(m),c(cc){}	//Parameterised constructor.
		~angle(){}		//destructor.
		void getangle();
		void showangle()const;
};

int main()
{
	angle a,b(179,59.5,'E');
	char q='y';
	
	cout<<"Constructor initialised co-ordinate: ";
	b.showangle();
	cout<<endl;
	
	while(q=='y'||q=='Y')
	{
		cout<<"Enter co-ordinate: \n";
		a.getangle();
		
		cout<<"Entered co-ordinate: ";
		a.showangle();
		cout<<"\nGo again(y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

void angle::getangle()
{
	cout<<"Enter degrees: ";
	cin>>degrees;
	cout<<"Enter minutes: ";
	cin>>minutes;
	c='E';
	cout<<"Enter direction(E,W,N,S)(default:E): ";
	cin>>c;
	c=toupper(c);
	switch(c)
	{
		case	'W': c='W';break;
		case 'N': c='N';break;
		case 'S': c='S';break;
		default: c='E';
		
	}
}

void angle::showangle()const
{
	cout<<degrees<<"\u00B0"<<minutes<<'\''<<' '<<c;
	//'\xF8' did not work for me.
	//I am using unicode character code. "\u00B0" = °.
	//Do not write '\u00B0' or "\uB0". Error pops up.
}