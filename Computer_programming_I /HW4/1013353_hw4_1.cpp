#include<iostream>
using namespace std;

bool isprime(unsigned int i){	//一個判斷數字是不是質數的function
	for(int k = 2 ; k < i ; k++){
		if( i % k == 0 )
			return false;
	}
		return true;
}
int main()
{
	int num;
	int counter = 0;//計數用

	cout<< "Enter a positive integer: ";
	cin>> num;

	//這個for loop是討論"有幾個"質因數
	for( int i = 2; i <= num; i++ ) //i從2開始給他一直檢查
		if( isprime(i)  && num % i == 0) { //如果這i是質數,又可以給他整除,他就是質因數
			counter++;
			}

	cout<< num<< " has "<< counter << " prime factors: ";

	//這個for loop是討論"有那些"質因數
	for(int i=2; i<=num ; i++){
		if(isprime(i) && num %i==0){
			cout << i << ", "; //最後一個頓號消不掉.....
		}
	}

	cout << "\n";//純粹換行美觀好看,沒有意義

	system("pause");
}