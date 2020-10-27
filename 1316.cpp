#include <iostream>
using namespace std;

int main()
{
	int result = 0;

	int cycle;
	cin >> cycle;

	string words[100];
	for (int i = 0; i < cycle; i++)
	{
		cin >> words[i];
	}

	int k = 0;
	while (true)
	{
		if (k == cycle)
		{
			break;
		}
		string word = words[k];

		int alpha[26];
		for (int i = 0; i < 26; i++)
		{
			alpha[i] = 0;
		}
		int cur_alphaIndex = -1;
		int pre_alphaIndex = -1;
		char curAlpha;
		bool check = true;
		for (int i = 0; i < word.size(); i++)
		{
			curAlpha = word[i];
			cur_alphaIndex = curAlpha - 'a';
			if (i != 0 && cur_alphaIndex == pre_alphaIndex)
			{
				alpha[cur_alphaIndex]++;
				pre_alphaIndex = cur_alphaIndex;
			}
			else
			{
				if (alpha[cur_alphaIndex] != 0)
				{
					check = false;
					break;
				}
				else
				{
					alpha[cur_alphaIndex]++;
					pre_alphaIndex = cur_alphaIndex;
				}
			}
		}

		if (!check)
		{
			//cout << "그룹 단어가 아니다\n";
		}
		else
		{
			//cout << "그룹 단어이다\n";
			result++;
		}

		k++;
	}

	cout << result;
}
