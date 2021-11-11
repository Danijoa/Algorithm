#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<int> g[21];
int cnt = 0;
bool visited[21] = { false, };

void DFS(int cur)
{
	if (cur == v)
	{
		cnt += 1;
		return;
	}

	for (int i = 0; i < g[cur].size(); i++)
	{
		int next = g[cur][i];
		if (visited[next] == false)
		{
			visited[next] = true;
			DFS(next);
			visited[next] = false;
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
		g[s].push_back(t);
	}

	visited[1] = true;
	DFS(1);

	cout << cnt;
	
	return 0;
}
