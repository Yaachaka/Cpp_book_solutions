/*
--PROGRAM NAME: rlch9e7.cpp
--PROGRAM STATEMENT: Start with the COUNTEN2 program in this chapter. It can 
increment or decrement a counter, but only using prefix notation. Using 
inheritance, add the ability to use postfix notation for both incrementing and 
decrementing. (See Chapter 8 for a description of postfix notation.)
*/
#include <iostream>
using namespace std;
//00000000000000000000000000000000000000000000000000000000000000//
class Counter
{
	protected: //NOTE: not private
		unsigned int count; //count
	public:
	Counter() : count(0)//constructor, no args
	{  }
	Counter(int c) : count(c) //constructor, one arg
	{  }
	unsigned int get_count() const  //return count
	{ return count; }
	Counter operator ++ () //incr count (prefix)
	{ return Counter(++count); }
	Counter operator ++ (int) //incr count (postfix)
	{ return Counter(count++); }
};
//00000000000000000000000000000000000000000000000000000000000000//
class CountDn : public Counter
{
	public:
	CountDn() : Counter()  //constructor, no args
	{ }
	CountDn(int c) : Counter(c)  //constructor, 1 arg
	{ }
	CountDn operator -- () //decr count (prefix)
	{ return CountDn(--count); }
	CountDn operator -- (int) //decr count (postfix)
	{ return CountDn(count--); }
};
//////////////////////////////START OF MAIN()//////////////////////////////////
int main()
{
	CountDn c1;//class CountDn
	CountDn c2(100);
	
	cout << "\nc1=" << c1.get_count(); //display
	cout << "\nc2=" << c2.get_count(); //display
	
	++c1; ++c1; ++c1;//increment c1
	cout << "\nc1=" << c1.get_count(); //display it
	
	--c2; --c2;//decrement c2
	cout << "\nc2=" << c2.get_count(); //display it
	
	CountDn c3 = --c2;  //create c3 from c2
	cout << "\nc3=" << c3.get_count(); //display c3
	
	c2--;
	cout << "\nc2(after c2--;)=" << c2.get_count(); //display it
	
	cout << "\nc2(before c3=c2--;)=" << c2.get_count(); //display it
	cout << "\nc3(before c3=c2--;)=" << c3.get_count(); //display c3
	c3=c2--;
	cout << "\nc2(after c3=c2--;)=" << c2.get_count(); //display it
	cout << "\nc3(after c3=c2--;)=" << c3.get_count(); //display c3
	
	cout << endl;
	return 0;
}
//////////////////////////////END OF MAIN()//////////////////////////////////
