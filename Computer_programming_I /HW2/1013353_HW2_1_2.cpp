#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    
    double sales;
    double salary;

    cout<<"Enter sales in dollars (-1 to end): ";
    cin>>sales;
    while(sales != -1)
	{
        
        salary = 200 + 0.09 * sales;

        cout << "Salary is: $"<<setprecision(2) << fixed << salary << endl;
	cout << "Enter sales in dollars (-1 to end): ";
        cin >> sales;
	}
    system("pause");
}