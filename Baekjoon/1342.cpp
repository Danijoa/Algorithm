#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int totalLen;

int alpha[26] = { 0, };
bool selected[11] = { false, };	// 문자 사용했는지 여부 확인(문자열 길이 최대 10)

int curLen = 0;
//string tempS;
vector<char> tempS;	// 문자열 순열

int luckyCnt = 0;	//행운의 문자열 개수 

bool IsLucky()
{
	for (int i = 0; i < totalLen - 1; i++)
	{
		if (tempS[i] == tempS[i + 1])
			return false;
	}
	return true;
}

void DFS(int curLen)
{
	// 문자열 재배치 완료
	if (curLen == totalLen)
	{
		// 행운 문자열 판별
		if (IsLucky() == true)
			luckyCnt++;
		return;
	}

	// 모든 경우의 문자열 만들기
	for (int i = 0; i < totalLen; i++)
	{
		if (selected[i] == true)
			continue;
		selected[i] = true;
		tempS.push_back(s[i]);
		DFS(curLen + 1);
		selected[i] = false;
		tempS.pop_back();
	}
}

int Factorial(int num)
{
	int result = 1;
	for (int i = num; i >= 1; i--)
		result *= i;
	return result;
}

int main()
{
	cin >> s;

	totalLen = s.length();

	for (int i = 0; i < totalLen; i++)
	{
		alpha[s[i] - 'a']++;
	}

	DFS(0);

	for (int i = 0; i < 26; i++)
	{
		// 순열을 조합으로 만들어 주는 과정
		// ex) 현재는 aabbc라는 문자열이 4개 count 되어 있다
		//     이를 1개로 줄이기 위해 a의 조합과 b의 조합과 c의 조합을 나누어 준다
		//     4 / (2! * 2! * 1!) = 1
		if (alpha[i] > 1)	// alpha[i] >= 1
			luckyCnt = luckyCnt / Factorial(alpha[i]);
	}

	cout << luckyCnt;

	return 0;
}
