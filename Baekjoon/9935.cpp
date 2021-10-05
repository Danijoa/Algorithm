#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, b;
	cin >> s >> b;
	int sLen = s.length();
	int bLen = b.length();

	int idx = 0;
	char myStack[1000001];

	for (int i = 0; i < s.length(); i++)
	{
		// 문자열의 문자 하나씩 스택에 저장
		myStack[idx] = s[i];
		
		// 폭탄 문자열이랑 마지막 문자랑 같네
		if (myStack[idx] == b[b.length() - 1])
		{
			// 아직 폭탄 문자열 만큼 스택에 쌓이지도 않았음
			if ((idx + 1) - b.length() < 0)
				continue;

			// 앞에 문자 확인하면서 폭탄 문자열 맞는지 확인
			bool bomb = true;
			for (int j = 1; j < b.length(); j++)
			{
				// 다른 문자 발견
				if (myStack[idx - j] != b[(b.length() - 1) - j])
				{
					bomb = false;
					break;
				}
			}

			// 폭탄 문자 맞으면 인덱스 이동하여 제거
			if (bomb)
				idx -= b.length();
		}

		// 다음 인덱스 부터 추가
		idx++;
	}

	if (idx == 0)
		cout << "FRULA";
	else
	{
		for (int i = 0; i < idx; i++)
		{
			cout << myStack[i];
		}
	}

	return 0;
}
