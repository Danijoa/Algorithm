#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	map<string, bool> myM;

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		myM[s] = true;
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (myM[s] == true)
			cnt++;
	}

	cout << cnt;

	return 0;
}
