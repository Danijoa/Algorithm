#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n; // 홀수개의 구슬
int m; // n = m + 1 + m 
int c; // 비교 횟수
int h, l; // h < l 무게

vector<int> hGu[100], lGu[100];
bool hVisit[100] = { false, }, lVisit[100] = { false, };

int hDFS(int cur)
{
	int result = 1;

	for (int i = 0; i < hGu[cur].size(); i++)
	{
		int next = hGu[cur][i];
		if (hVisit[next] == true)
			continue;

		hVisit[next] = true;
		result += hDFS(next);
	}

	return result;
}

int lDFS(int cur)
{
	int result = 1;

	for (int i = 0; i < lGu[cur].size(); i++)
	{
		int next = lGu[cur][i];
		if (lVisit[next] == true)
			continue;

		lVisit[next] = true;
		result += lDFS(next);
	}

	return result;
}

int main()
{
	cin >> n >> c;
	m = (n - 1) / 2;
	for (int i = 0; i < c; i++)
	{
		cin >> h >> l;
		hGu[h].push_back(l);
		lGu[l].push_back(h);
	}

	// 구슬간 무거운 쪽으로 뻗어가는 방향 그래프와
	// 구슬간 가벼운 쪽으로 뻗어가는 방향 그래프를
	// 모든 구슬을 시작점으로 DFS를 돈다. 
	// 이때, 각 구슬의 작은 구슬 개수 또는 무거운 구슬 개수가
	// 나 포함하지 않고 m+1개 이상 이면 확실하면 중간 구슬이 아니다
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(hVisit, false, sizeof(hVisit));
		memset(lVisit, false, sizeof(lVisit));

		hVisit[i] = true;
		lVisit[i] = true;

		if ((hDFS(i) > m + 1)
			|| (lDFS(i) > m + 1))
		{
			result++;
		}
	}

	cout << result;
}
