/*
--PROGRAM NAME: rlch10e7.cpp
--PROGRAM STATEMENT: Modify the person class in the PERSORT program in 
this chapter so that it includes not only a name, but also a salary item of type 
float representing the person’s salary. You’ll need to change the setData() and 
printData() member functions to setData() and printData(), and include in them 
the ability to set and display the salary as well as the name. You’ll also need a 
getSalary() function. Using pointer notation, write a salsort() function that 
sorts the pointers in the persPtrarray by salary rather than by name. Try doing 
all the sorting in salsort(), rather than calling another function as PERSORT 
does. If you do this, don’t forget that -> takes precedence over *, so you’ll 
need to say
	if((*(pp+j))->getSalary() > (*(pp+k))->getSalary() )
	{ // swap the pointers  }
*/
#include<iostream>
#include<string>  //for string class
#include<iomanip>  //setw(),setfill()
using namespace std;
//--------------------------------------------------------------------
class person  //class of persons
{
	protected:
		string name;  //person's name
		float salary;  //person's salary
	public:
		void setData()				  //set the name
		{
			cout<<"  Enter name: ";cin>>name;
			cout<<"  Enter salary: ";cin>>salary;
			
		}
		void printData()				//display the name
		{cout<<setw(15)<<left<<name<<"   "<<salary;}
		string getName()				//return the name
		{return name;}
		float getSalary()				//return the salary
		{return salary;}
		
};
//-------------------------START OF MAIN()----------------------------
int main(void)
{
	cout<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Top line of O/p screen.
	
	void namesort(person**, int);	  //prototype
	void salsort(person**, int);	  //prototype
	person* persPtr[10];			 //array of pointers to persons
	int n=0;							//number of persons in array
	char choice;						 //input char
	
	//Get user input 	for person name and person salary.	 
	do
	{  //put persons in array
		persPtr[n] = new person;  //make new object
		persPtr[n]->setData();  //set person's name and salary.
		n++;  //count new person
		cout << "Enter another (y/n)? ";  //enter another person?
		cin >> choice;
	}while(choice=='y' && n<10);  //quit on 'n'

	//Display All person name and salary, unsorted.
	cout << "\nUnsorted list:";
	for(int j=0; j<n; j++)
		{cout<<"\n  ";persPtr[j]->printData();}	  

	//Sort data by name.
	namesort(persPtr,n);

	//Display All person name and salary, sorted by name.
	cout<<"\nSorted list(by name):";
	for(int j=0; j<n; j++)  //print sorted list
		{cout<<"\n  ";persPtr[j]->printData();}
	
	//Sort data by salary.
	salsort(persPtr,n);

//Display All person name and salary, sorted by salary.
	cout<<"\nSorted list(by salary):";
	for(int j=0; j<n; j++)  //print sorted list
		{cout<<"\n  ";persPtr[j]->printData();}
	
	for(int j=0; j<n; j++)  //Returning memory to the system.
		{delete persPtr[j];}
	
	cout<<endl<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Bottom of O/p screen.
	return 0;
}
//-------------------------END OF MAIN()------------------------------
void namesort(person** pp, int n)  //sort pointers to persons
{										
	void order(person**, person**);  //prototype
	int j, k;  //indexes to array

	for(j=0; j<n-1; j++)  //outer loop
		for(k=j+1; k<n; k++)  //inner loop starts at outer
			order(pp+j, pp+k);  //order the pointer contents
}
//--------------------------------------------------------------------
void order(person** pp1, person** pp2)  //orders two pointers
{	
	if( (*pp1)->getName() > (*pp2)->getName() )  //if 1st larger than 2nd
	{
		person* tempptr = *pp1;  //swap the pointers
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
//--------------------------------------------------------------------
void salsort(person** pp, int n)  //sort pointers to persons
{										
	void salorder(person**, person**);  //prototype
	int j, k;  //indexes to array

	for(j=0; j<n-1; j++)  //outer loop
		for(k=j+1; k<n; k++)  //inner loop starts at outer
			salorder(pp+j, pp+k);  //order the pointer contents
}
//--------------------------------------------------------------------
void salorder(person** pp1, person** pp2)  //orders two pointers
{	
	if( (*pp1)->getSalary() < (*pp2)->getSalary() )  //if 1st smaller than 2nd
	{
		person* tempptr = *pp1;  //swap the pointers
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}
//--------------------------------------------------------------------
