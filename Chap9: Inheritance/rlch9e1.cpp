/*
--PROGRAM NAME: rlch9e1.cpp
--PROGRAM STATEMENT: Imagine a publishing company that markets both book 
and audiocassette versions of its works. Create a class publication that stores 
the title (a string) and price (type float) of a publication. From this class 
derive two classes: book, which adds a page count (type int), and tape, which 
adds a playing time in minutes (type float). Each of these three classes should 
have a getdata() function to get its data from the user at the keyboard, and a 
putdata() function to display its data. 
Write a main() program to test the book and tape classes by creating instances 
of them, asking the user to fill in data with getdata(), and then displaying 
the data with putdata().
*/

#include<iostream>
#include<string>
using namespace std;

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

class book:public publication  //derived from class publication
{
	private:
		int page_count;
	public:
		book():publication(),page_count(0){}  //Constructor with no parameters.
		~book(){}
		book(string t,float p,int pc):publication(t,p),page_count(pc){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};

class tape:public publication  //Derived from class publication.
{
	private:
		float minutes;
	public:
		tape():publication(),minutes(0.0){}  //Constructor with no parameters.
		~tape(){}
		tape(string t,float p,float m):publication(t,p),minutes(m){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};

int main(void)
{
	book b1("Inheritance",56.54,50);
	tape t1("Generalisation",50.45,16.54);
	
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

void publication::putdata()const
{
	cout<<"Title: "<<title<<"\nPrice: "<<price;
}

void book::getdata()
{
	cout<<"Book version of the work:\n";
	publication::getdata();
	cout<<"Enter no. of pages: ";
	cin>>page_count;
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}

void book::putdata()const
{
	cout<<"Book version of the work:\n";
	publication::putdata();
	cout<<"\nPage count: "<<page_count;
}

void tape::getdata()
{
	cout<<"Audio cassette(tape) version of the work:\n";
	publication::getdata();
	cout<<"Enter time in minutes: ";
	cin>>minutes;
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}

void tape::putdata()const
{
	cout<<"Audio cassette(tape) version of the work:\n";
	publication::putdata();
	cout<<"\nTime(in minutes): "<<minutes;
}