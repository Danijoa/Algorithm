#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	int num = 0;

	int len;
	if (!s.empty())
	{
		if (s.front() == ' ')
			s.erase(0, 1);

		len = s.length();

		for (int i = 0; i < len; i++)
		{
			if (s[i] == ' ')
				num++;
		}

		if (len != 0 && s[len - 1] != ' ')
			num++;
	}


	//cout << s << endl;
	cout << num;
	

	return 0;
}
