/*
--PROGRAM NAME: rlch7e9.cpp
--PROGRAM STATEMENT: A queue is a data storage device much like a stack. The 
difference is that in a stack the last data item stored is the first one retrieved, 
while in a queue the first data item stored is the first one retrieved. That is, 
a stack uses a last-in-first-out (LIFO) approach, while a queue uses 
first-in-first-out (FIFO). A queue is like a line of customers in a bank: The 
first one to join the queue is the first one served. 
Rewrite the STAKARAY program from this chapter to incorporate a class called queue 
instead of a class called stack. Besides a constructor, it should have two 
functions: one called put() to put a data item on the queue, and one called get() 
to get data from the queue. These are equivalent to push() and pop() in the stack 
class. 
Both a queue and a stack use an array to hold the data. However, instead of a 
single int variable called top,as the stack has, you’ll need two variables for a 
queue: one called head to point to the head of the queue, and one called tail to 
point to the tail. Items are placed on the queue at the tail (like the last 
customer getting in line at the bank) and removed from the queue at the head. The 
tail will follow the head along the array as items are added and removed from the 
queue. This results in an added complexity: When either the tail or the head gets 
to the end of the array, it must wrap around to the beginning. Thus you’ll need a 
statement like 
	if(tail == MAX-1) 
		tail = -1; 
to wrap the tail, and a similar one for the head. The array used in the queue is 
sometimes called a circular buffer, because the head and tail circle around it, 
with the data between them.
*/
#include<iostream>
using namespace std;

class queue
{
	private:
		enum {MAX=10};
		int arr[MAX]={0}, head, tail, count;
	public:
		queue()
			{head=tail=count=0;}
		~queue(){}
		void put(int);
		int get(void);
};

int main()
{
	queue q;
	char c='y';
	int value, choice;
	
	while(c=='y'||c=='Y')
	{
		cout<<"Enter 1 to put a value into the queue \n\t2 to get a value out of the queue: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter a value(keep it above 0): ";
				cin>>value;
				q.put(value);
				break;
			case 2:
				value=q.get();
				if(value==-1)
					cout<<"Queue is empty."<<endl;
				else
					cout<<"The value that got out is "<<value<<"."<<endl;
				break;
			default:
				cout<<"You are funny."<<endl;
		}
		cout<<"Go again(y/n)?: ";
		cin>>c;
	}
	
	return 0;
}

void queue::put(int value)
{
	if(count==MAX)
		cout<<"Queue is already full. Can't add value to the queue."<<endl;
	else
	{
		count++;
		arr[(tail++)%MAX]=value;
	}
}

int queue::get(void)
{
	if(count==0)
		return -1;
	count--;
	return arr[(head++)%MAX];
}