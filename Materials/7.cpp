#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	getline(cin, s);	// <string>에 정의되어있는 함수

	vector<char> myV;
	int cha = 'a' - 'A';
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				myV.push_back(s[i] + cha);
			}
			else
				myV.push_back(s[i]);
		}
	}

	for (int i = 0; i < myV.size(); i++)
	{
		cout << myV[i];
	}
}
