#include<iostream>

using namespace std;


int main(){

	int number;
	cin >> number; //five-digit integer
	
	cout << number/10000<< "   " << number/1000%10 << "   " << number/100%10 << "   "  << number/10%10 << "   "  << number%10 << endl;

	system("pause");
}