/*
--PROGRAM NAME: rlch5e6.cpp
--PROGRAM STATEMENT: Start with the program from Exercise 11 in Chapter 4, 
“Structures”, which adds two struct time values. Keep the same functionality, 
but modify the program so that it uses two functions. The first, time_to_secs(), 
takes as its only argument a structure of type time, and returns the equivalent 
in seconds (type  long). The second function, secs_to_time(), takes as its only 
argument a time in seconds (type long), and returns a structure of type time.
*/
#include<iostream>
using namespace std;

struct Time		//Do not use 'time'. std function time().
{
	int h,m,s;
};

long time_to_secs(Time t);
Time secs_to_time(long s);
	
int main()
{
	Time gt,ot;
	long s;
	gt.h=12;
	gt.m=36;
	gt.s=57;
	
	//Time to seconds.
	cout<<"Converting this time to total seconds= "<<gt.h<<':'<<gt.m<<':'<<gt.s;
	s=time_to_secs(gt);
	cout<<"\nTotal seconds: "<<s;
	
	//Seconds to Time.
	cout<<"\nConverting from total seconds to H:M:S format: ";
	ot=secs_to_time(s);
	cout<<"\nTime(H:M:S)= "<<ot.h<<':'<<ot.m<<':'<<ot.s<<endl;
	
	return 0;
}

long time_to_secs(Time t)
{
	long s=t.h*3600+t.m*60+t.s;
	return s;
}

Time secs_to_time(long sec)
{
	Time t;
	t.h=sec/3600;
	t.m=sec%3600/60;
	t.s=sec%60;
	return t;
}