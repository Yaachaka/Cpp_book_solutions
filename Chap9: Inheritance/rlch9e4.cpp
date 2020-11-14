/*
--PROGRAM NAME: rlch9e4.cpp
--PROGRAM STATEMENT: Assume that the publisher in Exercises 1 and 3 
decides to add a third way to distribute books: on computer disk, for those 
who like to do their reading on their laptop. Add a disk class that, like book 
and tape, is derived from publication. The disk class should incorporate the 
same member functions as the other classes. The data item unique to this class 
is the disk type: either CD or DVD. You can use an enum type to store this item. 
The user could select the appropriate type by typing c or d.
*/
#include<iostream>
#include<string>
using namespace std;

enum enum_disk{CD, DVD};
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

class disk:public publication, public sales  //derived from class publication
{
	private:
		enum_disk ed;
	public:
		disk():publication(),ed(enum_disk(0)),sales(){}  //Constructor with no parameters.
		~disk(){}
		disk(string t,float p,enum_disk edk,float sm[])
		:publication(t,p),ed(edk),sales(sm){}  //parameterised constructor.
		
		void getdata();
		void putdata()const;
};

//////////////////////////////START OF MAIN()////////////////////////////////////
int main(void)
{
	float arr1[]={2*56.54,3*56.54,5*56.54};
	float arr2[]={2*50.45,3*50.45,5*50.45};
	book b1("Inheritance", 56.54, 50, arr1);
	tape t1("Generalisation", 50.45, 16.54, arr2);
	disk d1("Specialisation", 50.45, enum_disk(0), arr2);
	
	//Display initialised data
	b1.putdata();
	cout<<endl;
	t1.putdata();
	cout<<endl;
	d1.putdata();
		
	//get data from user.
	cout<<"\n\nEnter data for book version of the work:\n";
	b1.getdata();
	cout<<"\nEnter data for tape version of the work:\n";
	t1.getdata();
	cout<<"\nEnter data for disk version of the work:\n";
	d1.getdata();
	
	//Display user inputted data
	cout<<endl;
	b1.putdata();
	cout<<endl;
	t1.putdata();
	cout<<endl;
	d1.putdata();
	
	cout<<endl;
	return 0;
}
////////////////////////////END OF MAIN()////////////////////////////////////////

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
	//Remove "\e[31;1;3m" if doesn't work on other OS/terminal.
	cout<<"Title: \e[31;1;3m"<<title;  //ESC[color;bold;(Italic/light intensity) in linux terminal.
	                                 //red color, no bold, italic.
	cout<<"\e[0m\nPrice: $"<<price;  //Normal font style. white color
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

void disk::getdata()
{
	cout<<"Disk version of the work:\n";
	publication::getdata();
	char c;
	cout<<"Choose disk type: Enter c for CD or d for DVD: ";
	cin>>c;
	switch(c)
	{
		case 'c':
			ed=enum_disk(0);
			break;
		case 'd':
			ed=enum_disk(1);
		
	}
	sales::getdata();
	cin.ignore();  //To ignore '\n' from std::istream(That gets fed to getline()).
}

void disk::putdata()const
{
	cout<<"Disk version of the work:\n";
	publication::putdata();
	cout<<"\nDisk type: ";
	switch(ed)
	{
		case 0:
			cout<<"CD";
			break;
		case 1:
			cout<<"DVD";
		
	}
	sales::putdata();
}