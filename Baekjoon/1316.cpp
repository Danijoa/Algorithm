#include <iostream>
using namespace std;

int main()
{
	// 입력
	int cycle;
	cin >> cycle;

	string words[100];
	for (int i = 0; i < cycle; i++)
	{
		cin >> words[i];
	}

	// 계산
	int cnt = 0;
	for (int i = 0; i < cycle; i++)
	{
		// 초기화
		bool isGroup = true;

		int alpha[26];
		for (int j = 0; j < 26; j++)
			alpha[j] = 0;

		// 그룹 확인할 단어
		string curWord = words[i];

		// 이전 알파벳
		char preAlpha = -1;
		int preAlphaNum = -1;
		
		// 단어 알파벳 하나씩 
		for (int j = 0; j < curWord.size(); j++)
		{
			// 현재 알파벳
			char curAlpha = curWord.at(j);
			int curAlphaNum = curAlpha - 'a';

			// 저장
			if (j != 0 && curAlphaNum == preAlphaNum)	// 앞에 알파벳과 동일
			{
				alpha[curAlphaNum]++;
				preAlphaNum = curAlphaNum;
			}
			else
			{
				if (alpha[curAlphaNum] != 0) // 앞에 알파벳과 동일하지 않고, 이미 존재했다
				{
					isGroup = false;
					break;
				}
				else // 첫 알파벳 j == 0 인 경우 
				{
					alpha[curAlphaNum]++;
					preAlphaNum = curAlphaNum;
				}
			}

		}

		// 그룹 인 경우
		if (isGroup)
			cnt++;
	}

	// 출력
	cout << cnt;
}
