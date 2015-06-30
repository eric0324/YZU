#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, number;
	cout << "Enter a positive integer of at most 8 digits: " ;
	cin >> number;
	a = number/10000;
	b = number/1000%10;
	c = number/100%10;
	d = number/10%10;
	e = number%10;
	
	cout << "The sum of all digits of" << number << " is " << a+b+c+d+e <<endl;

	system("pause");
}