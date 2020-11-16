/*
--PROGRAM NAME: rlch9e2.cpp
--PROGRAM STATEMENT: Recall the STRCONV example from Chapter 8. The String class 
in this example has a flaw: It does not protect itself if its objects are 
initialized to have too many characters. (The SZ constant has the value 80.) For 
example, the definition 
	String s = “This string will surely exceed the width of the “
	“screen, which is what the SZ constant represents.”;
will cause the str array in s to overflow, with unpredictable consequences, 
such as crashing the system. 
With String as a base class, derive a class Pstring (for “protected string”) 
that prevents buffer overflow when too long a string constant is used in a 
definition. A new constructor in the derived class should copy only  SZ–1 
characters into str if the string constant is longer, but copy the entire 
constant if it’s shorter. Write a main() program to test different lengths of 
strings.
*/
#include <iostream>
#include <cstring>             //strcpy()
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
		{return str;}  //convert String to C-string
};

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

int main()
{
	
	Pstring s1;  //use no-arg constructor
	char xstr[] = "Joyeux Noel!";  //create and initialize C-string
	
	s1 = xstr;  //use 1-arg constructor to convert C-string to String
	cout<<"s1= ";s1.display();  //display String

	//warning: ISO C++11 does not allow conversion from string literal to 'char *'
	Pstring s2 = "Bonne Annee!";  //uses 1-arg constructor to initialize String
	cout<<"\ns2= "<<(char*)(s2);  //use conversion operator to convert String to C-string
	                      //before sending to << op
	
	//warning: ISO C++11 does not allow conversion from string literal to 'char *'
	Pstring s="This string will surely exceed the width of the screen, which is what the SZ constant represents.";
	cout<<"\ns(supposed to be)= This string will surely exceed the width of the screen, which is what the SZ constant represents.\n";
	cout<<"s(due to protected string class)= ";s.display();
	
	cout<<endl;	              
	return 0;			           
}
