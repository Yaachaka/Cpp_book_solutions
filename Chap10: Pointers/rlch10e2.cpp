/*
--PROGRAM NAME: rlch10e2.cpp
--PROGRAM STATEMENT: Start with the String class from the NEWSTR example 
in this chapter. Add a member function called upit() that converts the string to 
all uppercase. You can use the toupper() library function, which takes a single 
character as an argument and returns a character that has been converted (if 
necessary) to uppercase. This function uses the C CTYPE header file. Write some 
code in main() to test upit().
*/
#include <iostream>
#include <cstring>		 //for strcpy(), etc
using namespace std;
////////////////////////////////////////////////////////////////
class String				 //user-defined string type
{
	private:
		char* str;						  //pointer to string
	public:
		String(char* s)					//constructor, one arg
		{
			int length = strlen(s);	 //length of string argument
			str = new char[length+1];  //get memory
			strcpy(str, s);				//copy argument to it
		}
		~String()							//destructor
		{
			cout << "Deleting str\n";
			delete[] str;				  //release memory
		}
		void display()					 //display the String
		{cout << str << endl;}
		
		void upit()  //Formatting string case.
		{
			for(int i=0;i<strlen(str);i++)
				*(str+i)=toupper(*(str+i));
		} 
};
///////////////////////////START OF MAIN()/////////////////////////////////////
int main()
{										  //uses 1-arg constructor
	String s1 = "Who knows nothing doubts nothing.";

	cout << "s1(As initialised)= ";						 //display string
	s1.display();
	
	//Case formatting.
	s1.upit();
	cout << "\ns1(After case formatting)= ";						 //display string
	s1.display();
	
	cout<<endl;
	return 0;
}
///////////////////////////END OF MAIN()/////////////////////////////////////
