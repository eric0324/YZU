#include <iostream>
 
using namespace std;

int main()
{
	int num; 

	cout << "Enter a positive integer in the range:";
	cin >> num;

	for(int k=1 ; k <= num ; k++){ //kノㄓ北ㄏノ块跑计
	for (int i=1 ; i <= num-k ; i++ ){ //i北space计ヘ
		cout << " ";
	}
	for (int j=1 ; j <= k ; j++ ){ //ノㄓ北star计ヘ
		cout << "*";
	}
	cout << endl;
	}
	cout << endl;
	system("pause");
}