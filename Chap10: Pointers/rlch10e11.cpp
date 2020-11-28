/*
--PROGRAM NAME: rlch10e11.cpp
--PROGRAM STATEMENT: Create a class that allows you to treat the 10 
separate arrays in Exercise 10 as a single one-dimensional array, using array 
notation with a single index. That is, statements in main() can access their 
elements using expressions like a[j], even though the class member functions 
must access the data using the two-step approach. Overload the subscript operator 
[] (see Chapter 9, “Inheritance”) to achieve this result. Fill the arrays with 
test data and then display it. Although array notation is used in the class 
interface in main() to access “array” elements, you should use only pointer 
notation for all the operations in the implementation (within the class member 
functions).
*/
#include<iostream>
#include<iomanip>  //setw(),setfill()
using namespace std;
//----------------------------------------------------------------
class fragarray  //Like fragments of array.
{
	private:
		static const int MAX=10;
		int* arr[MAX]={NULL};
	public:
		fragarray(){}  //Default consttuctor
		~fragarray();  //Destructor
		int& operator[](int);
};
//----------------------------------------------------------------
//-----------------------START OF MAIN()------------------------------------
int main(void)
{
	cout<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Top line of O/p screen.
	
	fragarray farr;
	int a=0;
	
	//Filling array
	for(int i=0;i<100;i++,a+=10)
		farr[i]=a;
	
	//Displaying array
	for(int i=0;i<100;i++)
	{
		if(i%10==0)  //Go to next line after printing 10 elements(a fragment of array.)
			cout<<endl<<"Fragment"<<setw(3)<<i/10+1<<": ";
		cout<<setw(4)<<farr[i];
	}
	cout<<endl<<setw(75)<<setfill('+')<<""<<setfill(' ')<<endl;  //Bottom line of O/p screen.
	return 0;
}
//-----------------------END OF MAIN()-----------------------------------------
int& fragarray::operator [](int index)
{
	if(arr[index/MAX]==NULL)  //If memory not allocated at the index
		arr[index/MAX]=new int[MAX];  //allocate memory. NOTE1
	return *(*(arr+index/MAX)+index%MAX);  //return by reference
}
//----------------------------------------------------------------
fragarray::~fragarray()
{
  for(int i=0;i<MAX;i++)  //Releasing memory
  	if(arr[i]!=NULL)
  		delete[] arr[i];  //NOTE2
}
//----------------------------------------------------------------

/*
--NOTE1: The array allocated here has indeterminate values, but it can be zero-
initialized by just adding an empty parentheses(), like this: new int[MAX](). More
generally, for arbitrary item type, this performs a value-initialization.
--NOTE2: Deleting the memory doesn't delete the pointer that points to it, and
doesn't change the address value in the pointer.
*/