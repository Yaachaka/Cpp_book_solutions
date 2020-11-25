/*
--PROGRAM NAME: rlch10e6.cpp
--PROGRAM STATEMENT: Make your own version of the library function 
strcmp(s1,s2), which compares two strings and returns –1 if s1 comes first 
alphabetically, 0 if s1 and s2 are the same, and 1 if s2 comes first alphabetically. 
Call your function compstr(). It should take two char* strings as arguments, 
compare them character by character, and return an int. Write a main() program to 
test the function with different combinations of strings. Use pointer notation 
throughout.
*/
#include<iostream>
#include<iomanip>  //setw(), setfill()
using namespace std;
//---------------------------------------------------------------------------
int cmpstr(const char*,const char*);  //Function declaration.
//-----------------------------START OF MAIN()-------------------------------
int main(void)
{
	cout<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Top line in O/p screen.
	char *s1="Chocolate", *s2="Milkybar", *s3="Milk", *s4="milk";
	
	//Displaying a message.
	cout<<"O/p is -1 if first string comes first alphabetically,\n"
	"\t0 if both strings are entirely same and \n\t1 if second string comes first "
	"alphabetically.\n\tNOTE: Irrespective of text case.";
	
	//Displaying all strings.
	cout<<"\n  s1: "<<s1;
	cout<<"\n  s2: "<<s2;
	cout<<"\n  s3: "<<s3;
	cout<<"\n  s4: "<<s4;
	
	//Comparing strings and displaying comparision status.
	cout<<"\n\ncmpstr(s1,s2): "<<cmpstr(s1,s2);  //Display -1
	cout<<"\ncmpstr(s2,s1): "<<cmpstr(s2,s1);  //Display 1
	cout<<"\ncmpstr(s3,s4): "<<cmpstr(s3,s4);  //Display 0
	cout<<"\ncmpstr(s4,s2): "<<cmpstr(s4,s2);  //Display 1
	cout<<"\ncmpstr(s3,s3): "<<cmpstr(s3,s3);  //Display 0
	
	cout<<endl<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Bottom line in O/p screen
	return 0;
}
//-----------------------------END OF MAIN()---------------------------------
int cmpstr(const char* s1,const char* s2)  //function definition.
{
	int len=(len<=strlen(s2))?len:strlen(s2);  //Store the length least out of two strings'
	
	for(int i=0;i<len;i++)  //Compare strings to the least length out of 2 strings.
	{
		if(tolower(*(s1+i))<tolower(*(s2+i)))
			return -1;
		else if(tolower(*(s1+i))>tolower(*(s2+i)))
			return 1;
	}  //End of for. Both strings are similar up to the least length.
	if(strlen(s1)<strlen(s2))  //Both strings are equal upto the least length but differ in length.
		return -1;
	else if(strlen(s1)>strlen(s2))  //Both strings are equal upto the least length but differ in length.
		return 1;
	else  //Both strings are equal upto the least length and are of same length.
		return 0;
}  //End of cmpstr(const char*, const char*)
//---------------------------------------------------------------------------
