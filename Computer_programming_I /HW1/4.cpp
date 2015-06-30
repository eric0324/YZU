#include<iostream>

using namespace std;


int main(){

	int integer;

	cout << "integer\tsquare\tcube\t\n";
	for (integer = 0 ; integer < 11 ; integer++ ){  
	cout << integer << "\t" << integer*integer << "\t" << integer*integer*integer << endl ;
	} 

	system("pause");
}