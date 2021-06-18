#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<vector<int>> myV;
//vector<int> myV[1001];
bool visited[1001] = { false, };

void DFS(int num)
{
	visited[num] = true;

	for (int i = 0; i < myV[num].size(); i++)
	{
		int temp = myV[num][i];
		if (visited[temp] == false)
			DFS(temp);
	}
}

int main()
{
	cin >> v >> e;

	myV.resize(1001);
	int a, b;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		myV[a].push_back(b);
		myV[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= v; i++)
	{
		if (visited[i] == false)
		{
			cnt++;
			DFS(i);
		}
	}

	cout << cnt;

	return 0;
}
