// ---------------------------------- //
// 1013353 元智大學資訊工程學系2C 吳冠賢          
// ---------------------------------- //

#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double power(double base, double exponent);

double power(double base, double exponent){

	if(exponent == 1)
		return 1;
	else
		return base*pow( base, exponent-1);
}

int main(){

	double base, exponent;

	cout << "Enter the base : " ;
	cin >> base;
	cout << "Enter the exponent : ";
	cin >> exponent;

	cout << power(base, exponent);

	system("pause");
}