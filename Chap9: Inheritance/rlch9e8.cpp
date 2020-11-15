/*
--PROGRAM NAME: rlch9e8.cpp
--PROGR STATEMENT: Operators in some computer languages, such as Visual 
Basic, allow you to select parts of an existing string and assign them to other 
strings. (The Standard C++ string class offers a different approach.) Using 
inheritance, add this capability to the Pstring class of Exercise 2. In the 
derived class, Pstring2, incorporate three new functions: left(), mid(), and 
right(). 
	s2.left(s1, n)    // s2 is assigned the leftmost n characters 
	                  //    from s1 
	s2.mid(s1, s, n)  // s2 is assigned the middle n characters 
	                  //    from s1, starting at character number s 
	                  //    (leftmost character is 0) 
	s2.right(s1, n)   // s2 is assigned the rightmost n characters 
	                  //    from s1 
You can use for loops to copy the appropriate parts of s1, character by 
character, to a temporary Pstring2 object, which is then returned. For extra 
credit, have these functions return by reference, so they can be used on the 
left side of the equal sign to change parts of an existing string.
*/
//NOTE 1: Return by reference to use on the left side of the equal sign task not completed.
#include <iostream>
#include <cstring>  //strcpy(),strlen()
using namespace std;

class String  //user-defined string type
{
	protected:  
		static const int SZ=80;  //size of all String objects
		char str[SZ];  //holds a C-string
	public:
		String()  //no-arg constructor
		{str[0]='\0';}
		String(char s[])  //1-arg constructor
		{strcpy(str,s);}  //   convert C-string to String
		void display()const  //display the String
		{cout<<str;}
		operator char*()  //conversion operator
		{ return str;}  //convert String to C-string
};
//000000000000000000000000000000000000000000000000000000000000000000000000//
class Pstring:public String
{
	public:
		Pstring(){String();}  //No argument constructor.
		Pstring(char s[])  //One argument constructor.
		{
			if(strlen(s)<SZ)
				//String(char*(s));  //Did not work: Did not assign to str
				strcpy(str,s);
			else
			{
				for(int i=0;i<SZ-2;i++)
					str[i]=s[i];
				str[SZ-1]='\0';
				
			}
		}
};
//000000000000000000000000000000000000000000000000000000000000000000000000//
class Pstring2:public Pstring
{
	public:
		Pstring2(){String();}  //No argument constructor.
		Pstring2(char s[]):Pstring(s){}  //One-argument constructor.
		
		void left(Pstring2 ps2,int n);
		void mid(Pstring2 ps2,int s,int n);
		void right(Pstring2 ps2,int n);
		
};
/////////////////////////////START OF MAIN()/////////////////////////////////
int main()
{
	
	Pstring2 s1;  //use no-arg constructor
	char xstr[] = "Joyeux Noel!";  //create and initialize C-string
	
	s1 = xstr;  //use 1-arg constructor to convert C-string to String
	cout<<"s1= ";s1.display();  //display String
/*
	//warning: ISO C++11 does not allow conversion from string literal to 'char *'
	Pstring2 s2 = "Bonne Annee!";  //uses 1-arg constructor to initialize String
	cout<<"\ns2= "<<(char*)(s2);  //use conversion operator to convert String to C-string
	                      //before sending to << op
	
	//warning: ISO C++11 does not allow conversion from string literal to 'char *'
	Pstring2 s="This string will surely exceed the width of the screen, which is what the SZ constant represents.";
	cout<<"\ns(supposed to be)= This string will surely exceed the width of the screen, which is what the SZ constant represents.\n";
	cout<<"s(due to protected string class)= ";s.display();
*/
	Pstring2 s3,s4;
	cout<<endl;
	s3.left(s1,8);
	s3.display();
	
	cout<<endl;
	s3.mid(s1,4,4);
	s3.display();
	
	cout<<endl;
	s3.right(s1,7);
	s3.display();
	
	cout<<endl;	              
	return 0;			           
}
/////////////////////////////END OF MAIN()/////////////////////////////////

void Pstring2::left(Pstring2 ps2,int n)
{
	str[n]='\0';
	for(int i=0;i<strlen(ps2.str)&&i<n;i++)
		{str[i]=ps2.str[i];str[i+1]='\0';}
}
//000000000000000000000000000000000000000000000000000000000000000000000000//
void Pstring2::mid(Pstring2 ps2,int s,int n)
{
	str[n]='\0';
	for(int i=s;i<strlen(ps2.str)&&i<n+s;i++)
		{str[i%s]=ps2.str[i];str[(i%s)+1]='\0';}
}
//000000000000000000000000000000000000000000000000000000000000000000000000//
void Pstring2::right(Pstring2 ps2,int n)
{
	if(strlen(ps2.str)<=n)
		strcpy(str,ps2.str);
	else
	{
		str[n--]='\0';
		for(int i=strlen(ps2.str)-1;i>=0&&n>=0;i--)
			str[n--]=ps2.str[i];
	}
}