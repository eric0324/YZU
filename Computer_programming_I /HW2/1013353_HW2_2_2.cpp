#include <iostream>
 
using namespace std;
 
int main()
{
    int counter, number;
    int largest = 0;
    
	cout << "Enter the first number: ";
	cin >> number;
	counter = 1;
	while(counter < 10)
	{
		if(number > largest)
			largest = number;
		counter ++;
		cout << "Enter the next number : ";
		cin >> number;
    }
	cout << "Largest number is " << largest << endl;
	system("pause");
   
}