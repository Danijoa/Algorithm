#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int alpha[26] = { 0, };

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] - 'a' >= 0 && s[i] - 'a' <= 26)
		{
			alpha[s[i] - 'a']++;
		}

		if (s[i] - 'A' >= 0 && s[i] - 'A' <= 26)
		{
			alpha[s[i] - 'A']++;
		}
	}

	int max = 0;
	int index = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max < alpha[i])
		{
			max = alpha[i];
			index = i;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (max == alpha[i])
			cnt++;
	}

	char answer = index + 'A';
	if (cnt == 1)
		cout << answer;
	else
		cout << "?";

	return 0;
}
