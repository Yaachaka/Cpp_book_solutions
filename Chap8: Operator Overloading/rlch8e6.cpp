/*
--PROGRAM NAME: rlch8e6.cpp
--PROGRAM STATEMENT: Add to the time class of Exercise 5 the ability to subtract 
two time values using the overloaded (-) operator, and to multiply a time value 
by a number, of type float, using the overloaded (*) operator.
*/
#include<iostream>
#include<cmath>
using namespace std;

class Time
{
	private:
		int h,m,s;
	public:
		Time():h(0),m(0),s(0){}  //Constructor to initialise data members to 0.
		Time(int hh,int mm,int ss);  //Constructor to initialise data members to default values.
		~Time(){}		//destructor.
		
		int Timetosec()
		{return h*3600+m*60+s;}
		void sectoTime(int sec);
		void Tadjust();  //To meet the condition minutes and seconds range 0-59.

		void display();
		
		Time operator +(Time t2)  //Addition of two times.
		{return Time(0,0,Timetosec()+t2.Timetosec());}
		Time operator -(Time t2)  //Difference of two times.
		{return Time(0,0,abs(Timetosec()-t2.Timetosec()));}
		Time operator *(float f)  //Multiplying a Time by a float.
		{return Time(0,0,int(f*Timetosec()));}
		
		Time operator ++()  //Time increment - prefix notation(i.e., ++Time).
		{return Time(h,m,++s);}
		Time operator ++(int)  //Time increment - postfix notation(i.e., Time++).
		{return Time(h,m,s++);}
		Time operator --()  //Time decrement - prefix notation(i.e., --Time).
		{return Time(h,m,--s);}
		Time operator --(int)  //Time decrement - postfix notation(i.e., Time--).
		{return Time(h,m,s--);}
		
};

int main()
{
	Time t,t1(12,19,59),t2(06,58,59);	 
	
	cout<<"Before t=t1+t2 and t=t1-t2(Difference i.e., t=t1~t2);";
	cout<<"\nt1: ";t1.display();
	cout<<"\nt2: ";t2.display();
	cout<<"\nt: ";t.display();
	
	//Adding t1 and t2 using overloaded operator +
	t=t1+t2;
	cout<<"\nAfter t=t1+t2;";
	cout<<"\nt1: ";t1.display();
	cout<<"\nt2: ";t2.display();
	cout<<"\nt: ";t.display();
	//Differenc of two times.
	t=t1-t2;
	cout<<"\nAfter t=t1-t2(actually t=t1~t2);";
	cout<<"\nt1: ";t1.display();
	cout<<"\nt2: ";t2.display();
	cout<<"\nt: ";t.display();
	
	++t1;
	cout<<"\n\nt1(after ++t1;)= ";t1.display();
	t1++;
	cout<<"\nt1(after t1++;)= ";t1.display();
	--t1;
	cout<<"\nt1(after --t1;)= ";t1.display();
	t1--;
	cout<<"\nt1(after t1--;)= ";t1.display();
	
	cout<<"\n\nt(before t=t2++;)= ";t.display();
	cout<<"\nt2(before t=t2++;)= ";t2.display();
	t=t2++;
	cout<<"\nt(After t=t2++;)= ";t.display();
	cout<<"\nt2(After t=t2++;)= ";t2.display();
	
	cout<<"\n\nt(before t=++t2;)= ";t.display();
	cout<<"\nt2(before t=++t2;)= ";t2.display();
	t=++t2;
	cout<<"\nt(After t=++t2;)= ";t.display();
	cout<<"\nt2(After t=++t2;)= ";t2.display();
	
	cout<<"\n\nt(before t=t2--;)= ";t.display();
	cout<<"\nt2(before t=t2--;)= ";t2.display();
	t=t2--;
	cout<<"\nt(After t=t2--;)= ";t.display();
	cout<<"\nt2(After t=t2--;)= ";t2.display();
	
	cout<<"\n\nt(before t=--t2;)= ";t.display();
	cout<<"\nt2(before t=--t2;)= ";t2.display();
	t=--t2;
	cout<<"\nt(After t=--t2;)= ";t.display();
	cout<<"\nt2(After t=--t2;)= ";t2.display();
	
	cout<<"\n\nt1(before t=t1+t2--;)= ";t1.display();
	cout<<"\nt2(before t=t1+t2--;)= ";t2.display();
	cout<<"\nt(before t=t1+t2--;)= ";t.display();
	t=t1+t2--;
	cout<<"\nt1(after t=t1+t2--;)= ";t1.display();
	cout<<"\nt2(after t=t1+t2--;)= ";t2.display();
	cout<<"\nt(after t=t1+t2--;)= ";t.display();
	
	cout<<"\n\nt1(before t=t1-t2--;)= ";t1.display();
	cout<<"\nt2(before t=t1-t2--;)= ";t2.display();
	cout<<"\nt(before t=t1-t2--;)= ";t.display();
	t=t1-t2--;
	cout<<"\nt1(after t=t1-t2--;)= ";t1.display();
	cout<<"\nt2(after t=t1-t2--;)= ";t2.display();
	cout<<"\nt(after t=t1-t2--;)= ";t.display();
	
	Time tm=t;
	float f=1.5;
	cout<<"\n\ntm(before tm=tm*f;)= ";tm.display();
	tm=tm*f;
	cout<<"\ntm(after tm=tm*f;f=1.5)= ";tm.display();
	
	cout<<endl;
	return 0;
}

Time::Time(int hh,int mm,int ss)  //Parameterised constructor.
{
	h=hh;m=mm;s=ss;
	Tadjust();
}

void Time::Tadjust()
{
	if(s>59||m>59||s<0||m<0)
		sectoTime(Timetosec());  //implicit assigning(implicit passing).
}

void Time::display()  //Display time in hh:mm:ss format.
{
	Tadjust();
	(h>=0 && h<10)?cout<<0<<h:cout<<h;
	cout<<':';
	(m>=0 && m<10)?cout<<0<<m:cout<<m;
	cout<<':';
	(s>=0 && s<10)?cout<<0<<s:cout<<s;
}
		
void Time::sectoTime(int sec)
{
	h=sec/3600;
	m=(sec%3600)/60;
	s=sec%60;
}
	

/*
--NOTE1: Now there are two different declarations for overloading the ++/-- 
operator, the prefix and postfix notations. 
The only difference is the int in the parentheses. This int isn’t really an 
argument, and it doesn’t mean integer. It’s simply a signal to the compiler to 
create the postfix version of the operator. The designers of C++ are fond of 
recycling existing operators andkeywords to play multiple roles, and int is the 
one they chose to indicate postfix. (Well,can you think of a better syntax?)
*/
