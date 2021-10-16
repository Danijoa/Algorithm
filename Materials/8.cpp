#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int l = 0, r = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			l++;
		if (s[i] == ')')
			r++;
	}
	if (l == r)
	{
		if(s[0] == ')' || s[s.size() - 1] == '(')
			cout << "NO";
		else
			cout << "YES";
	}
	else
		cout << "NO";
}
