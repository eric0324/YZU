#include <iostream>

using namespace std;

int main()
{
   int a, b, c;

   for(int number=100 ; number<=999; number++){

	   a = number/100;
	   b = number%100/10;
	   c = number%10;

	   if(a*a*a+b*b*b+c*c*c == number){
		   cout << number <<"\t";
	   }

   }
   cout << endl;
	system("pause");
}