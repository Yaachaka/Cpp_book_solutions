/*
--PROGRAM NAME: rlch8e10.cpp
--PROGRAM STATEMENT: For math buffs only: Create a class Polar that represents 
the points on the plain as polar coordinates (radius and angle). Create an 
overloaded +operator for addition of two Polar quantities. “Adding” two points on 
the plain can be accomplished by adding their X coordinates and then adding their 
Y coordinates. This gives the X and Y coordinates of the “answer”. Thus you’ll 
need to convert two sets of polar coordinates to rectangular coordinates, add them, 
then convert the resulting rectangular representation back to polar.
*/
#include<iostream>
#include<cmath>  //sin(),cos(),atan()
#define PI 3.1415
using namespace std;

class Polar
{
	private:
		float radius,angled,angler,xco,yco;
		  //angled-angle in degrees, angler-angle in radians, xco and yco - x and y coordinates.
	public:
		Polar(){}  //Default constructor.
		~Polar(){}  //Destructor.
		Polar(float r,float a):radius(r),angled(a)
		{deg_to_rad();polar_to_rect();}
		
		void deg_to_rad()  //Degrees to radians conversion.
		{angler=angled*PI/180;}
		void rad_to_deg()  //Radians to degrees conversion.
		{angled=angler*180/PI;}
		
		void polar_to_rect();  //coordinates conversion from polar to rectangular.
		void rect_to_polar();  //coordinates conversion from rectangular to polar.
		
		void getpolar();  //To get user i/p for coordinates in polar(degrees) form.
		void disppolar()const;  //To display coordinates in polar(degrees) form.
		Polar operator+(Polar);  //To add two polar coordinates.
};

int main(void)
{
	Polar p1,p2,ps;
	
	//Taking user i/p for polar coordinates.
	cout<<"Enter polar coordinate p1: \n";
	p1.getpolar();
	cout<<"Enter polar coordinate p2: \n";
	p2.getpolar();
	
	//Displaying polar coordinates.
	cout<<"p1= ";p1.disppolar();
	cout<<"\np2= ";p2.disppolar();
	
	//Summing 2 coordinates and displaying.
	ps=p1+p2;
	cout<<"\nps(=p1+p2)= ";ps.disppolar();
	
	cout<<endl;
	return 0;
}

void Polar::polar_to_rect()
{
	xco=radius*cos(angler);  //trigonometric functions defined in cmath library take the angle parameter in radians.
	yco=radius*sin(angler);
}

void Polar::rect_to_polar()
{
	radius=sqrt(xco*xco+yco*yco);
	angler=atan(yco/xco);  //Trigonometric functions in cmath lib return angle in radians.
	rad_to_deg();
}

void Polar::getpolar()
{
	//taking user inputs.
	cout<<"Enter radius: ";
	cin>>radius;
	cout<<"Enter angle in degrees: ";
	cin>>angled;
	deg_to_rad();  //convert angle in degrees to angle in radians.
	polar_to_rect();  //convert polar coordinates to rectangular form.
}

void Polar::disppolar()const
{
	cout<<radius<<"\u2220"<<angled<<"°";  // \u2220: unicode to display angle(∠) symbol.
}

Polar Polar::operator+(Polar p2)
{
	Polar p;
	p.xco=xco+p2.xco;
	p.yco=yco+p2.yco;
	p.rect_to_polar();
	p.rad_to_deg();
	return p;
}