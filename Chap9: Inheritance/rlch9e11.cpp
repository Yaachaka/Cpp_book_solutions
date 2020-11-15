/*
--PROGRAM NAME: rlch9e11.cpp
--PROGRAM STATEMENT: Various situations require that Pairs of numbers 
be treated as a unit. For example, each screen coordinate has an x (horizontal) 
component and a y (vertical) component. Represent such a Pair of numbers as a 
structure called Pair that comprises two int member variables. 
Now, assume you want to be able to store  Pair variables on a stack. That is, 
you want to be able to place a Pair (which contains two integers) onto a stack 
using a single call to a push() function with a structure of type Pair as an 
argument, and retrieve a Pair using a single call to a pop() function, which 
will return a structure of type Pair. Start with the Stack2 class in the 
STAKEN program in this chapter, and from it derive a new class called PairStack. 
This new class need contain only two members: the overloaded push() and pop() 
functions. The PairStack::push() function will need to make two calls to 
Stack2::push() to store the two integers in its Pair, and the PairStack::pop() 
function will need to make two calls to Stack2::pop() (although not necessarily 
in the same order).
*/
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
struct Pair  //Do not use pair: results in ambiguous condition. Else use struct key on each instance creation.
{
	int xco,yco;
};
////////////////////////////////////////////////////////////////
class Stack
{
	protected:						 //NOTE: can't be private
		enum { MAX = 9 };			//size of stack array
		int st[MAX];				  //stack: array of integers
		int top;						//index to top of stack
	public:
		Stack()						 //constructor
		{ top = -1; }
		void push(int var)		  //put number on stack
		{ st[++top] = var; }
		int pop()					  //take number off stack
		{ return st[top--]; }
};
////////////////////////////////////////////////////////////////
class Stack2 : public Stack
{
	public:
		void push(int var)		  //put number on stack
		{
			if(top >= MAX-1)		  //error if stack full
			{ cout << "\nError: stack is full"; exit(1); }
			Stack::push(var);		//call push() in Stack class
		}
		int pop()					  //take number off stack
		{
			if(top < 0)				//error if stack empty
			{ cout << "\nError: stack is empty\n"; exit(1); }
			return Stack::pop();	//call pop() in Stack class
		}
};
////////////////////////////////////////////////////////////////
class PairStack : public Stack2
{
	public:
		void push(Pair p)		  //put number on stack
		{
			if(top >= MAX-2)		  //error if stack full
			{cout << "\nError: only 1 int space available on stack.";exit(1);}
			Stack2::push(p.xco);		//call push() in Stack2 class
			Stack2::push(p.yco);		//call push() in Stack2 class
			
		}
		Pair pop()					  //take number off stack
		{
			if(top < 1)				//error if stack empty
			{cout<<"\nError: Only 1 int space is available on stack.\n";exit(1);}
			int y=Stack2::pop(),x=Stack2::pop();
			return Pair{x,y};	//call pop() in Stack2 class
		}
};
//////////////////////////////START OF MAIN()//////////////////////////////////
int main()
{
	Pair p1{23,45},p2{34,87},p3{56,233},p;
	PairStack ps1;
	//pushing Pair
	cout<<"‡Pushing Pair p1{23,45} on to the stack.";
	ps1.push(p1);
	//popping Pair
	cout<<"\n†Popping a Pair from the stack and assigning to p.";
	p=ps1.pop();
	cout<<"\n\tp is {"<<p.xco<<","<<p.yco<<"}";
	//pushing Pair
	cout<<"\n‡Pushing Pair p2{34,87} on to the stack.";
	ps1.push(p2);
	//pushing Pair
	cout<<"\n‡Pushing Pair p2{34,87} on to the stack.";
	ps1.push(p2);
	//popping Pair
	cout<<"\n†Popping a Pair from the stack and assigning to p.";
	p=ps1.pop();
	cout<<"\n\tp is {"<<p.xco<<","<<p.yco<<"}";
	//pushing Pair
	cout<<"\n‡Pushing Pair p3{56,233} on to the stack.";
	ps1.push(p3);
	//popping Pair
	cout<<"\n†Popping a Pair from the stack and assigning to p.";
	p=ps1.pop();
	cout<<"\n\tp is {"<<p.xco<<","<<p.yco<<"}";
	//popping Pair
	cout<<"\n†Popping a Pair from the stack and assigning to p.";
	p=ps1.pop();
	cout<<"\n\tp is {"<<p.xco<<","<<p.yco<<"}";
	//popping Pair
	cout<<"\n†Popping a Pair from the stack and assigning to p.";
	p=ps1.pop();
	cout<<"\n\tp is {"<<p.xco<<","<<p.yco<<"}";
	//popping Pair
	cout<<"\n†Popping a Pair from the stack and assigning to p.";
	p=ps1.pop();
	cout<<"\n\tp is {"<<p.xco<<","<<p.yco<<"}";
	
	cout << endl;
	return 0;
}
//////////////////////////////END OF MAIN()//////////////////////////////////
