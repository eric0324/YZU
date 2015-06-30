#include <iostream>
#include <iomanip>
using namespace::std;
#include <ctime>

int recursiveMaximum(const int data[], int last );

// function main begins program execution
int main()
{
   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand( seed );

   const int arraySize = 100;
   int data[ arraySize ];

   int number;
   cout << "Enter a positive integer : ";
   cin >> number;

   for( int i = 0; i < number; i++ )
      data[i] = 1 + rand() % 100;

   cout << "\nArray members are:";
   for( int i = 0; i < number; i++ )
      cout << setw(4) << data[i];

	cout << "\n\nLargest element is: "
        << recursiveMaximum( data, number - 1 ) << endl << endl;

	system( "pause" );
} // end function main

// function to recursively find maximum array element
int recursiveMaximum(const int data[], int last )
{	
	if (last > 1) {//Added

		int temp = recursiveMaximum(data, last - 1);//Added

		if (temp < data[last + 1])//Added
			return data[last + 1];//Added
		else//Added
			return temp;//Added
	}else {//Added
		if (data[last] < data[0])//Added
			return data[0];//Added
		else//Added
			return data[last];//Added
	}//Added
}