/*
--PROGRAM NAME: rlch9e9.cpp
--PROGRAM STATEMENT: Start with the publication, book, and tape classes 
of Exercise 1. Suppose you want to add the date of publication for both books 
and tapes. From the publication class, derive a new class called publication2 
that includes this member data. Then change book and tape so they are derived 
from publication2 instead of publication. Make all the necessary changes in 
member functions so the user can input and output dates along with the other 
data. For the dates, you can use the date class from Exercise 5 in Chapter 6, 
which stores a date as three  ints, for month, day, and year.
*/
#include<iostream>
#include<string>
using namespace std;
//-------------------------------------------------------------------------//
class publication
{
	protected:
		string title;
		float price;
	public:
		publication():title(""),price(0.0){}  //Constructor with no parameters.
		~publication(){}  //Destructor.
		publication(string t,float p):title(t),price(p){}  //Parameterised constructor.
		
		void getdata();
		void putdata()const;
};
//-------------------------------------------------------------------------//
class date
{
	private:
		int day,month,year;
	public:
		date():day(1),month(1),year(1920){}		//constructor initialisation.
		~date(){}		//destructor.
		date(int d,int m,int y):day(d),month(m),year(y){}
		
		void getdate()
		{char c;cin>>day>>c>>month>>c>>year;}
		void showdate()const
		{cout<<day<<'/'<<month<<'/'<<year;}

};
//-------------------------------------------------------------------------//
class publication2:public publication
{
	private:
		date d1;
	public:
		publication2():publication(){}
		~publication2(){}
		publication2(string t,float p, date d):
		publication(t,p),d1(d){}
		
		void getdata();
		void putdata()const;
};
//-------------------------------------------------------------------------//
class book:public publication2  //derived from class publication
{
	private:
		int page_count;
	public:
		book():publication2(),page_count(0){}  //Constructor with no parameters.
		~book(){}
		book(string t,float p,date d,int pc):publication2(t,p,d),page_count(pc){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};
//-------------------------------------------------------------------------//
class tape:public publication2  //Derived from class publication.
{
	private:
		float minutes;
	public:
		tape():publication2(),minutes(0.0){}  //Constructor with no parameters.
		~tape(){}
		tape(string t,float p,date d,float m):publication2(t,p,d),minutes(m){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};
//----------------------------START OF MAIN()---------------------------------//
int main(void)
{
	date d1(23,11,2012),d2(10,9,1996);
	book b1("Inheritance",56.54,{23,11,2012},50);
	//book b1("Inheritance",56.54,(23,11,2012),50); doesn't work.
	tape t1("Generalisation",50.45,d2,16.54);
	
	//Display initialised data
	b1.putdata();
	cout<<endl;
	t1.putdata();
		
	//get data from user.
	cout<<"\n\nEnter data for book version of the work:\n";
	b1.getdata();
	cout<<"\nEnter data for tape version of the work:\n";
	t1.getdata();
	
	//Display user inputted data
	cout<<endl;
	b1.putdata();
	cout<<endl;
	t1.putdata();
	
	cout<<endl;
	return 0;
}
//-----------------------------END OF MAIN()--------------------------------//
void publication::getdata()
{
	cout<<"Enter title: ";
	/*
	When cin.getline() or getline(cin,name) reads from the input, there is a 
	newline character left in the input stream (by the cin commands used before), 
	so it doesn't read your c-string. Use cin.ignore() beore calling getline().
	*/

	getline(cin,title);
	cout<<"Enter price: ";
	cin>>price;
	
}
//-------------------------------------------------------------------------//
void publication::putdata()const
{
	cout<<"Title: "<<title<<"\nPrice: "<<price;
}
//-----------------------------END OF MAIN()--------------------------------//
void publication2::getdata()
{
	publication::getdata();
	cout<<"Enter date(format: dd/mm/yyyy): ";d1.getdate();
}
//-------------------------------------------------------------------------//
void publication2::putdata()const
{
	publication::putdata();
	cout<<"\nDate: ";d1.showdate();
}
//-------------------------------------------------------------------------//
void book::getdata()
{
	cout<<"Book version of the work:\n";
	publication2::getdata();
	cout<<"Enter no. of pages: ";
	cin>>page_count;
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}
//-------------------------------------------------------------------------//
void book::putdata()const
{
	cout<<"Book version of the work:\n";
	publication2::putdata();
	cout<<"\nPage count: "<<page_count;
}
//-------------------------------------------------------------------------//
void tape::getdata()
{
	cout<<"Audio cassette(tape) version of the work:\n";
	publication2::getdata();
	cout<<"Enter time in minutes: ";
	cin>>minutes;
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}
//-------------------------------------------------------------------------//
void tape::putdata()const
{
	cout<<"Audio cassette(tape) version of the work:\n";
	publication2::putdata();
	cout<<"\nTime(in minutes): "<<minutes;
}
//-------------------------------------------------------------------------//
