#include <iostream>
 
using namespace std;

int main()
{
	double number1, number2, total=1;
	cout << "Enter a positive Integer: ";
	cin >> number1;
	number2 = number1;
	for( ; number1 ; number1--)
	{
		total *= number1;
		
	}
	cout << number2 <<"! is " << total << endl ;
	system("pause");
}