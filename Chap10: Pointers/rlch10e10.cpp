/*
--PROGRAM NAME: rlch10e10.cpp
--PROGRAM STATEMENT: As presented, Exercise 9 is rather inelegant 
because each of the 10 int arrays is declared in a different program statement, 
using a different name. Each of their addresses must also be obtained using a 
separate statement. You can simplify things by using new, which allows you to 
allocate the arrays in a loop and assign pointers to them at the same time: 
	for(j=0; j<NUMARRAYS; j++)         // allocate NUMARRAYS arrays 
		*(ap+j) = new int[MAXSIZE];     // each MAXSIZE ints long 
Rewrite the program in Exercise 9 to use this approach. You can access the 
elements of the individual arrays using the same expression mentioned in Exercise 
9, or you can use pointer notation: *(*(ap+j)+k). The two notations are 
equivalent.
*/
#include<iostream>
#include<iomanip>  //setw(), setfill()
using namespace std;
//--------------------------START OF MAIN()----------------------------------
int main(void)
{
	cout<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Top line of O/p screen.
	
	const int MAX=10;
	int* ap[MAX];  //Array of 10 pointers to the above integer arrays.
	
	for(int j=0; j<MAX; j++)         // allocate MAX arrays 
		//*(ap+j)=new int[MAX];     // each MAX ints long
		ap[j]=new int[MAX];
	
	int a=0;
	//filling the arrays
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++,a+=10)
			ap[i][j]=a;
			//*(ap[i]+j)=a; //valid. i is not distributed sequentially in memory.
			//*(*(ap+i)+j)=a;  //valid
			//**(ap+i+j)=a; //wrong
			
	}
	
	//Displaying the arrays
	for(int i=0;i<MAX;i++)
	{
		cout<<"ap["<<i<<"]: ";
		for(int j=0;j<MAX;j++)
			cout<<setw(4)<<ap[i][j];
			//cout<<setw(4)<<*(ap[i]+j); //valid. i is not distributed sequentially in memory.
			//cout<<setw(4)<<*(*(ap+i)+j);  //valid
			//cout<<setw(4)<<**(ap+i+j); //wrong
			
		cout<<endl;
	}
	
	for(int j=0; j<MAX; j++)  //releasing memory.
		delete ap[j];
	
	cout<<endl<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Bottom line of O/p screen.
	return 0;
}
//--------------------------END OF MAIN()-----------------------------------