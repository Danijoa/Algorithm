#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 2~9
int num;	
char k[10];
// 0~9
bool visited[10] = { false, };
// 부등호 배열에 알맞는 숫자들 오름차순으로 저장
vector<string> answer;

// 현재 숫자, 현재 위치의 부등호, 현재 완성된 숫자
void DFS(int curNum, int pos, string ans)
{
	if (pos == num)
	{
		answer.push_back(ans);
		return;
	}
	
	// 부등호에 맞는 다음 숫자 탐색하기
	for (int i = 0; i <= 9; i++)
	{
		int nextNum = i;

		if (visited[nextNum] == true)
			continue;

		if (visited[nextNum] == false)
		{
			// 부등호에 안맞는 경우
			if (k[pos] == '<')
			{
				if (curNum >= nextNum)
					continue;
			}
			else
			{
				if (curNum <= nextNum)
					continue;
			}

			// 부등호에 맞는 경우
			visited[nextNum] = true;
			DFS(nextNum, pos + 1, ans + to_string(nextNum));
			// 백트래킹
			visited[nextNum] = false;
		}
	}
}

int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> k[i];

	// 대입 비교 시작 숫자 정해주기
	for (int i = 0; i <= 9; i++)
	{
		visited[i] = true;
		DFS(i, 0, to_string(i));
		// 백트래킹
		visited[i] = false;
	}

	cout << answer[answer.size() - 1] << "\n";
	cout << answer[0] << "\n";
}
