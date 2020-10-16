/*
--PROGRAM NAME: rlch4e10.cpp
--PROGRAM STATEMENT: Create a structure called sterling that stores money amounts 
in the old-style British system discussed in Exercises 8 and 11 in Chapter 3, 
“Loops and Decisions.” The members could be called pounds, shillings, and pence, 
all of type  int. The program should ask the user to enter a money amount in 
new-style decimal pounds (type double), convert it to the old-style system, 
store it in a variable of type struct sterling, and then display this amount in 
pounds-shillings-pence format.
*/

#include<iostream>
#include<cmath>
using namespace std;

struct sterling
{
	int pounds,shillings,pence;
};

int main()
{
	sterling s;
	double n;
	int np,npe;	//new style pounds and pence.
	
	cout<<"Enter amount in new-style decimal pounds(£): ";
	cin>>n;
	
	np=floor(n);		//Extract only pounds.
	npe=(n-np)*100;		//Extracting pence.
	npe+=np*100;		//All amount in pence.
	npe*=2.4;			//Equalising to old currency. 2.4*(new_pence)=1*(old_pence).
											//Old system: 1 pound=20 shillings, 1 shilling=12 pence, 1 pound=240 pence.
											//New system: 1 pound=100 pence.
	
	s.pounds=npe/240;		//Extracting old style pounds.
	s.shillings=(npe%240)/12;		//Extrafting shillings.
	s.pence=npe%12;			//Extracting old style pence.
	
	cout<<"Amount is: £"<<s.pounds<<'.'<<s.shillings<<'.'<<s.pence<<endl;
	
	return 0;
}