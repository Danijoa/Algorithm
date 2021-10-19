#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int index;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'H')
		{
			index = i;
			break;
		}
	}

	string c = s.substr(1, index - 1);
	string h = s.substr(index + 1, s.size() - 1 - index);

	int cNum = 0;
	for (int i = 0; i < c.size(); i++)
	{
		cNum += (c[(c.size() - 1) - i] - '0') * pow(10, i);
	}
	
	if (cNum == 0)
		cNum = 1;

	int hNum = 0;
	for (int i = 0; i < h.size(); i++)
	{
		hNum += (h[(h.size() - 1) - i] - '0') * pow(10, i);
	}

	if (hNum == 0)
		hNum = 1;

	cout << cNum * 12 + hNum * 1;

	return 0;
}
