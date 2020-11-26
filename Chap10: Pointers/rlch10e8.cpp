/*
--PROGRAM NAME: rlch10e8.cpp
--PROGRAM STATEMENT: Revise the additem() member function from the LINKLIST 
program so that it adds the item at the end of the list, rather than the beginning. 
This will cause the first item inserted to be the first item displayed, so the 
output of the program will be 
25
36
49
64
To add the item, you’ll need to follow the chain of pointers to the end of the 
list, then change the last link to point to the new link.
*/
#include<iostream>
#include<iomanip>  //setw(), setfill()
using namespace std;
//------------------------------------------------------------------
struct link									//one element of list
{
	int data;								  //data item
	link* next;								//pointer to next link
};
//------------------------------------------------------------------
class linklist								//a list of links
{
	private:
		link* first;						  //pointer to first link
		link* ff;  //To hold the address of the very first element's address.
	public:
		linklist()							 //no-argument constructor
		{ first = NULL; }				//no first link
		~linklist();
		void additem(int d);				//add data item (one link)
		void display();					  //display all links
};
//---------------------------START OF MAIN()------------------------------
int main()
{
	cout<<setw(75)<<setfill('+')<<""<<endl;  //Top line of O/p screen.
	
	linklist li;		 //make linked list

	li.additem(25);	 //add four items to list
	li.additem(36);
	li.additem(49);
	li.additem(64);

	li.display();		//display entire list
	
	cout<<endl<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Bottom line of O/p screen.
	return 0;
}
//------------------------END OF MAIN()----------------------------------
void linklist::additem(int d)			//add data item
{
	link* newlink = new link;			 //make a new link
	if(first==NULL)
		ff=newlink;  //To store the first element's address.
	else
		first->next=newlink;  //It should come under else. Because first-next is 
		                         //not a valid segment when first==NULL.
	newlink->data = d;					  //give it data
	newlink->next = NULL;  //it points to next link
	first = newlink;  //now first points to this
}
//------------------------------------------------------------------
void linklist::display()  //display all links
{
	link* current = ff;  //set ptr to first link
	while( current->next != NULL )  //quit on last link
	{
		cout << current->data << endl;  //print data
		current = current->next;  //move to next link
	}
	cout << current->data << endl;  //print last element
	
}
//------------------------------------------------------------------
linklist::~linklist()
{
	first=ff;
	link* current = first;				 //set ptr to first link
	while( first->next != NULL )			  //quit on last link
	{
		cout<<"Link Destroyed.\n";  
		first = current->next;  //Save link to next data, before deleting the current.
		       //Becuase current one holds link to next. If we do not store the link to
		       //to the next data, we will lose the link forever (and memory) on 
		       //deleting current link.
		delete current;  //Delete the current data/link.
		current=first;  //Get ready the next link for deletion.
	}
	cout<<"Link Destroyed.\n";
	delete first; //Delete the last element and link.
}
//------------------------------------------------------------------
