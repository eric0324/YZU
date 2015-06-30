#include <iostream>
 
using namespace std;
 
int main()
{
    int counter, number;
    int largest = 0;
    
	cout << "Enter the first number: ";
	cin >> number;

	for( counter = 1 ; counter < 10 ; counter++)
	{
		if(number > largest)
		largest = number;
		cout << "Enter the next number : ";
		cin >> number;

	}
 
 
	cout << "Largest number is " << largest << endl;
 
   
    system("pause");
   
}