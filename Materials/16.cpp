#include <iostream>

using namespace std;

string f, s;
int fA['z' - 'A' + 1] = { 0, };
int sA['z' - 'A' + 1] = { 0, };
int len;	// 길이 같음
string ans;

int main()
{
	cin >> f >> s;
	len = f.size();

	for (int i = 0; i < len; i++)
	{
		fA[f[i] - 'A']++;
		sA[s[i] - 'A']++;
	}

	ans = "YES";
	for (int i = 0; i < (int)('z' - 'A' + 1); i++)
	{
		if (fA[i] != sA[i])
		{
			ans = "NO";
			break;
		}
	}

	cout << ans;
}
