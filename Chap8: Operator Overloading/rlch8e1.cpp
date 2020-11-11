/*
--PROGRAM NAME: rlch8e1.cpp
--PROGRAM STATEMENT: To the Distance class in the ENGLPLUS program in this 
chapter, add an overloaded - operator that subtracts two distances. It should 
allow statements like  dist3= dist1-dist2;. Assume that the operator will never 
be used to subtract a larger number from a smaller one (that is, negative 
distances are not allowed).
*/
#include<iostream>
#include<cmath>
using namespace std;

class Distance
{
	private:
		int feet;
		float inches;
	public:
		Distance():feet(0),inches(0){}  //Constructor (no args)
		Distance(int ft, float in):feet(ft),inches(in){}  //Constructor (2 args)
		void getdist();  //Get distance from user.
		void showdist()const;  //Show distance.
		Distance operator + (Distance)const;
		Distance operator - (Distance)const;
};

int main()
{
	Distance dist1, dist3, dist4;  //Define distances.
	dist1.getdist();  //Get distance from user.
	Distance dist2(11,6.25);  //Define, initialize dist2.
	
	//Usage of overloaded operator +
	cout<<"Exercising overloading of operator +\n";
	dist3=dist1+dist2;  //Single '+' operator.
	dist4=dist1+dist2+dist3;  //Multiple '+' operator.
	//Displaying all distances.
	cout<<"dist1(user entered)= ";
	dist1.showdist();
	cout<<endl;
	cout<<"dist2(initialized)= ";
	dist2.showdist();
	cout<<endl;
	cout<<"dist3(=dist1+dist2)= ";
	dist3.showdist();
	cout<<endl;
	cout<<"dist4(=dist1+dist2+dist3)= ";
	dist4.showdist();
	cout<<endl;
	
	//Usage of overloaded operator -
	cout<<"\nExercising overloading of operator -\n";
	dist3=dist1-dist2;  //Single '+' operator.
	dist4=dist1-dist2-dist3;  //Multiple '+' operator.
	//Displaying all distances.
	cout<<"dist1(user entered)= ";
	dist1.showdist();
	cout<<endl;
	cout<<"dist2(initialized)= ";
	dist2.showdist();
	cout<<endl;
	cout<<"dist3(=difference of dist1 and dist2)= ";
	dist3.showdist();
	cout<<endl;
	cout<<"dist4(=difference of dist1 and (dist2+dist3))= ";
	dist4.showdist();
	cout<<endl;
	
	
	return 0;
}

void Distance::getdist()
{
	cout<<"\nEnter feet: ";
	cin>>feet;
	cout<<"\tEnter inches: ";
	cin>>inches;
}

void Distance::showdist()const
{
	cout<<feet<<"\' "<<inches<<'\"';
}

Distance Distance::operator +(Distance d2)const
{
	float in=inches+d2.inches+(feet+d2.feet)*12;  //Resulting distance in inches only.
	int ft=(int)in/12;  //feet
	in-=ft*12;  //inches
	return Distance(ft,in);  //unnamed object of type Distance is created, initialized and returned.
}

Distance Distance::operator -(Distance d2)const
{
	//Finding difference of two distances. Following no negative distance assumption.
	float in=fabs((inches+feet*12)-(d2.inches+d2.feet*12));  //Resulting distance in inches only.
	int ft=(int)in/12;  //feet
	in-=ft*12;  //inches
	return Distance(ft,in);  //unnamed object of type Distance is created, initialized and returned.
}
