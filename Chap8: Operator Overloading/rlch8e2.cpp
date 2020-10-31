/*
--PROGRAM NAME: rlch8e2.cpp
--PROGRAM STATEMENT: Write a program that substitutes an overloaded  += operator 
for the overloaded + operator in the STRPLUS program in this chapter. This 
operator should allow statements like 
	s1 += s2; 
where s2 is added (concatenated) to s1 and the result is left in  s1. The operator 
should also permit the results of the operation to be used in other calculations, 
as in 
	s3 = s1 += s2;
*/
#include<iostream>
#include<cstring>  //strlen(), strcpy(), strcat()
#include<stdlib.h>  //exit()
using namespace std;

class String
{
	private:
		static const int SIZE=80;  //Size of string
		char str[SIZE];  //Holds a string.
	public:
		String(){strcpy(str,"");}  //Constructo (no args)
		String(char s[]){strcpy(str,s);}  //Constructor (One arg)
		void display()const{cout<<str;}
		String operator +(String ss)const;
		String operator +=(String ss);
};

int main()
{
	String s1="Merry Christmas!";  //Uses constructor 2. Note1: At the end of the program.
	String s2="Happy new year!";  //Uses Constructor 2
	String s3;  //Uses constructor 1;
	
	//Display all strings.
	cout<<"s1= ";s1.display();
	cout<<"\ns2= ";s2.display();
	cout<<"\ns3= ";s3.display();
	
	s3=s1+s2;  //Add s1 and s2 and store in s3.
	cout<<"\ns3(=s1+s2)= ";s3.display();cout<<endl;
	
	s1="Hello";
	s2="World";
	//Display all strings.
	cout<<"s1= ";s1.display();
	cout<<"\ns2= ";s2.display();
	cout<<"\ns3= ";s3.display();
	s3=s1+s2;
	cout<<"\ns3(=s1+s2)= ";s3.display();
	s1+=s2;
	cout<<"\ns1(after s1+=s2)= ";s1.display();
	cout<<"\ns2(after s1+=s2)= ";s2.display();
	s3=s1+=s2;  //first, s1=s1+s2 then s3=s1.
	cout<<"\ns3(after s3=s1+=s2)= ";s3.display();
	cout<<endl;
	
	return 0;
}

String String::operator + (String ss)const
{
	String temp;
	if(strlen(str)+strlen(ss.str)<SIZE)
	{
		strcpy(temp.str,str);  //Copy this string to temp.
		strcat(temp.str, ss.str);  //Add the argument string.
	}
	else
	{
		cout<<"\nString overflow.\n";
		exit(1);
	}
	
	return temp;
}

String String::operator+=(String ss)
{
	if(strlen(str)+strlen(ss.str)<SIZE)
	{
		strcat(str, ss.str);  //Add the argument string.
	}
	else
	{
		cout<<"\nString overflow.\n";
		exit(1);  //Exits from the program throwing error 1.
	}
	
	return String(str);
}

/*
--Note:Following mentioned statements in the program throw this warning: ISO C++11 
does not allow conversion from string literal to 'char *'
	String s1="Merry Christmas!";
	String s2="Happy new year!";
	String s1="Hello";
	String s2="World";
*/