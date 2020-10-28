/*
--PROGRAM NAME: rlch7e3.cpp
--PROGRAM STATEMENT: Write a program that calculates the average of up to 100 
English distances input by the user. Create an array of objects of the Distance 
class, as in the ENGLARAY example in this chapter. To calculate the average, you 
can borrow the add_dist() member function from the ENGLCON example in Chapter 6. 
You’ll also need a member function that divides a Distance value by an integer. 
Here’s one possibility: 
void Distance::div_dist(Distance d2, int divisor) 
{ 
	float fltfeet = d2.feet + d2.inches/12.0; 
	fltfeet /= divisor; 
	feet = int(fltfeet); 
	inches = (fltfeet-feet) * 12.0; 
}
*/
#include<iostream>
using namespace std;

class Distance
{
	private:
		int feet;
		float inches;
	public:
		void readdist();
		void dispdist()const;
		void avgdist(Distance [],int);
		void divdist(Distance,int);
};

int main()
{
	const int MAX=100;
	Distance d[MAX],davg,dd;
	int count=0;
	char q;
	//Getting distances from user.
	cout<<"Enter distances: \n";
	do
	{
		d[count++].readdist();
		cout<<"Enter another distance(y/n)?: ";
		cin>>q;
	}while((q=='y'||q=='Y')&&count<MAX);
	
	//Finding average of the count number of distances entered and displaying it.
	davg.avgdist(d,count);
	cout<<"The average distance: ";
	davg.dispdist();
	
	//Exercising 'divide a distance by an integer' operation.
	cout<<"\nExercising \'divide a distance by an integer\' operation.\n";
	cout<<"Enter an integer value: ";
	cin>>count;
	dd.divdist(d[0],count);
	cout<<"d[0]/"<<count<<"= ";
	dd.dispdist();
	cout<<endl;
	
	return 0;
}

void Distance::readdist()
{
	cout<<"Enter feets: ";cin>>feet;
	cout<<"\tInches(0.0 to 11.9): ";cin>>inches;
}

void Distance::dispdist()const
{
	cout<<feet<<"\'"<<inches<<"\"";
}

void Distance::avgdist(Distance d[],int n)
{
	feet=0;inches=0.0;
	for(int i=0;i<n;i++)
		inches+=d[i].feet*12+d[i].inches;
	inches/=n;	//averaging
	feet=static_cast<int>(inches/12);		//We can write feet=int(inches/12);
	inches-=feet*12;
}

void Distance::divdist(Distance d,int n)
{
	inches=(d.feet*12+d.inches)/n;
	feet=(int)inches/12;
	inches-=feet*12;
}