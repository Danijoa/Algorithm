#include <iostream>
#include <stack>
using namespace std;

int priority(char a) //연산자 우선순위 비교
{
	switch (a) {
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
	case ')':
		return 0;
	}
    return -1;
}

int main()
{
	string str;
	cin >> str;
	int len = str.length();

	stack<char> myS;
	string result;

	for (int i = 0; i < len; i++)
	{
		int temp = priority(str.at(i));
		char cur = str.at(i);
		
		switch (cur) {
		case '*':
		case '/':
		case '+':
		case '-':
			while (!myS.empty() && priority(myS.top()) >= temp) //(비교)스택 가장 위에 있는 연산자 >= 현재 연산자의 우선순위 우선순위 
			{
				result += myS.top();
				myS.pop(); //같은 괄호 속 앞에 우선순위가 같거나 높은 연산자가 있는 경우
			}
			myS.push(cur);
			break;
		case '(':
			myS.push(cur);
			break;
		case ')':
			while (!myS.empty() && myS.top() != '(') //'('와 ')' 사이의 연산자 뒤에서 부터 출력
			{
				result += myS.top();
				myS.pop();
			}
			myS.pop(); //'(' 삭제
			break;
		default: //피연산자는 순서대로 출력 
			result += cur;
		}
	}

	while (!myS.empty()) //스택에 남아있는 값 출력
	{
		result += myS.top();
		myS.pop();
	}

	cout << result;
}
