/*
--PROGRAM NAME: rlch7e10.cpp
--PROGRAM STATEMENT: A matrix is a two-dimensional array. Create a class matrix 
that provides the same safety feature as the array class in Exercise 7; that is, 
it checks to be sure no array index is out of bounds. Make the member data in the 
matrix class a 10-by-10 array. A constructor should allow the programmer to 
specify the actual dimensions of the matrix (provided they’re less than 10 by 10). 
The member functions that access data in the matrix will now need two index 
numbers: one for each dimension of the array. Here’s what a fragment of a main() 
program that operates on such a class might look like: 
	matrix m1(3, 4);           // define a matrix object 
	int temp = 12345;          // define an int value 
	m1.putel(7, 4, temp);      // insert value of temp into matrix at 7,4 
	temp = m1.getel(7, 4);     // obtain value from matrix at 7,4
*/
#include<iostream>
using namespace std;

class matrix
{
	private:
		static const int MAX=10;
		int mat[MAX][MAX]={0}, row, column;
	public:
		matrix(int r, int c);
		~matrix(){}
		void putel(int, int, int);
		int getel(int,int)const;
};

int main()
{
	matrix m(2,3),m2(5,10);
	int element;
	//Putting element in the valid range.
	m.putel(0,2,34);
	m.putel(1,1,56);
	
	//putting elements in the valid range.
	m.putel(2,3,77);	//indices start at 0 and end at length-1.
	m.putel(1,4,85);
	m.putel(1,4,85);
	
	//Getting element from the valid range.
	element=m.getel(0,2);
	cout<<"The element at mentioned indices(if indices are valid) is "<<element<<endl;
	element=m.getel(0,0);
	cout<<"The element at mentioned indices(if indices are valid) is "<<element<<endl;
	
	//Getting element from the invalid range.
	element=m.getel(2,3);
	cout<<"The element at mentioned indices(if indices are valid) is "<<element<<endl;
	element=m.getel(0,5);
	cout<<"The element at mentioned indices(if indices are valid) is "<<element<<endl;
	element=m.getel(8,9);
	cout<<"The element at mentioned indices(if indices are valid) is "<<element<<endl;
	
	return 0;
}

matrix::matrix(int r, int c)
{
	if(r>=0&&r<MAX&&c>=0&&c<MAX)
	{
		row=r;
		column=c;
	}
	else
	{
		cout<<"Matrix order is too high for this class.\n";
		cout<<"You tried to create matrix of order "<<r<<'x'<<c<<".\n";
		cout<<"This program (class) can handle matrices of order in the range from 1x1 and 10x10.\n";
		row=-1;
		column=-1;
	}
}

void matrix::putel(int r, int c, int el)
{
	if(r>=0&&r<row&&c>=0&&c<column)
		mat[r][c]=el;
	else
		cout<<"Indices out of bounds. Can't store element in the matrix."<<endl; 
}

int matrix::getel(int r, int c)const
{
	if(r>=0&&r<row&&c>=0&&c<column)
		return mat[r][c];
	cout<<"Indices out of bounds. Returning value 0."<<endl;
	return 0;
}