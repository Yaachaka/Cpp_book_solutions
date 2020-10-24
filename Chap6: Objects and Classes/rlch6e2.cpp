/*
--PROGRAM NAME: rlch6e2.cpp
--PROGRAM STATEMENT: Imagine a tollbooth at a bridge. Cars passing by the booth 
are expected to pay a 50 cent toll. Mostly they do, but sometimes a car goes by 
without paying. The tollbooth keeps track of the number of cars that have gone by, 
and of the total amount of money collected.Model this tollbooth with a class 
called  tollBooth. The two data items are a type unsigned int to hold the total 
number of cars, and a type double to hold the total amount of money collected. A 
constructor initializes both of these to 0. A member function called payingCar() 
increments the car total and adds 0.50 to the cash total. Another function, called 
nopayCar(),increments the car total but adds nothing to the cash total. Finally, 
a member function called display() displays the two totals. Make appropriate 
member functions const. Include a program to test this class. This program should 
allow the user to push one key to count a paying car, and another to count a 
nonpaying car. Pushing the Esc key should cause the program to print out the total 
cars and total cash and then exit.
*/
#include<iostream>
//#include<conio.h>		//getch(). Windows based.
#include<curses.h>			//getchar(). Linux based.
using namespace std;

class tollBooth
{
	private:
		unsigned int ncars;
		double amount;
	public:
		tollBooth():ncars(0),amount(0.00)		//constructor initialisation.
		{}
		~tollBooth(){}		//destructor.
		void payingCar()
		{
			cout<<"A car paid toll.\n";
			ncars++;
			amount+=0.50;
		}
		void nopayCar()
		{
			cout<<"A car has not paid toll.\n";
			ncars++;
		}
		void display()const
		{
			cout<<"Total no. of cars: "<<ncars;
			cout<<"\nTotal amount($): "<<amount;
		}
};

int main()
{
	tollBooth tb;
	char c='\0';
	cout<<"Press key \'P\' to account paying car, \
		\n\tkey \'N\' to account non-paying car and \
		\n\tkey \'ESC\' to stop counting and see the totals:\n";
	
	while((c=getchar())!='\e')
	{
		if(c=='p'||c=='P')
			tb.payingCar();
		if(c=='n'||c=='N')
			tb.nopayCar();
	}
	
	tb.display();
	cout<<endl;
	
	return 0;
}