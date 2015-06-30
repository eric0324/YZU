//元智大學 資訊工程學系 1013353 吳冠賢
//transform an infix expression to postfix and prefix formats. 


#include<iostream>  
#include<string>  
#include<stack> 
#include<queue>
using namespace std;

/*infix -> postfix*/
void inToPost(string mid, int len){

	queue<char> stk; 
	stack<char> cal; 

	for (int i = 0; i <= len - 1; i++){
		char tmp;
		tmp = mid[i];
		if (tmp == '+' || tmp == '-'){
			if (cal.empty()) {
				cal.push(tmp);
			}
			else if (cal.top() == '+' || cal.top() == '-' || cal.top() == '*' || cal.top() == '/') {
				do {
					stk.push(cal.top());
					cal.pop();
				} while (!cal.empty() && (cal.top() == '+' || cal.top() == '-' || cal.top() == '*' || cal.top() == '/'));
				// pop to the queue
				cal.push(tmp);
			}
			else {
				cal.push(tmp);
			}
		}
		else if (tmp == '*' || tmp == '/'){
			if (cal.empty()) {
				cal.push(tmp);
			}
			else if (cal.top() == '*' || cal.top() == '/') {
				while (!cal.empty() && (cal.top() == '*' || cal.top() == '/')){
					stk.push(cal.top());
					cal.pop();
				};
				cal.push(tmp);
			}
			else {
				cal.push(tmp);
			}
		}else if (tmp == ')'){
			while (cal.top() != '('){
				stk.push(cal.top());
				cal.pop();
			}
			cal.pop();
		}
		else if (tmp == '(')
			cal.push(tmp);
		else
			stk.push(tmp);
	}

	while (!cal.empty()){
		stk.push(cal.top());
		cal.pop();
	}

	//最後再把他輸出

	cout << "prefix expression : ";

	while (!stk.empty()){
		cout << stk.front();
		stk.pop();
	}

	cout << '\n';

}

/*infix -> prefix*/
void inToPre(string mid,int len){

	stack<char> stk; //stk堆疊用來放數字
	stack<char> cal; //cal堆疊用來放運算符號	

	for (int i = len - 1; i >= 0; i--){
		char tmp;
		tmp = mid[i];
		if (tmp == '+' || tmp == '-'){
			if (!cal.empty() && cal.top() != ')'){
				while ((cal.top() == '*') || (cal.top() == '/')){
					stk.push(cal.top());
					cal.pop();
					if (cal.empty())
						break;
				}
			}
			cal.push(tmp);
		}
		else if (tmp == '*' || tmp == '/')
			cal.push(tmp);
		else if (tmp == '('){
			while (cal.top() != ')'){
				stk.push(cal.top());
				cal.pop();
			}
			cal.pop();
		}
		else if (tmp == ')')
			cal.push(tmp);
		else
			stk.push(tmp);
	}

	//要滿足優先順序，當 +，- 號遇到 *，/ 時，要把 *，/ 號推到stack 的 top
	while (!cal.empty()){
		stk.push(cal.top());
		cal.pop();
	}

	//最後再把他輸出

	cout << "prefix expression : ";

	while (!stk.empty()){
		cout << stk.top();
		stk.pop();
	}

	cout << '\n';

}

int main()
{
	string mid;

	cout << "Enter an infix expression : ";
	cin >> mid;

	int len = mid.length();

	//postfix expression
	inToPost(mid, len);

	//prefix expression 
	inToPre(mid, len);

	system("pause");
}