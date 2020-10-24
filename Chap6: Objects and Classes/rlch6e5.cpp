/*
--PROGRAM NAME: rlch6e5.cpp
--PROGRAM STATEMENT: Start with the date structure in Exercise 5 in Chapter 4 and 
transform it into a date class. Its member data should consist of three ints: 
month, day, and year. It should also have two member functions: getdate(), which 
allows the user to enter a date in 12/31/02 format, and showdate(), which displays 
the date.
*/
#include<iostream>
using namespace std;

class date
{
	private:
		int day,month,year;
	public:
		date():day(1),month(1),year(1920){}		//constructor initialisation.
		~date(){}		//destructor.
		void getdate();
		void showdate()const;
};

int main()
{
	date d;
	cout<<"Enter date(D:M:Y): ";
	d.getdate();
	cout<<"Entered date(D:M:Y): ";
	d.showdate();
	cout<<endl;
	return 0;
}

void date::getdate()
{
	char c;	//To place a dummy character. To place /.
	cin>>day>>c>>month>>c>>year;
}

void date::showdate() const
{
	cout<<day<<'/'<<month<<'/'<<year;
}