/*
--PROGRAM NAME: rlch9e3.cpp
--PROGRAM STATEMENT: Start with the publication, book, and tape classes 
of Exercise 1. Add a base class sales that holds an array of three floats so 
that it can record the dollar sales of a particular publication for the last 
three months. Include a getdata() function to get three sales amounts from the 
user, and a putdata() function to display the sales figures. Alter the book 
and tape classes so they are derived from both publication and sales. An object 
of class book or tape should input and output sales data along with its other 
data. Write a main() function to create a book object and a tape object and 
exercise their input/output capabilities.
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

class sales
{
	protected:
		float sales_month[3]={0};
	public:
		sales(){}
		~sales(){}
		sales(float arr[])
		{
			for(int i=0;i<3;i++)
				sales_month[i]=arr[i];
		}
		
		void getdata();
		void putdata()const;
};

class book:public publication, public sales  //derived from class publication
{
	private:
		int page_count;
	public:
		book():publication(),page_count(0),sales(){}  //Constructor with no parameters.
		~book(){}
		book(string t,float p,int pc,float sm[])
		:publication(t,p),page_count(pc),sales(sm){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};

class tape:public publication, public sales  //Derived from class publication.
{
	private:
		float minutes;
	public:
		tape():publication(),minutes(0.0),sales(){}  //Constructor with no parameters.
		~tape(){}
		tape(string t,float p,float m,float sm[])
		:publication(t,p),minutes(m),sales(sm){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};
/////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	float arr1[]={2*56.54,3*56.54,5*56.54};
	float arr2[]={2*50.45,3*50.45,5*50.45};
	book b1("Inheritance", 56.54, 50, arr1);
	tape t1("Generalisation", 50.45, 16.54, arr2);
	
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
/////////////////////////////////////////////////////////////////////////////////

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
	cout<<"Title: "<<title<<"\nPrice: $"<<price;
}

void sales::getdata()
{
	for(int i=0;i<3;i++)
	{
		cout<<"Enter sales amount of month "<<i+1<<": ";
		cin>>sales_month[i];
	}
}

void sales::putdata()const
{
	for(int i=0;i<3;i++)
	{
		cout<<"\nMonth "<<i+1<<" sales amount: $"<<sales_month[i];
	}
}

void book::getdata()
{
	cout<<"Book version of the work:\n";
	publication::getdata();
	cout<<"Enter no. of pages: ";
	cin>>page_count;
	sales::getdata();
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}

void book::putdata()const
{
	cout<<"Book version of the work:\n";
	publication::putdata();
	cout<<"\nPage count: "<<page_count;
	sales::putdata();
}

void tape::getdata()
{
	cout<<"Audio cassette(tape) version of the work:\n";
	publication::getdata();
	cout<<"Enter time in minutes: ";
	cin>>minutes;
	sales::getdata();
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}

void tape::putdata()const
{
	cout<<"Audio cassette(tape) version of the work:\n";
	publication::putdata();
	cout<<"\nTime(in minutes): "<<minutes;
	sales::putdata();
}