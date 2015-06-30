#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "Enter a positive integer in the range 1 to 500: ";
	cin >> number;

	cout << "side1\tside2\tside3\t" << endl;

    for(int hypotenuse = 1; hypotenuse <= number ; hypotenuse++)
		for(int side2 = 1; side2 <= number ; side2++)
			for(int side1 = side2; side1 <= number ; side1++)
				if(hypotenuse*hypotenuse == side2*side2+side1*side1)
					cout << side2 << "\t" << side1 << "\t" << hypotenuse << "\t" << endl;
	system("pause");
}