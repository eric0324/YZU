#include<iostream>

using namespace std;

int main(){

	int num1, num2, num3;

	cout << "Input three different integers: " ;
	cin >> num1 >> num2 >> num3;

	cout << "Sum is " << num1 + num2 + num3 << endl; //Calculate Sum
	cout << "Average is " << (num1 + num2 + num3)/3 << endl; //Calculate Average
	cout << "Product is " << num1 * num2 * num3 << endl; //Calculate Product
	

	if(num1 < num2){ 
		if(num3 < num1){
			cout << "Smallest is " << num3 << endl;
		}else{
			cout << "Smallest is " << num1 << endl;
		}
	}else{
		if(num3 < num2){
			cout << "Smallest is " << num3 << endl;
		}else{
			cout << "Smallest is " << num2 << endl;
		}
	}//Calculate Smallest

	if(num1 > num2){ 
		if(num3 > num1){
			cout << "Largest is " << num3 << endl;
		}else{
			cout << "Largest is " << num1 << endl;
		}
	}else{
		if(num3 > num2){
			cout << "Largest is " << num3 << endl;
		}else{
			cout << "Largest is " << num2 << endl;
		}
	}//Calculate Largest

	system("pause");
}