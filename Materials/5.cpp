#include <iostream>
#include <string>

using namespace std;

int main()
{
	string jumin;
	cin >> jumin;

	int birth = (jumin[0] - '0') * 10 + (jumin[1] - '0');
	char sex = 'W';
	for (int i = 0; i < jumin.size(); i++)
	{
		if (jumin[i] == '-')
		{
			if (jumin[i + 1] == '1')
			{
				birth += 1900;
				sex = 'M';
			}
			else if (jumin[i + 1] == '3')
			{
				birth += 2000;
				sex = 'M';
			}
			else if (jumin[i + 1] == '2')
			{
				birth += 1900;
			}
			else
			{
				birth += 2000;
			}
			break;
		}
	}

	cout << 2019 - birth + 1 << " " << sex;
}
