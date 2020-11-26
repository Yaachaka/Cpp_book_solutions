/*
--PROGRAM NAME: rlch10e9.cpp
--PROGRAM STATEMENT: Let’s say that you need to store 100 integers so that 
they’re easily accessible. However, let’s further assume that there’s a problem: 
The memory in your computer is so frag-mented that the largest array that you can 
use holds only 10 integers. (Such problems actually arise, although usually with 
larger memory objects). You can solve this problem by defining 10 separate 
intarrays of 10 integers each, and an array of 10 pointers to these arrays. The 
intarrays can have names like a0, a1, a2, and so on. The address of each of these 
arrays can be stored in the pointer array of type int*, which can have a name like 
ap(for array of pointers). You can then access individual integers using 
expressions like ap[j][k], where j steps through the pointers in ap and k steps 
through individual integers in each array. This looks as if you’re accessing a 
two-dimensional array, but it’s really a group of one-dimensional arrays. 
Fill such a group of arrays with test data (say the numbers 0, 10, 20, and so on 
up to 990). Then display the data to make sure it’s correct.
*/
#include<iostream>
#include<iomanip>  //setw(), setfill()
using namespace std;
//--------------------------START OF MAIN()----------------------------------
int main(void)
{
	cout<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Top line of O/p screen.
	
	const int MAX=10;
	int a0[MAX],a1[MAX],a2[MAX],a3[MAX],a4[MAX],a5[MAX],a6[MAX],a7[MAX],a8[MAX],a9[MAX];
	int* ap[MAX];  //Array of 10 pointers to the above integer arrays.
	
	ap[0]=a0;ap[1]=a1;ap[2]=a2;ap[3]=a3;ap[4]=a4;
	ap[5]=a5;ap[6]=a6;ap[7]=a7;ap[8]=a8;ap[9]=a9;
	
	int a=0;
	//filling the arrays
	for(int i=0;i<MAX;i++,a+=10)a0[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a1[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a2[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a3[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a4[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a5[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a6[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a7[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a8[i]=a;
	for(int i=0;i<MAX;i++,a+=10)a9[i]=a;
	
	//Displaying the arrays
	for(int i=0;i<MAX;i++)
	{
		cout<<"a"<<i<<": ";
		for(int j=0;j<MAX;j++)
			cout<<setw(4)<<ap[i][j];
			//cout<<setw(4)<<*(ap[i]+j); //valid. i is not distributed sequentially in memory.
			//cout<<setw(4)<<**(ap+i+j); //wrong
			
		cout<<endl;
	}
	
	cout<<endl<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Bottom line of O/p screen.
	return 0;
}
//--------------------------END OF MAIN()-----------------------------------