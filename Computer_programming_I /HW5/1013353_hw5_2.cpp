// ---------------------------------- //
// 1013353 元智大學資訊工程學系2C 吳冠賢          
// ---------------------------------- //

#include <iostream> 
using namespace std; 

int gcd(int x, int y); 

int gcd(int x, int y) { 
    if(y == 0) 
        return x; 
    else 
        return gcd(y, x % y); 
}

int main() { 
    int x=0, y=0; 

    cout << "Enter x："; 
    cin >> x ;
	cout << "Enter y："; 
    cin >> y ;

    cout << "GCD: " << gcd(x, y) << endl; 

    system("pause");
} 

