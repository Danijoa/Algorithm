#include <iostream>

using namespace std;

int v, e;
int g[21][21] = { 0 };
int cnt = 0;
bool visited[21] = { false, };

void DFS(int cur)
{
	// 정점 v도달
	if (cur == v)
	{
		cnt += 1;
		return;
	}

	for (int i = 1; i <= v; i++)
	{
		// cur노드와 연결되어 있고, 방문하지 않았으면
		if (g[cur][i] == 1 && visited[i] == false)
		{
			visited[i] = true;
			DFS(i);
			visited[i] = false;
		}
	}
}

int main() 
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int s, t;
		cin >> s >> t;
		g[s][t] = 1;
	}

	// 시작은 노드 1
	visited[1] = true;
	DFS(1);

	cout << cnt;
	
	return 0;
}
