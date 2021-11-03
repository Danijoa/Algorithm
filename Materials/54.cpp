#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> myS;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			myS.push(s[i]);
		else
		{
      // ')'의 짝이 없는 경우
			if (myS.empty()
				|| myS.top() != '(')
			{
				cout << "NO";
				return 0;
			}
			
			myS.pop();
		}
	}

	if(myS.empty())
		cout << "YES";
	else
		cout << "NO"; // '('가 남아있는 경우

	return 0;
}
